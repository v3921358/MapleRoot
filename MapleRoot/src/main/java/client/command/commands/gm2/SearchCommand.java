package client.command.commands.gm2;

import client.Character;
import client.Client;
import client.command.Command;
import constants.id.NpcId;
import provider.Data;
import provider.DataProvider;
import provider.DataProviderFactory;
import provider.DataTool;
import provider.wz.WZFiles;
import scripting.npc.NPCScriptManager;
import server.ItemInformationProvider;
import server.quest.Quest;
import tools.PacketCreator;
import tools.Pair;

import java.util.ArrayList;

public class SearchCommand extends Command {
    private static Data npcStringData;
    private static Data mobStringData;
    private static Data skillStringData;
    private static Data mapStringData;

    {
        setDescription("Search through String.wz.");

        DataProvider dataProvider = DataProviderFactory.getDataProvider(WZFiles.STRING);
        npcStringData = dataProvider.getData("Npc.img");
        mobStringData = dataProvider.getData("Mob.img");
        skillStringData = dataProvider.getData("Skill.img");
        mapStringData = dataProvider.getData("Map.img");
    }

    @Override
    public void execute(Client c, String[] params) {
        Character player = c.getPlayer();
        if (params.length < 2) {
            player.yellowMessage("Syntax: !search/find <type> <name>");
            return;
        }
        StringBuilder sb = new StringBuilder();

        boolean item = false;
        boolean mob = false;
        boolean npc = false;
        boolean map = false;
        boolean quest = false;
        boolean results = true;
        ArrayList<Integer> searchdata = new ArrayList<>();

        String search = joinStringFrom(params, 1);
        long start = System.currentTimeMillis();//for the lulz
        Data data = null;
        if (!params[0].equalsIgnoreCase("ITEM")) {
            int searchType = 0;

            if (params[0].equalsIgnoreCase("NPC")) {
                data = npcStringData;
            } else if (params[0].equalsIgnoreCase("MOB") || params[0].equalsIgnoreCase("MONSTER")) {
                data = mobStringData;
                // } else if (params[0].equalsIgnoreCase("SKILL")) {
                //  data = skillStringData;
            } else if (params[0].equalsIgnoreCase("MAP")) {
                data = mapStringData;
                searchType = 1;
            } else if (params[0].equalsIgnoreCase("QUEST")) {
                data = mapStringData;
                searchType = 2;
            } else {
                sb.append("#bInvalid search.\r\nSyntax: '!search [type] [name]', where [type] is MAP, QUEST, NPC, ITEM, MOB, or SKILL.");
            }
            if (data != null) {
                String name;

                if (searchType == 0) {
                    int counter = -1;
                    for (Data searchData : data.getChildren()) {
                        name = DataTool.getString(searchData.getChildByPath("name"), "NO-NAME");
                        if (name.toLowerCase().contains(search.toLowerCase())) {
                            counter++;
                            //sb.append("#b").append(Integer.parseInt(searchData.getName())).append("#k - #r").append(name).append("#l\r\n");
                            sb.append("#L").append(counter).append("##b").append(Integer.parseInt(searchData.getName())).append("#k - #r").append(name).append("#l\r\n");
                            searchdata.add(Integer.parseInt(searchData.getName()));
                            if (params[0].equalsIgnoreCase("MOB") || params[0].equalsIgnoreCase("MONSTER")) {
                                mob = true;
                            } else if (params[0].equalsIgnoreCase("NPC")) {
                                npc = true;
                            }
                        }
                    }
                } else if (searchType == 1) {
                    map = true;
                    int counter = 0;
                    String mapName, streetName;
                    for (Data searchDataDir : data.getChildren()) {
                        for (Data searchData : searchDataDir.getChildren()) {
                            mapName = DataTool.getString(searchData.getChildByPath("mapName"), "NO-NAME");
                            streetName = DataTool.getString(searchData.getChildByPath("streetName"), "NO-NAME");

                            if (mapName.toLowerCase().contains(search.toLowerCase()) || streetName.toLowerCase().contains(search.toLowerCase())) {
                                int mapId = Integer.parseInt(searchData.getName());
                                searchdata.add(mapId);
                                sb.append("#L").append(counter).append("##b").append(mapId).append("#k - #r").append(streetName).append(" - ").append(mapName).append("#l\r\n");
                                counter ++;
                            }
                        }
                    }
                } else {
                    quest = true;
                    int counter = 0;
                    for (Quest mq : Quest.getMatchedQuests(search)) {
                        searchdata.add((int)mq.getId());
                        sb.append("#L").append(counter).append("##b").append(mq.getId()).append("#k - #r");

                        String parentName = mq.getParentName();
                        if (!parentName.isEmpty()) {
                            sb.append(parentName).append(" - ");
                        }
                        sb.append(mq.getName()).append("#l\r\n");
                        counter++;
                    }
                }
            }
        } else {
            int counter = -1;
            for (Pair<Integer, String> itemPair : ItemInformationProvider.getInstance().getAllItems()) {
                if (sb.length() < 32654) {//ohlol
                    if (itemPair.getRight().toLowerCase().contains(search.toLowerCase())) {
                        counter++;
                        sb.append("#L").append(counter).append("##b").append(itemPair.getLeft()).append("#k - #r#z").append(itemPair.getLeft()).append("##l\r\n");
                        searchdata.add(itemPair.getLeft());
                        item = true;
                    }
                } else {
                    sb.append("#bCouldn't load all items, there are too many results.\r\n");
                    break;
                }
            }
        }
        if (sb.isEmpty()) {
            results = false;
            sb.append("#bNo ").append(params[0].toLowerCase()).append("s found.\r\n");
        }
        sb.append("\r\n#kLoaded within ").append((double) (System.currentTimeMillis() - start) / 1000).append(" seconds.");//because I can, and it's free
        if (!results || (!item && !mob && !npc && !map && !quest) ) {
            c.sendPacket(PacketCreator.getNPCTalk(9010000, (byte) 0, sb.toString(), "00 00", (byte) 0));
        } else {
            c.getPlayer().setDataSearch(sb.toString());
            c.getPlayer().setDataSearchArr(searchdata);
            c.getPlayer().setDataSearchType(item ? "item" : (mob ? "mob" : (npc ? "npc" : (map ? "map" : "quest"))));
            NPCScriptManager.getInstance().start(c, 1032009, "search", c.getPlayer());
        }
    }
}