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
/* 	Jimmy
	Singapore Random Hair/Color Changer
	@Author Cody (FlowsionMS)
        @Author AAron (FlowsionMS)

        GMS-like revised by Ronan -- contents found thanks to Mitsune (GamerBewbs), Waltzing, AyumiLove
 */
var status = 0;
var beauty = 0;
var mhair_r = Array(30110, 30180, 30260, 30290, 30300, 30350, 30470, 30720, 30840);
var fhair_r = Array(31110, 31200, 31250, 31280, 31600, 31640, 31670, 31810, 34020);
var hairnew = Array();

function pushIfItemExists(array, itemid) {
    if ((itemid = cm.getCosmeticItem(itemid)) != -1 && !cm.isCosmeticEquipped(itemid)) {
        array.push(itemid);
    }
}

function start() {
    cm.sendSimple("Hi, I'm the assistant here. Dont worry, I'm plenty good enough for this. If you have #b#t5150032##k or #b#t5151027##k by any chance, then allow me to take care of the rest?\r\n#L1#Haircut: #i5150032##t5150032##l\r\n#L2#Dye your hair: #i5151027##t5151027##l");
}

function action(mode, type, selection) {
    if (mode < 1) {
        cm.dispose();
    } else {
        status++;
        if (selection == 1) {
            beauty = 1;
            hairnew = Array();
            for (var id = 0; id < cm.getPlayer().getGender() == 0 ? mhair_r.length : fhair_r.length; id++) {
                pushIfItemExists(hairnew, cm.getPlayer().getGender == 0 ? mhair_r[i] : fhair_r[i] + parseInt(cm.getPlayer().getHair() % 10));
            }
            cm.sendYesNo("If you use the REG coupon your hair will change RANDOMLY with a chance to obtain a new experimental style that I came up with. Are you going to use #b#t5150032##k and really change your hairstyle?");
        } else if (selection == 2) {
            beauty = 2;
            haircolor = Array();
            var current = parseInt(cm.getPlayer().getHair() / 10) * 10;
            for (var i = 0; i < 8; i++) {
                pushIfItemExists(haircolor, current + i);
            }
            cm.sendYesNo("If you use the REG coupon your hair will change RANDOMLY. Do you still want to use #b#t5151027##k and change it up?");
        } else if (status == 2) {
            if (beauty == 1) {
                if (cm.haveItem(5150032)) {
                    cm.gainItem(5150032, -1);
                    cm.setHair(hairnew[Math.floor(Math.random() * hairnew.length)]);
                    cm.sendOk("Enjoy your new and improved hairstyle!");
                } else {
                    cm.sendOk("Hmmm...it looks like you don't have our designated coupon...I'm afraid I can't give you a haircut without it. I'm sorry...");
                }
            }
            if (beauty == 2) {
                if (cm.haveItem(5151027)) {
                    cm.gainItem(5151027, -1);
                    cm.setHair(haircolor[Math.floor(Math.random() * haircolor.length)]);
                    cm.sendOk("Enjoy your new and improved haircolor!");
                } else {
                    cm.sendOk("Hmmm...it looks like you don't have our designated coupon...I'm afraid I can't dye your hair without it. I'm sorry...");
                }
            }
            cm.dispose();
        }
    }
}
