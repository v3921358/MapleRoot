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
/**
 -- Odin JavaScript --------------------------------------------------------------------------------
 King Sage Cat Spawner
 -- Edited by --------------------------------------------------------------------------------------
 ThreeStep - based on xQuasar's King Clang spawner

 **/

function init() {
    scheduleNew();
}

function scheduleNew() {
    setupTask = em.schedule("start", 0);    //spawns upon server start. Each 3 hours an server event checks if boss exists, if not spawns it instantly.
}

function cancelSchedule() {
    if (setupTask != null) {
        setupTask.cancel(true);
    }
}

function start() {
    var goblinForest2 = em.getChannelServer().getMapFactory().getMap(250010504);
    const LifeFactory = Java.type('server.life.LifeFactory');
    var kingSageCat = LifeFactory.getMonster(7220002);

    if (goblinForest2.getMonsterById(7220002) != null) {
        em.schedule("start", 3 * 60 * 60 * 1000);
        return;
    }
    var posX;
    var posY = 540;
    posX = Math.floor((Math.random() * 1300) - 500);
    const Point = Java.type('java.awt.Point');
    const spawnpoint = new Point(posX, posY);
    goblinForest2.spawnMonsterOnGroundBelow(kingSageCat, spawnpoint);

    const PacketCreator = Java.type('tools.PacketCreator');
    goblinForest2.broadcastMessage(PacketCreator.serverNotice(6, "The ghostly air around here has become stronger. The unpleasant sound of a cat crying can be heard."));
    em.schedule("start", 3 * 60 * 60 * 1000);
}

// ---------- FILLER FUNCTIONS ----------

function dispose() {}

function setup(eim, leaderid) {}

function monsterValue(eim, mobid) {return 0;}

function disbandParty(eim, player) {}

function playerDisconnected(eim, player) {}

function playerEntry(eim, player) {}

function monsterKilled(mob, eim) {}

function scheduledTimeout(eim) {}

function afterSetup(eim) {}

function changedLeader(eim, leader) {}

function playerExit(eim, player) {}

function leftParty(eim, player) {}

function clearPQ(eim) {}

function allMonstersDead(eim) {}

function playerUnregistered(eim, player) {}

