/*
	This file is part of the OdinMS Maple Story Server
    Copyright (C) 2008 Patrick Huy <patrick.huy@frz.cc>
		       Matthias Butz <matze@odinms.de>
		       Jan Christian Meyer <vimes@odinms.de>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation version 3 as published by
    the Free Software Foundation. You may not use, modify or distribute
    this program under any other version of the GNU Affero General Public
    License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
package constants.inventory;

import client.inventory.InventoryType;
import config.YamlConfig;
import constants.id.ItemId;

import java.util.*;

/**
 * @author Jay Estrella
 * @author Ronan
 */
public final class ItemConstants {
    protected static Map<Integer, InventoryType> inventoryTypeCache = new HashMap<>();

    public final static short LOCK = 0x01;
    public final static short SPIKES = 0x02;
    public final static short KARMA_USE = 0x02;
    public final static short COLD = 0x04;
    public final static short UNTRADEABLE = 0x08;
    public final static short KARMA_EQP = 0x10;
    public final static short SANDBOX = 0x40;             // let 0x40 until it's proven something uses this
    public final static short PET_COME = 0x80;
    public final static short ACCOUNT_SHARING = 0x100;
    public final static short MERGE_UNTRADEABLE = 0x200;

    public final static int STORAGE_MAX_SLOT_SIZE = 255;

    public final static boolean EXPIRING_ITEMS = true;
    public final static Set<Integer> permanentItemids = new HashSet<>();

    public final static Set<Integer> makerItemIds = new HashSet<>(Arrays.asList(
            4004000, 4004001, 4004002, 4004003, 4004004, 4005000, 4005001,
            4005002, 4005003, 4005004, 4007000, 4007001, 4007002, 4007003,
            4007004, 4007005, 4007006, 4007007, 4010000, 4010001, 4010002,
            4010003, 4010004, 4010005, 4010006, 4010007, 4011000, 4011001,
            4011002, 4011003, 4011004, 4011005, 4011006, 4011007, 4011008,
            4020000, 4020001, 4020002, 4020003, 4020004, 4020005, 4020006,
            4020007, 4020008, 4020009, 4021000, 4021001, 4021002, 4021003,
            4021004, 4021005, 4021006, 4021007, 4021008, 4021009, 4021010,
            4250000, 4250001, 4250002, 4250100, 4250101, 4250102, 4250200,
            4250201, 4250202, 4250300, 4250301, 4250302, 4250400, 4250401,
            4250402, 4250500, 4250501, 4250502, 4250600, 4250601, 4250602,
            4250700, 4250701, 4250702, 4250800, 4250801, 4250802, 4250900,
            4250901, 4250902, 4251000, 4251001, 4251002, 4251100, 4251101,
            4251102, 4251200, 4251201, 4251202, 4251300, 4251301, 4251302,
            4251400, 4251401, 4251402, 4260000, 4260001, 4260002, 4260003,
            4260004, 4260005, 4260006, 4260007, 4260008
    ));

    public final static Set<Integer> SuperiorItemIds = new HashSet<>(Arrays.asList(
            1132174, 1132175, 1132176, 1132177, 1132178, 1102481, 1102482,
            1102483, 1102484, 1102485, 1082543, 1082544, 1082545, 1082546,
            1082547, 1072743, 1072744, 1072745, 1072746, 1072747, 1132164,
            1132165, 1132166, 1132167, 1132168, 1102471, 1102472, 1102473,
            1102474, 1102475, 1072732, 1072733, 1072734, 1072735, 1072736,
            1132170, 1132171, 1132172, 1132173, 1132169, 1102476, 1072741,
            1102477, 1102478, 1102479, 1102480, 1072737, 1072738, 1072739,
            1072740

    ));

    public final static Set<Integer> useBlockedIds = new HashSet<>(Arrays.asList(
            //Elixirs & Stat increases
            2000004, 2000005, 2000006, 2000011, 2000012, 2000018, 2000019,
            2002012, 2002013, 2002015, 2002016, 2002017, 2002018, 2002019,
            2002024, 2002025, 2022282, 2022439, 2022456, 2022457, 2022544,
            2012008, 2022179, 2022273, 2022283, 2002023, 2002026, 2002020,
            2002021, 2002022, 2050004, 2001000,

            //Throwing Stars, Bullets, and Arrows
            2070000, 2070001, 2070002, 2070003, 2070004, 2070005, 2070006,
            2070007, 2070008, 2070009, 2070010, 2070011, 2070012, 2070013,
            2070015, 2070016, 2070018, 2060001, 2060002, 2060003,
            2060004, 2061001, 2061002, 2061003, 2061004, 2330000,
            2330001, 2330002, 2330003, 2330004, 2330005,

            //Scrolls
            2044818, 2044911, 2002029, 2030000, 2030001, 2030002, 2030003,
            2030004, 2030005, 2030006, 2030007, 2030019, 2030020, 2030100,
            2040000, 2040001, 2040002, 2040003, 2040004, 2040005, 2040006,
            2040007, 2040008, 2040009, 2040010, 2040011, 2040012, 2040013,
            2040014, 2040015, 2040016, 2040017, 2040018, 2040019, 2040020,
            2040021, 2040022, 2040023, 2040024, 2040025, 2040026, 2040027,
            2040028, 2040029, 2040030, 2040031, 2040041, 2040042, 2040043,
            2040044, 2040045, 2040046, 2040100, 2040101, 2040102, 2040103,
            2040104, 2040105, 2040106, 2040107, 2040108, 2040109, 2040200,
            2040201, 2040202, 2040203, 2040204, 2040205, 2040206, 2040207,
            2040208, 2040209, 2040300, 2040301, 2040302, 2040303, 2040304,
            2040305, 2040306, 2040307, 2040308, 2040309, 2040310, 2040311,
            2040312, 2040313, 2040314, 2040315, 2040316, 2040317, 2040318,
            2040319, 2040320, 2040321, 2040322, 2040323, 2040324, 2040325,
            2040326, 2040327, 2040328, 2040329, 2040330, 2040331, 2040333,
            2040334, 2040335, 2040336, 2040337, 2040338, 2040339, 2040340,
            2040400, 2040401, 2040402, 2040403, 2040404, 2040405, 2040406,
            2040407, 2040408, 2040409, 2040410, 2040411, 2040412, 2040413,
            2040414, 2040415, 2040416, 2040417, 2040418, 2040419, 2040420,
            2040421, 2040422, 2040423, 2040424, 2040425, 2040426, 2040427,
            2040429, 2040430, 2040431, 2040432, 2040433, 2040434, 2040435,
            2040436, 2040500, 2040501, 2040502, 2040503, 2040504, 2040505,
            2040506, 2040507, 2040508, 2040509, 2040510, 2040511, 2040512,
            2040513, 2040514, 2040515, 2040516, 2040517, 2040518, 2040519,
            2040520, 2040521, 2040522, 2040523, 2040524, 2040525, 2040526,
            2040527, 2040528, 2040529, 2040530, 2040531, 2040532, 2040533,
            2040534, 2040538, 2040539, 2040540, 2040541, 2040542, 2040543,
            2040600, 2040601, 2040602, 2040603, 2040604, 2040605, 2040606,
            2040607, 2040608, 2040609, 2040610, 2040611, 2040612, 2040613,
            2040614, 2040615, 2040616, 2040617, 2040618, 2040619, 2040620,
            2040621, 2040622, 2040623, 2040624, 2040625, 2040626, 2040627,
            2040629, 2040630, 2040631, 2040632, 2040633, 2040634, 2040635,
            2040636, 2040700, 2040701, 2040702, 2040703, 2040704, 2040705,
            2040706, 2040707, 2040708, 2040709, 2040710, 2040711, 2040712,
            2040713, 2040714, 2040715, 2040716, 2040717, 2040718, 2040719,
            2040720, 2040721, 2040722, 2040723, 2040727, 2040728, 2040729,
            2040730, 2040731, 2040732, 2040733, 2040734, 2040735, 2040736,
            2040737, 2040738, 2040739, 2040740, 2040741, 2040742, 2040755,
            2040756, 2040757, 2040758, 2040759, 2040760, 2040800, 2040801,
            2040802, 2040803, 2040804, 2040805, 2040806, 2040807, 2040808,
            2040809, 2040810, 2040811, 2040812, 2040813, 2040814, 2040815,
            2040816, 2040817, 2040818, 2040819, 2040820, 2040821, 2040822,
            2040823, 2040824, 2040825, 2040826, 2040829, 2040830, 2040831,
            2040832, 2040833, 2040834, 2040900, 2040901, 2040902, 2040903,
            2040904, 2040905, 2040906, 2040907, 2040908, 2040909, 2040910,
            2040911, 2040912, 2040914, 2040915, 2040916, 2040917, 2040918,
            2040919, 2040920, 2040921, 2040922, 2040923, 2040924, 2040925,
            2040926, 2040927, 2040928, 2040929, 2040930, 2040931, 2040932,
            2040933, 2040936, 2040937, 2040938, 2040939, 2040940, 2040941,
            2040942, 2040943, 2041000, 2041001, 2041002, 2041003, 2041004,
            2041005, 2041006, 2041007, 2041008, 2041009, 2041010, 2041011,
            2041012, 2041013, 2041014, 2041015, 2041016, 2041017, 2041018,
            2041019, 2041020, 2041021, 2041022, 2041023, 2041024, 2041025,
            2041026, 2041027, 2041028, 2041029, 2041030, 2041031, 2041032,
            2041033, 2041034, 2041035, 2041036, 2041037, 2041038, 2041039,
            2041040, 2041041, 2041042, 2041043, 2041044, 2041045, 2041046,
            2041047, 2041048, 2041049, 2041050, 2041051, 2041052, 2041053,
            2041054, 2041055, 2041056, 2041057, 2041058, 2041059, 2041060,
            2041061, 2041062, 2041066, 2041067, 2041068, 2041069, 2041100,
            2041101, 2041102, 2041103, 2041104, 2041105, 2041106, 2041107,
            2041108, 2041109, 2041110, 2041111, 2041112, 2041113, 2041114,
            2041115, 2041116, 2041117, 2041118, 2041119, 2041300, 2041301,
            2041302, 2041303, 2041304, 2041305, 2041306, 2041307, 2041308,
            2041309, 2041310, 2041311, 2041312, 2041313, 2041314, 2041315,
            2041316, 2041317, 2041318, 2041319, 2043000, 2043001, 2043002,
            2043003, 2043004, 2043005, 2043006, 2043007, 2043008, 2043009,
            2043010, 2043011, 2043012, 2043013, 2043015, 2043016, 2043017,
            2043018, 2043019, 2043021, 2043022, 2043023, 2043024, 2043025,
            2043100, 2043101, 2043102, 2043103, 2043104, 2043105, 2043106,
            2043107, 2043108, 2043110, 2043111, 2043112, 2043113, 2043114,
            2043116, 2043117, 2043118, 2043119, 2043120, 2043200, 2043201,
            2043202, 2043203, 2043204, 2043205, 2043206, 2043207, 2043208,
            2043210, 2043211, 2043212, 2043213, 2043214, 2043216, 2043217,
            2043218, 2043219, 2043220, 2043300, 2043301, 2043302, 2043303,
            2043304, 2043305, 2043306, 2043307, 2043308, 2043311, 2043312,
            2043313, 2043700, 2043701, 2043702, 2043703, 2043704, 2043705,
            2043706, 2043707, 2043708, 2043711, 2043712, 2043713, 2043800,
            2043801, 2043802, 2043803, 2043804, 2043805, 2043806, 2043807,
            2043808, 2043811, 2043812, 2043813, 2044000, 2044001, 2044002,
            2044003, 2044004, 2044005, 2044006, 2044007, 2044008, 2044010,
            2044011, 2044012, 2044013, 2044014, 2044015, 2044024, 2044025,
            2044026, 2044027, 2044028, 2044100, 2044101, 2044102, 2044103,
            2044104, 2044105, 2044106, 2044107, 2044108, 2044110, 2044111,
            2044112, 2044113, 2044114, 2044116, 2044117, 2044118, 2044119,
            2044120, 2044200, 2044201, 2044202, 2044203, 2044204, 2044205,
            2044206, 2044207, 2044208, 2044210, 2044211, 2044212, 2044213,
            2044214, 2044216, 2044217, 2044218, 2044219, 2044220, 2044300,
            2044301, 2044302, 2044303, 2044304, 2044305, 2044306, 2044307,
            2044308, 2044310, 2044311, 2044312, 2044313, 2044314, 2044316,
            2044317, 2044318, 2044319, 2044320, 2044400, 2044401, 2044402,
            2044403, 2044404, 2044405, 2044406, 2044407, 2044408, 2044410,
            2044411, 2044412, 2044413, 2044414, 2044416, 2044417, 2044418,
            2044419, 2044420, 2044500, 2044501, 2044502, 2044503, 2044504,
            2044505, 2044506, 2044507, 2044508, 2044511, 2044512, 2044513,
            2044600, 2044601, 2044602, 2044603, 2044604, 2044605, 2044606,
            2044607, 2044608, 2044611, 2044612, 2044613, 2044700, 2044701,
            2044702, 2044703, 2044704, 2044705, 2044706, 2044707, 2044708,
            2044711, 2044712, 2044713, 2044800, 2044801, 2044802, 2044803,
            2044804, 2044805, 2044806, 2044807, 2044808, 2044809, 2044810,
            2044811, 2044812, 2044813, 2044814, 2044815, 2044816, 2044817,
            2044900, 2044901, 2044902, 2044903, 2044904, 2044906, 2044907,
            2044908, 2044909, 2044910, 2048000, 2048001, 2048002, 2048003,
            2048004, 2048005, 2048006, 2048007, 2048008, 2048009, 2048010,
            2048011, 2048012, 2048013, 2049000, 2049001, 2049002, 2049003,
            2049100, 2049103, 2049104, 2049105, 2049106, 2049107, 2049108,
            2049109, 2049110, 2049112, 2049113, 2049114, 2049200, 2049201,
            2049202, 2049203, 2049204, 2049205, 2049206, 2049207, 2049208,
            2049209, 2049210, 2049211, 2340000
            ));

    public final static Set<Integer> etcBlockedIds = new HashSet<>(Arrays.asList(
            4001126, 4001017, 4000415, 4004000, 4004001, 4004002, 4004003, 4004004,
            4010000, 4010001, 4010002, 4010003, 4010004, 4010005, 4010006, 4010007,
            4010008, 4010009, 4010010, 4020000, 4020001, 4020002, 4020003, 4020004,
            4020005, 4020006, 4020007, 4020008, 4031179, 4009454, 4009455, 4009456,
            4009457, 4009458, 4009459, 4021033, 4021034, 4021035, 4036513, 4020013,
            4260000, 4260001, 4260002, 4260003, 4260004, 4260005, 4260006, 4260007,
            4260008, 4011000, 4011001, 4011002, 4011003, 4011004, 4011005, 4011006,
            4251401, 4250401, 4021000, 4021001, 4021002, 4021003, 4021004, 4021005,
            4021006, 4021007, 4005000, 4005001, 4005002, 4005003, 4005004, 4006000,
            4006001, 4007000, 4007001, 4007002, 4007003, 4007004, 4007005, 4007006,
            4007007, 4032133, 4021010
    ));

    public final static Set<Integer> rebirth1 = new HashSet<>(Arrays.asList(
            1302193, 1322139, 1322139, 1402131, 1432119,    //Marx Von Leon Weapons level 120
            1442156, 1332170, 1372119, 1382145, 1412179,
            1422186, 1452149, 1462139, 1472161, 1482122,
            1492122
    ));

    public final static Set<Integer> rebirth2 = new HashSet<>(Arrays.asList(

            1004229, 1004230, 1004231, 1004232, 1004233,  //Pensalir Gear
            1052799, 1052800, 1052801, 1052802, 1052803,
            1072967, 1072968, 1072969, 1072970, 1072971,
            1082608, 1082609, 1082610, 1082611, 1082612,
            1102718, 1102719, 1102720, 1102721, 1102722,



            1302315, 1312185, 1322236, 1332260, 1372207,  //Utgard weapons
            1382245, 1402236, 1412164, 1422171, 1432200,
            1442254, 1452238, 1462225, 1472247, 1482202,
            1492212,


            1004224, 1004225, 1004226, 1004227, 1004228,  //Muspell gear set level 130
            1082603, 1082604, 1082605, 1082606, 1082607,
            1052794, 1052795, 1052796, 1052797, 1052798,
            1072962, 1072963, 1072964, 1072965, 1072966,



            1302314, 1312184, 1322235, 1332259,              //Jaihin Weapons  level 130
            1372206, 1382244, 1402235, 1412163, 1422170,
            1432199, 1442253, 1462224, 1452237, 1472246,
            1482201, 1492211,

            1302152, 1312065, 1322096, 1412065, 1422066,      //LionHeart Weapons level 140
            1432086, 1442116, 1372084, 1382104, 1452111,
            1462099, 1492085, 1482084, 1332130, 1472122


    ));

    public final static Set<Integer> rebirth3 = new HashSet<>(Arrays.asList(

            1302302, 1312177, 1322229, 1332252, 1372199,      //Azure Weapons level 135
            1382237, 1402226, 1412156, 1422163, 1432192,
            1442246, 1452231, 1462217, 1472239, 1482194,
            1492203,

            1302281, 1312159, 1322210, 1332232, 1372183,     //FrontierA Weapons level 135
            1382217, 1402206, 1412141, 1422146, 1432173,
            1442229, 1452211, 1462199, 1472220, 1482174,
            1492185,

            1302282, 1312160, 1322211, 1332233, 1372184,       // FrontierB Weapons level 140
            1382218, 1402207, 1412142, 1422147, 1432174,
            1442230, 1452212, 1462200, 1472221, 1482175,
            1492186,

            1302283, 1312161, 1322212, 1332234, 1372185,       //FrontierC Weapons  level 145
            1382219, 1402208, 1412143, 1422148, 1432175,
            1442231, 1452213, 1462201, 1472222, 1482176,
            1492187,

            1302275, 1312153, 1322203, 1332225, 1372177,       //Fafnir Weapons level 160
            1382208, 1402196, 1412135, 1422140, 1432167,
            1442223, 1452205, 1462193, 1472214, 1482168,
            1492179,

            1302290, 1312166, 1322216, 1332239, 1372189,      //Terminus Weapons level 160
            1382223, 1402211, 1412148, 1422153, 1432179,
            1442235, 1452217, 1462205, 1472227, 1482180,
            1492191


    ));

    public static Set<Integer> getRestrictedItemsForRebirth(int rebirths) {
        Set<Integer> result = new HashSet<>();

        if (rebirths == 0) {
            result.addAll(rebirth1);
            result.addAll(rebirth2);
            result.addAll(rebirth3);

            return result;
        }

        if (rebirths == 1) {
            result.addAll(rebirth2);
            result.addAll(rebirth3);

            return result;
        }

        if (rebirths == 2) {
            result.addAll(rebirth3);

            return result;
        }

        // no restricted items
        return result;
    }
    public static Integer getItemRebirthRequirement(int itemId) {
        if(rebirth1.contains(itemId)) return 1;
        if(rebirth2.contains(itemId)) return 2;
        if(rebirth3.contains(itemId)) return 3;
        return 0;
    }

    static {
        // i ain't going to open one gigantic itemid cache just for 4 perma itemids, no way!
        for (int petItemId : ItemId.getPermaPets()) {
            permanentItemids.add(petItemId);
        }
    }

    public static int getFlagByInt(int type) {
        if (type == 128) {
            return PET_COME;
        } else if (type == 256) {
            return ACCOUNT_SHARING;
        }
        return 0;
    }

    public static boolean isThrowingStar(int itemId) {
        return itemId / 10000 == 207;
    }

    public static boolean isBullet(int itemId) {
        return itemId / 10000 == 233;
    }

    public static boolean isPotion(int itemId) {
        return itemId / 1000 == 2000;
    }

    public static boolean isFood(int itemId) {
        int useType = itemId / 1000;
        return useType == 2022 || useType == 2010 || useType == 2020;
    }

    public static boolean isConsumable(int itemId) {
        return isPotion(itemId) || isFood(itemId);
    }

    public static boolean isRechargeable(int itemId) {
        return isThrowingStar(itemId) || isBullet(itemId);
    }

    public static boolean isArrowForCrossBow(int itemId) {
        return itemId / 1000 == 2061;
    }

    public static boolean isArrowForBow(int itemId) {
        return itemId / 1000 == 2060;
    }

    public static boolean isArrow(int itemId) {
        return isArrowForBow(itemId) || isArrowForCrossBow(itemId);
    }

    public static boolean isPet(int itemId) {
        return itemId / 1000 == 5000;
    }

    public static boolean isExpirablePet(int itemId) {
        return YamlConfig.config.server.USE_ERASE_PET_ON_EXPIRATION || itemId == ItemId.PET_SNAIL;
    }

    public static boolean isPermanentItem(int itemId) {
        return permanentItemids.contains(itemId);
    }

    public static boolean isNewYearCardEtc(int itemId) {
        return itemId / 10000 == 430;
    }

    public static boolean isNewYearCardUse(int itemId) {
        return itemId / 10000 == 216;
    }

    public static boolean isAccessory(int itemId) {
        return itemId >= 1110000 && itemId < 1140000;
    }

    public static boolean isTaming(int itemId) {
        int itemType = itemId / 1000;
        return itemType == 1902 || itemType == 1912;
    }

    public static boolean isTownScroll(int itemId) {
        return itemId >= 2030000 && itemId < ItemId.ANTI_BANISH_SCROLL;
    }

    public static boolean isAntibanishScroll(int itemId) {
        return itemId == ItemId.ANTI_BANISH_SCROLL;
    }

    public static boolean isCleanSlate(int scrollId) {
        return scrollId > 2048999 && scrollId < 2049004;
    }

    public static boolean isModifierScroll(int scrollId) {
        return scrollId == ItemId.SPIKES_SCROLL || scrollId == ItemId.COLD_PROTECTION_SCROLl;
    }

    public static boolean isFlagModifier(int scrollId, short flag) {
        if (scrollId == ItemId.COLD_PROTECTION_SCROLl && ((flag & ItemConstants.COLD) == ItemConstants.COLD)) {
            return true;
        }
        return scrollId == ItemId.SPIKES_SCROLL && ((flag & ItemConstants.SPIKES) == ItemConstants.SPIKES);
    }

    public static boolean isChaosScroll(int scrollId) {
        return scrollId >= 2049100 && scrollId <= 2049103;
    }

    public static boolean isRateCoupon(int itemId) {
        int itemType = itemId / 1000;
        return itemType == 5211 || itemType == 5360 || itemType == 5431 || itemType == 5432;
    }

    public static boolean isExpCoupon(int couponId) {
        return couponId / 1000 == 5211;
    }

    public static boolean isPartyItem(int itemId) {
        return itemId >= 2022430 && itemId <= 2022433 || itemId >= 2022160 && itemId <= 2022163;
    }

    public static boolean isHiredMerchant(int itemId) {
        return itemId / 10000 == 503;
    }

    public static boolean isPlayerShop(int itemId) {
        return itemId / 10000 == 514;
    }

    public static InventoryType getInventoryType(final int itemId) {
        if (inventoryTypeCache.containsKey(itemId)) {
            return inventoryTypeCache.get(itemId);
        }

        InventoryType ret = InventoryType.UNDEFINED;

        final byte type = (byte) (itemId / 1000000);
        if (type >= 1 && type <= 5) {
            ret = InventoryType.getByType(type);
        }

        inventoryTypeCache.put(itemId, ret);
        return ret;
    }

    public static boolean isMakerReagent(int itemId) {
        return itemId / 10000 == 425;
    }

    public static boolean isOverall(int itemId) {
        return itemId / 10000 == 105;
    }

    public static boolean isCashStore(int itemId) {
        int itemType = itemId / 10000;
        return itemType == 503 || itemType == 514;
    }

    public static boolean isMapleLife(int itemId) {
        int itemType = itemId / 10000;
        return itemType == 543 && itemId != 5430000;
    }

    public static boolean isWeapon(int itemId) {
        return itemId >= 1302000 && itemId < 1493000;
    }

    public static boolean isEquipment(int itemId) {
        return itemId < 2000000 && itemId != 0;
    }

    public static boolean isFishingChair(int itemId) {
        return itemId == ItemId.FISHING_CHAIR;
    }

    public static boolean isMedal(int itemId) {
        return itemId >= 1140000 && itemId < 1143000;
    }

    public static boolean isFace(int itemId) {
        return itemId >= 20000 && itemId < 22000;
    }

    public static boolean isHair(int itemId) {
        return itemId >= 30000 && itemId < 35000;
    }
}
