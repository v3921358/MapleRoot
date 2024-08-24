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
/*
 * @Name: Cotton Warper
 * @NPC ID: 9010002
 * @Author: MrXotic
 * @Author: XxOsirisxX
 * @Author: Moogra
 */

var status = -1;
var possibleJobs = new Array();
var maps = [
    /*BossMaps*/[240050400, 211042400],

    /*MonsterMaps*/[104040000, 101010100, 104010001, 103000101, 105070001, 101030103, 230020000,
        101040001, 106000002, 220010500, 200040000, 110010000, 230010400, 222010000, 101040003,
        103000105, 251010000, 250020000, 800040202, 682010201, 211041400, 105040306, 105090300,
        101030110, 682010202, 200010301, 600020300, 240020100, 551030100, 541020100, 541010010, 682010203, 801040004, 
        230040000, 220070300, 240040000, 800020130, 240040500, 541020500, 270010410, 270020410, 270030410],

    /*Towns*/[  300000000, 680000000, 230000000, 260000000, 541000000,
                540010000, 219000000, 610010004, 211060000, 101000000, 211000000,
                110000000, 100000000, 251000000, 551000000, 103000000, 222000000,
                240000000, 104000000, 220000000, 261000000,  250000000, 106020000,
                800000000, 120000000, 600000000, 221000000, 200000000, 800040000,
                102000000, 140000000, 801000000, 105040300, 270000000,  240070000],

    /*Grandis*/[400000000, 401000000, 402000600, 410000000, 402000000, 410000416, 402000500, 410000200, 410000300],

    /*Arcane River*/[450001000, 450002000, 450015060, 450003000, 450005000, 450006130, 450007040, 450016000, 450009100, 450011120, 450012300]];
var chosenMap = -1;
var chosenSection = -1;

function start() {
    status = -1;
    action(1, 0, 0);
}

function action(mode, type, selection) {
    if (mode === 1) {
        status++;
    } else {
        cm.dispose();
        return;
    }
    if (status === 0) {
        if (cm.getChar().getReborns() >= 3) {
            cm.sendSimple("Hi! Where would you like to go?\r\n\r\n" +
                "#b#L0#  #fMap/MapHelper.img/mark/Zakum#  Boss Maps#l\r\n\r\n" +
                "#b#L1#  #fMap/MapHelper.img/mark/BattleSquare#  Monster Maps#l\r\n\r\n" +
                "#b#L2#  #fMap/MapHelper.img/mark/Henesys#  Towns#l\r\n\r\n" +
                "#b#L3#  #fMap/MapHelper.img/mark/Ristonia#  Grandis Towns#l\r\n\r\n" +
                "#b#L4#  #fMap/MapHelper.img/mark/Lacheln#  Arcane River Towns#l");

        } else {
            cm.sendSimple("Hi! Where would you like to go?\r\n\r\n" +
            "#b#L0#  #fMap/MapHelper.img/mark/Zakum#  Boss Maps#l\r\n\r\n" +
            "#b#L1#  #fMap/MapHelper.img/mark/BattleSquare#  Monster Maps#l\r\n\r\n" +
            "#b#L2#  #fMap/MapHelper.img/mark/Henesys#  Towns#l\r\n\r\n" +
            "#b#L3#  #fMap/MapHelper.img/mark/Ristonia#  Grandis Towns#l\r\n\r\n" +
            "#b#L4#  #fMap/MapHelper.img/mark/Lacheln#  Arcane River Towns#l");
        }
    }
    if (status == 1) {
        if (selection === 4 || selection === 3) {
            // Handle access to Arcane River Towns
            if (cm.getChar().getReborns() < 3) {
                cm.sendOk("#r                                            #fMap/MapHelper.img/mark/Lacheln# \r\n\r\nYou need to have at least 3 rebirths to access Grandis/Arance River.");
                cm.dispose();
                return;
            }
        }
        chosenSection = selection;
        if (chosenSection === 0) {
            showBossMaps();
        } else if (chosenSection === 1) {
            showMonsterMaps();
        } else if (chosenSection === 2) {
            showOssyriaTowns();
        } else if (chosenSection === 3) {
            showGrandisTowns();
        } else if (chosenSection === 4) {
            showArcaneRiverTowns();
        }
    } else if (status == 2) {
        chosenMap = selection;
        cm.sendYesNo("Do you want to go to #m" + maps[chosenSection][chosenMap] + "#?");
    } else if (status == 3) {
        cm.warp(maps[chosenSection][chosenMap]);
        cm.dispose();
    }
}

function showBossMaps() {
    var selStr = "                                          #fMap/MapHelper.img/mark/Zakum# #b";
    for (var i = 0; i < maps[chosenSection].length; i++) {
        selStr += "\r\n#L" + i + "##m" + maps[chosenSection][i] + "#";
    }
    cm.sendSimple(selStr);
}

function showMonsterMaps() {
    var selStr = "                                          #fMap/MapHelper.img/mark/BattleSquare# #b";
    for (var i = 0; i < maps[chosenSection].length; i++) {
        selStr += "\r\n#L" + i + "##m" + maps[chosenSection][i] + "#";
    }
    cm.sendSimple(selStr);
}

function showOssyriaTowns() {
    var selStr = "                                          #fMap/MapHelper.img/mark/Henesys# #b";
    for (var i = 0; i < maps[chosenSection].length; i++) {
        selStr += "\r\n#L" + i + "##m" + maps[chosenSection][i] + "#";
    }
    cm.sendSimple(selStr);
}

function showGrandisTowns() {
    var selStr = "                                          #fMap/MapHelper.img/mark/Henesys# #b";
    for (var i = 0; i < maps[chosenSection].length; i++) {
        selStr += "\r\n#L" + i + "##m" + maps[chosenSection][i] + "#";
    }
    cm.sendSimple(selStr);
}

function showArcaneRiverTowns() {
    var selStr = "                                          #fMap/MapHelper.img/mark/Lacheln# #b";
    for (var i = 0; i < maps[chosenSection].length; i++) {
        selStr += "\r\n#L" + i + "##m" + maps[chosenSection][i] + "#";
    }
    cm.sendSimple(selStr);
}
