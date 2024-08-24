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
	Author : Ronan Lana
*/
var status = -1;

function start(mode, type, selection) {
    if (mode == -1) {
        qm.dispose();
        return;
    } else if (status >= 2 && mode == 0) {
        qm.dispose();
        return;
    }

    if (mode == 1) {
        status++;
    } else {
        status--;
    }

    if (status == 0) {
        qm.sendNext("The riding for Knights are a bit different from the rides available for regular folks. The takes place through a creature that is of the Mimi race that can be found on this island; they are called #bMimianas#k. Instead of riding monsters, the Knights ride Mimiana. There's one thing that you should never, ever forget.");
    } else if (status == 1) {
        qm.sendNextPrev("Dont't think of this as just a form of mount or transportation. These mounts can be your friend, your comrade, your colleague... all of the above. Even a friend close enough to entrust your life! That's why the Knights of Ereve actually grow their own mounts.");
    } else if (status == 2) {
        qm.sendAcceptDecline("Now, here's a Mimiana egg. Are you ready to raise a Mimiana and have it as your traveling companion for the rest of its life?");
    } else if (status == 3) {
        if (!qm.haveItem(4220137) && !qm.canHold(4220137)) {
            qm.sendOk("Make up a room on your ETC tab so I can give you the Mimiana egg.");
            qm.dispose();
            return;
        }

        qm.forceStartQuest();
        if (!qm.haveItem(4220137)) {
            qm.gainItem(4220137);
        }
        qm.sendOk("Mimiana's egg can be raised by #bsharing your daily experiences with it#k. Once Mimiana fully grows up, please come see me.");
    } else if (status == 4) {
        qm.dispose();
    }
}

function end(mode, type, selection) {
    if (mode != 1) {
        qm.dispose();
        return;
    }

    status++;
    if (status == 0) {
        qm.sendNext("Hey there! How's Mimiana's egg?");
    } else if (status == 1) {   //pretty sure there would need to have an egg EXP condition... Whatever.
        if (!qm.haveItem(4220137)) {
            qm.sendOk("I see, you lost your egg... You need to be more careful when raising a baby Mimiana!");
            return;
        }

        qm.forceCompleteQuest();
        qm.gainItem(4220137, -1);
        qm.gainExp(37600);
        qm.sendOk("Oh, were you able to awaken Mimiana Egg? That's amazing... Most knights can't even dream of awakening it in such a short amount of time.");
    } else if (status == 2) {
        qm.dispose();
    }
}

