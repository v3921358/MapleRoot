function start(ms) {
    if (ms.getMapId() == 108010101) { // Archer
        spawnMob(188, 20, 9001002, ms.getPlayer().getMap());
    } else if (ms.getMapId() == 108010301) { // Warrior
        spawnMob(188, 20, 9001000, ms.getPlayer().getMap());
    } else if (ms.getMapId() == 108010201) { // Mage
        spawnMob(188, 20, 9001001, ms.getPlayer().getMap());
    } else if (ms.getMapId() == 108010401) { // Thief
        spawnMob(188, 20, 9001003, ms.getPlayer().getMap());
    } else if (ms.getMapId() == 108010501) { // Pirate
        spawnMob(188, 20, 9001008, ms.getPlayer().getMap());
    }
}

function spawnMob(x, y, id, map) {
    if (map.getMonsterById(id) != null) {
        return;
    }

    const LifeFactory = Java.type('server.life.LifeFactory');
    const Point = Java.type('java.awt.Point');
    var mob = LifeFactory.getMonster(id);
    map.spawnMonsterOnGroundBelow(mob, new Point(x, y));
}