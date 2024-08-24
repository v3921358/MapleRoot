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

var status = -1; //invalid value, bascially -Darnell 2023
var selectionChoices = [];

function start() {
    //cm.logMessage("3004015", `${BossLogEntry.Map}`);  DARNELL LOVES YOU VERY MUCH
    selectionChoices = Object.values(BossLogEntry.Map);
    action(1,0,0)
}

function action(mode, type, selection) {
    if (mode == 1) {
        status++;
    } else {
        status--;    
    }
   
    if (status == 0) {
        cm.sendSimple (`The followning options will show your expedition attempts and time remaining to repeat them.\r\n${generateSelectionMenu(selectionChoices)}`);

    } else if (status == 1) {
        cm.sendOk (`You've attempted ${BossLogEntry.Map[selection+1]} ${cm.getBossLogEntries(selection)} times`)
        
    } else{cm.dispose();}
    
}

function generateSelectionMenu(array) {     // nice tool for generating a string for the sendSimple functionality
    var menu = "";
    for (var i = 0; i < array.length; i++) {
        menu += "#L" + i + "#" + array[i] + "#l\r\n";
    }
    return menu;
}





var BossLogEntry = {
    Map:{
        1: "ZAKUM",
        2: "HORNTAIL",
        3: "PINKBEAN",
        4: "SCARGA",
        5: "PAPULATUS",
        6: "VONLEON",
        7: "CYGNUS",
        8: "WILLSPIDER",
        9: "VERUS",
        10: "DARKNELL",
        11: "KREXEL",
        12: "CASTELLAN",
    }, 
    ZAKUM: 1,
    HORNTAIL: 2,
    PINKBEAN: 3,
    SCARGA: 4,
    PAPULATUS: 5,
    VONLEON: 6,
    CYGNUS: 7,
    WILLSPIDER: 8,
    VERUS: 9,
    DARKNELL: 10,
    KREXEL: 11,
    CASTELLAN: 12,
}