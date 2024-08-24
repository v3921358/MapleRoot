package tools.mapletools;

import provider.wz.WZFiles;
import tools.Pair;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;

/**
 * @author RonanLana
 * <p>
 * This application parses the cosmetic recipes defined within "lib/care" folder, loads
 * every present cosmetic itemid from the XML data, then checks the scripts for missed
 * cosmetics within the stylist/surgeon. Results from the search are reported in a report
 * file.
 * <p>
 * Note: to best make use of this feature, set IGNORE_CURRENT_SCRIPT_COSMETICS = true. This
 * way, every available cosmetic present on the recipes will be listed on the report.
 * <p>
 * Estimated parse time: 1 minute
 */
public class CashCosmeticsChecker {
    private static final String INPUT_DIRECTORY_PATH = ToolConstants.getInputFile("care").toString();
    private static final Path OUTPUT_FILE = ToolConstants.getOutputFile("cash_cosmetics_result.txt");
    private static final boolean IGNORE_CURRENT_SCRIPT_COSMETICS = false; // Toggle to preference
    private static final int INITIAL_STRING_LENGTH = 50;

    private static final Map<Integer, Set<Integer>> scriptCosmetics = new HashMap<>();
    private static final Map<Integer, String> scriptEntries = new HashMap<>(500);
    private static final Set<Integer> allCosmetics = new HashSet<>();
    private static final Set<Integer> unusedCosmetics = new HashSet<>();
    private static final Map<Integer, List<Integer>> usedCosmetics = new HashMap<>();
    private static final Map<Integer, String> couponNames = new HashMap<>();
    private static final Map<Integer, Integer> cosmeticNpcs = new HashMap<>(); // expected only 1 NPC per cosmetic coupon (town care/salon)
    private static final Map<List<String>, Integer> cosmeticNpcids = new HashMap<>();
    private static final Set<String> missingCosmeticNames = new HashSet<>();
    private static final Map<String, Integer> cosmeticNameIds = new HashMap<>();
    private static final Map<Integer, String> cosmeticIdNames = new HashMap<>();
    private static final Map<Pair<Integer, String>, Set<Integer>> missingCosmeticsNpcTypes = new HashMap<>();

    private static PrintWriter printWriter = null;
    private static InputStreamReader fileReader = null;
    private static BufferedReader bufferedReader = null;
    private static byte status = 0;

    private static String getName(String token) {
        int i, j;
        char[] dest;
        String d;

        i = token.lastIndexOf("name");
        i = token.indexOf("\"", i) + 1; //lower bound of the string
        j = token.indexOf("\"", i);     //upper bound

        dest = new char[INITIAL_STRING_LENGTH];
        token.getChars(i, j, dest, 0);

        d = new String(dest);
        return (d.trim());
    }

    private static String getValue(String token) {
        int i, j;
        char[] dest;
        String d;

        i = token.lastIndexOf("value");
        i = token.indexOf("\"", i) + 1; //lower bound of the string
        j = token.indexOf("\"", i);     //upper bound

        dest = new char[INITIAL_STRING_LENGTH];
        token.getChars(i, j, dest, 0);

        d = new String(dest);
        return (d.trim());
    }

    private static void forwardCursor(int st) {
        String line = null;

        try {
            while (status >= st && (line = bufferedReader.readLine()) != null) {
                simpleToken(line);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void simpleToken(String token) {
        if (token.contains("/imgdir")) {
            status -= 1;
        } else if (token.contains("imgdir")) {
            status += 1;
        }
    }

    private static void translateToken(String token) {
        if (token.contains("/imgdir")) {
            status -= 1;
        } else if (token.contains("imgdir")) {
            status += 1;

            if (status == 3) {
                String d = getName(token);

                if (!(d.contentEquals("Face") || d.contentEquals("Hair"))) {
                    forwardCursor(status);
                }
            } else if (status == 4) {
                String d = getName(token);
                int itemid = Integer.parseInt(d);

                int cosmeticid;
                if (itemid >= 30000) {
                    cosmeticid = (itemid / 10) * 10;
                } else {
                    cosmeticid = itemid - ((itemid / 100) % 10) * 100;
                }

                allCosmetics.add(cosmeticid);
                forwardCursor(status);
            }
        }
    }

    private static void readEqpStringData(String eqpStringDirectory) throws IOException {
        String line;

        fileReader = new InputStreamReader(new FileInputStream(eqpStringDirectory), StandardCharsets.UTF_8);
        bufferedReader = new BufferedReader(fileReader);

        while ((line = bufferedReader.readLine()) != null) {
            translateToken(line);
        }

        bufferedReader.close();
        fileReader.close();
    }

    private static void loadCosmeticWzData() throws IOException {
        System.out.println("Reading String.wz ...");
        readEqpStringData(WZFiles.STRING.getFilePath() + "/Eqp.img.xml");
    }

    private static void setCosmeticUsage(List<Integer> usedByNpcids, int cosmeticid) {
        if (!usedByNpcids.isEmpty()) {
            usedCosmetics.put(cosmeticid, usedByNpcids);
        } else {
            unusedCosmetics.add(cosmeticid);
        }
    }

    private static void listFiles(String directoryName, ArrayList<File> files) {
        File directory = new File(directoryName);

        // get all the files from a directory
        File[] fList = directory.listFiles();
        for (File file : fList) {
            if (file.isFile()) {
                files.add(file);
            } else if (file.isDirectory()) {
                listFiles(file.getAbsolutePath(), files);
            }
        }
    }

    private static int getNpcIdFromFilename(String name) {
        try {
            return Integer.parseInt(name.substring(0, name.indexOf('.')));
        } catch (Exception e) {
            return -1;
        }
    }

    private static List<Integer> findCosmeticDataNpcids(int itemid) {
        List<Integer> npcids = new LinkedList<>();
        for (Map.Entry<Integer, Set<Integer>> sc : scriptCosmetics.entrySet()) {
            if (sc.getValue().contains(itemid)) {
                npcids.add(itemid);
            }
        }

        return npcids;
    }

    private static void loadScripts() throws IOException {
        ArrayList<File> files = new ArrayList<>();
        listFiles(ToolConstants.SCRIPTS_PATH + "/npc", files);

        for (File f : files) {
            Integer npcid = getNpcIdFromFilename(f.getName());

            //System.out.println("Parsing " + f.getAbsolutePath());
            fileReader = new InputStreamReader(new FileInputStream(f), StandardCharsets.UTF_8);
            bufferedReader = new BufferedReader(fileReader);

            String line;

            StringBuilder stringBuffer = new StringBuilder();

            boolean cosmeticNpc = false;
            Set<Integer> cosmeticids = new HashSet<>();
            while ((line = bufferedReader.readLine()) != null) {
                String[] s = line.split("hair_. = Array\\(", 2);

                if (s.length > 1) {
                    cosmeticNpc = true;
                    s = s[1].split("\\)", 2);
                    s = s[0].split(", ");

                    for (String st : s) {
                        if (!st.isEmpty()) {
                            int itemid = Integer.parseInt(st);
                            cosmeticids.add(itemid);
                        }
                    }
                } else {
                    s = line.split("face_. = Array\\(", 2);

                    if (s.length > 1) {
                        cosmeticNpc = true;
                        s = s[1].split("\\)", 2);
                        s = s[0].split(", ");

                        for (String st : s) {
                            if (!st.isEmpty()) {
                                int itemid = Integer.parseInt(st);
                                cosmeticids.add(itemid);
                            }
                        }
                    }
                }

                stringBuffer.append(line).append("\n");
            }

            scriptEntries.put(npcid, stringBuffer.toString());

            if (cosmeticNpc) {
                scriptCosmetics.put(npcid, cosmeticids);
            }

            bufferedReader.close();
            fileReader.close();
        }
    }

    private static void processCosmeticScriptData() throws IOException {
        System.out.println("Reading script files ...");
        loadScripts();

        if (IGNORE_CURRENT_SCRIPT_COSMETICS) {
            for (Set<Integer> npcCosmetics : scriptCosmetics.values()) {
                npcCosmetics.clear();
            }
        }

        for (Integer itemid : allCosmetics) {
            List<Integer> npcids = findCosmeticDataNpcids(itemid);
            setCosmeticUsage(npcids, itemid);
        }
    }

    private static List<Integer> loadCosmeticCouponids() throws IOException {
        List<Integer> couponItemids = new LinkedList<>();

        fileReader = new InputStreamReader(new FileInputStream(getHandbookFileName("/Cash.txt")), StandardCharsets.UTF_8);
        bufferedReader = new BufferedReader(fileReader);

        String line;
        while ((line = bufferedReader.readLine()) != null) {
            if (line.isEmpty()) {
                continue;
            }
            String[] s = line.split(" - ", 3);

            int itemid = Integer.parseInt(s[0]);
            if (itemid >= 5150000 && itemid < 5160000) {
                couponItemids.add(itemid);
                couponNames.put(itemid, s[1]);
            }
        }

        bufferedReader.close();
        fileReader.close();

        return couponItemids;
    }

    private static List<Integer> findItemidOnScript(int itemid) {
        List<Integer> files = new LinkedList<>();
        String t = String.valueOf(itemid);

        for (Map.Entry<Integer, String> text : scriptEntries.entrySet()) {
            if (text.getValue().contains(t)) {
                files.add(text.getKey());
            }
        }

        return files;
    }

    private static void loadCosmeticCouponNpcs() throws IOException {
        System.out.println("Locating cosmetic NPCs ...");

        for (Integer itemid : loadCosmeticCouponids()) {
            List<Integer> npcids = findItemidOnScript(itemid);

            if (!npcids.isEmpty()) {
                cosmeticNpcs.put(itemid, npcids.get(0));
            }
        }
    }

    private enum CosmeticType {
        HAIRSTYLE,
        HAIRCOLOR,
        DIRTYHAIR,
        FACE_SURGERY,
        EYE_COLOR,
        SKIN_CARE
    }

    private static Pair<Integer, CosmeticType> parseCosmeticCoupon(String[] tokens) {
        for (int i = 0; i < tokens.length; i++) {
            String s = tokens[i];

            if (s.startsWith("Hair")) {
                if (s.contentEquals("Hairstyle")) {
                    return new Pair<>(i, CosmeticType.HAIRSTYLE);
                } else {
                    if (i - 1 >= 0 && tokens[i - 1].contentEquals("Dirty")) {
                        return new Pair<>(i - 1, CosmeticType.DIRTYHAIR);
                    } else if (i + 1 < tokens.length && tokens[i + 1].contentEquals("Color")) {
                        return new Pair<>(i, CosmeticType.HAIRCOLOR);
                    } else {
                        return new Pair<>(i, CosmeticType.HAIRSTYLE);
                    }
                }
            } else if (s.startsWith("Face")) {
                return new Pair<>(i, CosmeticType.FACE_SURGERY);
            } else if (s.startsWith("Cosmetic")) {
                return new Pair<>(i, CosmeticType.EYE_COLOR);
            } else if (s.startsWith("Plastic")) {
                return new Pair<>(i, CosmeticType.FACE_SURGERY);
            } else if (s.startsWith("Skin")) {
                return new Pair<>(i, CosmeticType.SKIN_CARE);
            }
        }

        return null;
    }

    private static List<String> getCosmeticCouponData(String town, String type, String subtype) {
        List<String> ret = new ArrayList<>(3);
        ret.add(town);
        ret.add(type);
        ret.add(subtype);
        return ret;
    }

    private static List<String> parseCosmeticCoupon(String couponName) {
        String town, type, subtype = "EXP";

        String[] s = couponName.split(" Coupon ", 2);

        if (s.length > 1) {
            subtype = s[1].substring(1, s[1].length() - 1);
        }

        String[] tokens = s[0].split(" ");
        Pair<Integer, CosmeticType> cosmeticData = parseCosmeticCoupon(tokens);
        if (cosmeticData == null) {
            return null;
        }

        town = "";
        for (int i = 0; i < cosmeticData.left; i++) {
            town += (tokens[i] + "_");
        }
        town = town.substring(0, town.length() - 1).toLowerCase();

        switch (cosmeticData.right) {
            case HAIRSTYLE:
                type = "hair";
                break;

            case FACE_SURGERY:
                type = "face";
                break;

            default:
                return null;
        }

        return getCosmeticCouponData(town, type, subtype);
    }

    private static void generateCosmeticPlaceNpcs() {
        for (Map.Entry<Integer, String> e : couponNames.entrySet()) {
            Integer npcid = cosmeticNpcs.get(e.getKey());
            if (npcid == null) {
                continue;
            }

            String couponName = e.getValue();
            List<String> couponData = parseCosmeticCoupon(couponName);

            if (couponData == null) {
                continue;
            }
            cosmeticNpcids.put(couponData, npcid);
        }
    }

    private static Integer getCosmeticNpcid(String townName, String typeCosmetic, String typeCoupon) {
        return cosmeticNpcids.get(getCosmeticCouponData(townName, typeCosmetic, typeCoupon));
    }

    private static String getCosmeticName(String name, boolean gender) {
        final String genderString = gender ? "F" : "M";
        return String.format("%s (%s)", name, genderString);
    }

    private static void loadCosmeticNames(String cosmeticPath) throws IOException {
        fileReader = new InputStreamReader(new FileInputStream(cosmeticPath), StandardCharsets.UTF_8);
        bufferedReader = new BufferedReader(fileReader);

        String line;
        while ((line = bufferedReader.readLine()) != null) {
            String[] s = line.split(" - ", 3);
            int itemid = Integer.parseInt(s[0]);

            String name;
            if (itemid < 30000) {
                itemid = itemid - ((itemid / 100) % 10) * 100;

                int idx = s[1].lastIndexOf(" ");
                if (idx > -1) {
                    name = s[1].substring(0, idx);
                } else {
                    name = s[1];
                }
            } else {
                itemid = (Integer.valueOf(s[0]) / 10) * 10;

                int idx = s[1].indexOf(" ");
                if (idx > -1) {
                    name = s[1].substring(idx + 1);
                } else {
                    name = s[1];
                }
            }

            name = name.trim();

            String cname = getCosmeticName(name, (((itemid / 1000) % 10) % 3) != 0);

            /*
            if (cosmeticNameIds.containsKey(cname) && Math.abs(cosmeticNameIds.get(cname) - itemid) > 50) {
                System.out.println("Clashing '" + name + "' " + itemid + "/" + cosmeticNameIds.get(cname));
            }
            */

            cosmeticNameIds.put(cname, itemid);
            cosmeticIdNames.put(itemid, name);
        }

        bufferedReader.close();
        fileReader.close();
    }

    private static void loadCosmeticNames() throws IOException {
        System.out.println("Reading cosmetics from handbook ...");

        loadCosmeticNames(getHandbookFileName("/Equip/Face.txt"));
        loadCosmeticNames(getHandbookFileName("/Equip/Hair.txt"));
    }

    private static String getHandbookFileName(String fileName) {
        return ToolConstants.HANDBOOK_PATH + fileName;
    }

    private static List<Integer> fetchExpectedCosmetics(String[] cosmeticList, boolean gender) {
        List<Integer> list = new LinkedList<>();

        for (String cosmetic : cosmeticList) {
            String cname = getCosmeticName(cosmetic, gender);
            Integer itemid = cosmeticNameIds.get(cname);
            if (itemid != null) {
                list.add(itemid);
            } else {
                missingCosmeticNames.add(cosmetic);
            }
        }

        return list;
    }

    private static void verifyCosmeticExpectedFile(File f) throws IOException {
        String townName = f.getParent().substring(f.getParent().lastIndexOf("\\") + 1);
        String typeCosmetic = f.getName().substring(0, f.getName().indexOf("."));

        fileReader = new InputStreamReader(new FileInputStream(f), StandardCharsets.UTF_8);
        bufferedReader = new BufferedReader(fileReader);

        String line;
        while ((line = bufferedReader.readLine()) != null) {
            String[] s = line.split(": ", 2);
            String[] t = s[0].split("ale ");

            String typeCoupon = t[1];
            boolean gender = !t[0].contentEquals("M");

            Integer npcid = getCosmeticNpcid(townName, typeCosmetic, typeCoupon);
            if (npcid != null) {
                String[] cosmetics = s[1].split(", ");
                List<Integer> cosmeticItemids = fetchExpectedCosmetics(cosmetics, gender);

                Set<Integer> npcCosmetics = scriptCosmetics.get(npcid);
                Set<Integer> missingCosmetics = new HashSet<>();
                for (Integer itemid : cosmeticItemids) {
                    if (!npcCosmetics.contains(itemid)) {
                        missingCosmetics.add(itemid);
                    }
                }

                if (!missingCosmetics.isEmpty()) {
                    Pair<Integer, String> key = new Pair<>(npcid, typeCoupon);

                    Set<Integer> list = missingCosmeticsNpcTypes.get(key);
                    if (list == null) {
                        missingCosmeticsNpcTypes.put(key, missingCosmetics);
                    } else {
                        list.addAll(missingCosmetics);
                    }
                }
            }
        }

        bufferedReader.close();
        fileReader.close();
    }

    private static void verifyCosmeticExpectedData() throws IOException {
        System.out.println("Analyzing cosmetic NPC scripts ...");

        ArrayList<File> cosmeticRecipes = new ArrayList<>();
        listFiles(INPUT_DIRECTORY_PATH, cosmeticRecipes);

        for (File f : cosmeticRecipes) {
            verifyCosmeticExpectedFile(f);
        }
    }

    private static List<Pair<Pair<Integer, String>, List<Integer>>> getSortedMapEntries(Map<Pair<Integer, String>, Set<Integer>> map) {
        List<Pair<Pair<Integer, String>, List<Integer>>> list = new ArrayList<>(map.size());
        for (Map.Entry<Pair<Integer, String>, Set<Integer>> e : map.entrySet()) {
            List<Integer> il = new ArrayList<>(2);
            il.addAll(e.getValue());

            il.sort((o1, o2) -> o1 - o2);

            list.add(new Pair<>(e.getKey(), il));
        }

        list.sort((o1, o2) -> {
            int cmp = o1.getLeft().getLeft() - o2.getLeft().getLeft();
            if (cmp == 0) {
                return o1.getLeft().getRight().compareTo(o2.getLeft().getRight());
            } else {
                return cmp;
            }
        });

        return list;
    }

    private static void printReportFileHeader() {
        printWriter.println(" # Report File autogenerated from the MapleCashCosmeticsChecker feature by Ronan Lana.");
        printWriter.println(" # Generated data takes into account several data info from the server source files and the server-side WZ.xmls.");
        printWriter.println();
    }

    private static Pair<List<Integer>, List<Integer>> getCosmeticReport(List<Integer> itemids) {
        List<Integer> maleItemids = new LinkedList<>();
        List<Integer> femaleItemids = new LinkedList<>();

        for (Integer i : itemids) {
            if ((((i / 1000) % 10) % 3) == 0) {
                maleItemids.add(i);
            } else {
                femaleItemids.add(i);
            }
        }

        return new Pair<>(maleItemids, femaleItemids);
    }

    private static void reportNpcCosmetics(List<Integer> itemids) {
        if (!itemids.isEmpty()) {
            String res = "    ";
            for (Integer i : itemids) {
                res += (i + ", ");
                unusedCosmetics.remove(i);
            }

            printWriter.println(res.substring(0, res.length() - 2));
        }
    }

    private static void reportCosmeticResults() throws IOException {
        System.out.println("Reporting results ...");

        try (PrintWriter pw = new PrintWriter(Files.newOutputStream(OUTPUT_FILE));) {
            printWriter = pw;
            printReportFileHeader();

            if (!missingCosmeticsNpcTypes.isEmpty()) {
                printWriter.println(
                        "Found " + missingCosmeticsNpcTypes.size() + " entries with missing cosmetic entries.");

                for (Pair<Pair<Integer, String>, List<Integer>> mcn : getSortedMapEntries(missingCosmeticsNpcTypes)) {
                    printWriter.println("  NPC " + mcn.getLeft());

                    Pair<List<Integer>, List<Integer>> genderItemids = getCosmeticReport(mcn.getRight());
                    reportNpcCosmetics(genderItemids.getLeft());
                    reportNpcCosmetics(genderItemids.getRight());
                    printWriter.println();
                }
            }

            if (!unusedCosmetics.isEmpty()) {
                printWriter.println("Unused cosmetics: " + unusedCosmetics.size());

                List<Integer> list = new ArrayList<>(unusedCosmetics);
                Collections.sort(list);

                for (Integer i : list) {
                    printWriter.println(i + " " + cosmeticIdNames.get(i));
                }

                printWriter.println();
            }

            if (!missingCosmeticNames.isEmpty()) {
                printWriter.println("Missing cosmetic itemids: " + missingCosmeticNames.size());

                List<String> listString = new ArrayList<>(missingCosmeticNames);
                Collections.sort(listString);

                for (String c : listString) {
                    printWriter.println(c);
                }

                printWriter.println();
            }
        }
    }

    public static void main(String[] args) {
        try {
            loadCosmeticWzData();
            processCosmeticScriptData();

            loadCosmeticCouponNpcs();
            generateCosmeticPlaceNpcs();

            loadCosmeticNames();
            verifyCosmeticExpectedData();

            reportCosmeticResults();
            System.out.println("Done!");
        } catch (IOException ioe) {
            ioe.printStackTrace();
        }
    }
}
