/*
	This file is part of the OdinMS Maple Story Server
    Copyright (C) 2008 Patrick Huy <patrick.huy@frz.cc> 
                       Matthias Butz <matze@odinms.de>
                       Jan Christian Meyer <vimes@odinms.de>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License version 3
    as published by the Free Software Foundation. You may not use, modify
    or distribute this program under any other version of the
    GNU Affero General Public License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* Midori
	Showa Random Hair/Hair Color Change.

        GMS-like revised by Ronan -- contents found thanks to Mitsune (GamerBewbs), Waltzing, AyumiLove
*/
var status = 0;
var beauty = 0;
var hairprice = 1000000;
var haircolorprice = 1000000;
var mhair_r = Array(30260, 30280, 30340, 30360, 30710, 30780, 30790, 30800, 30810, 30820, 30920);
var fhair_r = Array(31350, 31410, 31460, 31540, 31550, 31710, 31720, 31770, 31790, 31800, 31850, 34000);
var hairnew = Array();

function pushIfItemExists(array, itemid) {
    if ((itemid = cm.getCosmeticItem(itemid)) != -1 && !cm.isCosmeticEquipped(itemid)) {
        array.push(itemid);
    }
}

function start() {
    status = -1;
    action(1, 0, 0);
}

function action(mode, type, selection) {
    if (mode < 1) {  // disposing issue with stylishs found thanks to Vcoc
        cm.dispose();
    } else {
        if (mode == 1) {
            status++;
        } else {
            status--;
        }
        if (status == 0) {
            cm.sendSimple("Hi, I'm the assistant here. Don't worry, I'm plenty good enough for this. If you have #b#t5150008##k or #b#t5151008##k by any chance, then allow me to take care of the rest, alright?\r\n#L1#Haircut: #i5150008##t5150008##l\r\n#L2#Dye your hair: #i5151008##t5151008##l");
        } else if (status == 1) {
            if (selection == 1) {
                beauty = 1;
                hairnew = Array();
                if (cm.getPlayer().getGender() == 0) {
                    for (var i = 0; i < mhair_r.length; i++) {
                        pushIfItemExists(hairnew, mhair_r[i] + parseInt(cm.getPlayer().getHair() % 10));
                    }
                }
                if (cm.getPlayer().getGender() == 1) {
                    for (var i = 0; i < fhair_r.length; i++) {
                        pushIfItemExists(hairnew, fhair_r[i] + parseInt(cm.getPlayer().getHair() % 10));
                    }
                }
                cm.sendYesNo("If you use the REG coupon your hair will change RANDOMLY with a chance to obtain a new experimental style that I came up with. Are you going to use #b#t5150008##k and really change your hairstyle?");
            } else if (selection == 2) {
                beauty = 2;
                haircolor = Array();
                var current = parseInt(cm.getPlayer().getHair() / 10) * 10;
                for (var i = 0; i < 8; i++) {
                    pushIfItemExists(haircolor, current + i);
                }
                cm.sendYesNo("If you use a regular coupon your hair will change RANDOMLY. Do you still want to use #b#t5151008##k and change it up?");
            }
        } else if (status == 2) {
            cm.dispose();
            if (beauty == 1) {
                if (cm.haveItem(5150008)) {
                    cm.gainItem(5150008, -1);
                    cm.setHair(hairnew[Math.floor(Math.random() * hairnew.length)]);
                    cm.sendOk("Enjoy your new and improved hairstyle!");
                } else {
                    cm.sendOk("Hmmm...it looks like you don't have our designated coupon...I'm afraid I can't give you a haircut without it. I'm sorry...");
                }
            } else if (beauty == 2) {
                if (cm.haveItem(5151008)) {
                    cm.gainItem(5151008, -1);
                    cm.setHair(haircolor[Math.floor(Math.random() * haircolor.length)]);
                    cm.sendOk("Enjoy your new and improved haircolor!");
                } else {
                    cm.sendOk("Hmmm...it looks like you don't have our designated coupon...I'm afraid I can't dye your hair without it. I'm sorry...");
                }
            } else if (beauty == 0) {
                if (selection == 0 && cm.getMeso() >= hairprice) {
                    cm.gainMeso(-hairprice);
                    cm.gainItem(5150008, 1);
                    cm.sendOk("Enjoy!");
                } else if (selection == 1 && cm.getMeso() >= haircolorprice) {
                    cm.gainMeso(-haircolorprice);
                    cm.gainItem(5151008, 1);
                    cm.sendOk("Enjoy!");
                } else {
                    cm.sendOk("You don't have enough mesos to buy a coupon!");
                }
            }
        }
    }
}
