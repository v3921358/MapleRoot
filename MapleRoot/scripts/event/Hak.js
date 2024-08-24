var returnTo = [200000141, 250000100];
var rideTo = [250000100, 200000141];
var birdRide = [200090300, 200090310];
var myRide;
var returnMap;
var exitMap;
var map;
var onRide;

//Time Setting is in millisecond
var rideTime = 60 * 1000;

function init() {
    rideTime = em.getTransportationTime(rideTime);
}

function setup(level, lobbyid) {
    var eim = em.newInstance("Hak_" + lobbyid);
    return eim;
}

function afterSetup(eim) {}

function playerEntry(eim, player) {
    if (player.getMapId() == returnTo[0]) {
        myRide = 0;
    } else {
        myRide = 1;
    }
    exitMap = eim.getEm().getChannelServer().getMapFactory().getMap(rideTo[myRide]);
    returnMap = eim.getMapFactory().getMap(returnTo[myRide]);
    onRide = eim.getMapFactory().getMap(birdRide[myRide]);
    player.changeMap(onRide, onRide.getPortal(0));

    const PacketCreator = Java.type('tools.PacketCreator');
    player.sendPacket(PacketCreator.getClock(rideTime / 1000));
    eim.schedule("timeOut", rideTime);
}

function timeOut(eim) {
    end(eim);
}

function playerUnregistered(eim, player) {}

function playerExit(eim, player, success) {
    eim.unregisterPlayer(player);
    player.changeMap(success ? exitMap.getId() : returnMap.getId(), 0);
}

function end(eim) {
    var party = eim.getPlayers();
    for (var i = 0; i < party.size(); i++) {
        playerExit(eim, party.get(i), true);
    }
    eim.dispose();
}

function playerDisconnected(eim, player) {
    playerExit(eim, player, false);
}

function cancelSchedule() {}

function dispose(eim) {}


// ---------- FILLER FUNCTIONS ----------

function monsterValue(eim, mobid) {return 0;}

function disbandParty(eim, player) {}

function monsterKilled(mob, eim) {}

function scheduledTimeout(eim) {}

function changedLeader(eim, leader) {}

function leftParty(eim, player) {}

function clearPQ(eim) {}

function allMonstersDead(eim) {}

