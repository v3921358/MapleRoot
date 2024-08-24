
/* Tana
 * 
 * @Author Rulax, Tifa, Seeker1437
 * Helps players leave the map and logs weekly bosses
 * Tana
 */

const ExpeditionBossLog = Java.type("server.expeditions.ExpeditionBossLog");

var status;

function start() {
    status = -1;
    action(1, 0, 0)
}

function action(mode, type, selection) {
    if (mode < 1) {
        cm.dispose();
    } else {
        if (mode == 0) {
            cm.dispose();
            return;
        }

        if (mode == 1) {
            status++;
        } else {
            status--;
        }

        let eim = cm.getEventInstance();
        let mapId = cm.getMapId();
        let warpToMapId = getWarpToMapId(mapId);

        if (warpToMapId !== 0) {
            if (eim === null) {
                cm.sendYesNo("How did you even get in here without starting the expedition? Do you want to leave?");
            } else if (!eim.isEventCleared()) {
                cm.sendYesNo("If you leave now, you'll have to start over. \r\n\r\n" +
                cm.getEventInstance().sendDmgDealt(cm.getPlayer().getWorld()) +
                "Are you sure you want to leave?");
            } else {
                cm.sendYesNo("You guys finally overthrew such darkness! What a superb feat! Congratulations! \r\n\r\n" +
                cm.getEventInstance().sendDmgDealt(cm.getPlayer().getWorld()) +
                "Are you sure you want to leave now?");
            }
        } else {
            cm.sendYesNo("If you leave now, you'll have to start over. Are you sure you want to leave?");
        }

        if (status == 1) {
            if (eim.isEventCleared()){
            let rewarded = eim.getProperty("rewarded") == "true";

            const players = eim.getPlayers();

            // Add item rewards based on the map or other conditions
            switch (mapId) {
                case 280030000: //ZAKUM
                    if (!rewarded) {
                        players.forEach((chr, index) => {
                            const playerInteraction = chr.getAbstractPlayerInteraction();
                            chr.getClient().getWorldServer().removeUnclaimed(ExpeditionBossLog.BossLogEntry.ZAKUM, chr.getId());

                            playerInteraction.gainItem(4032133, 1);
                            playerInteraction.gainItem(2000005, 1000);
                        })

                        eim.setProperty("rewarded", "true");
                    }
                    break;
                case 240060200: //HORNTAIL
                    if (!rewarded) {
                        players.forEach((chr, index) => {
                            const playerInteraction = chr.getAbstractPlayerInteraction();
                            chr.getClient().getWorldServer().removeUnclaimed(ExpeditionBossLog.BossLogEntry.HORNTAIL, chr.getId());

                            playerInteraction.gainItem(4001094, 1);
                            playerInteraction.gainItem(2022179, 1);
                            playerInteraction.gainItem(2000005, 1000);
                        })

                        eim.setProperty("rewarded", "true");
                    }
                    break;
                case 211070100:  //VON LEON
                    if (!rewarded) {
                        players.forEach((chr, index) => {
                            const playerInteraction = chr.getAbstractPlayerInteraction();
                            chr.getClient().getWorldServer().removeUnclaimed(ExpeditionBossLog.BossLogEntry.VONLEON, chr.getId());

                            playerInteraction.gainItem(2022282, 1);
                            playerInteraction.gainItem(2022179, 2);
                            playerInteraction.gainItem(4001693, 1);
                            playerInteraction.gainItem(2000005, 1000);
                        })

                        
                        eim.setProperty("rewarded", "true");
                    }
                    break; 
                case 271040100: //CYGNUS
                    if (!rewarded) {
                        players.forEach((chr, index) => {
                            const playerInteraction = chr.getAbstractPlayerInteraction();
                            chr.getClient().getWorldServer().removeUnclaimed(ExpeditionBossLog.BossLogEntry.CYGNUS, chr.getId());

                            playerInteraction.gainItem(2022282, 8);
                            playerInteraction.gainItem(2022179, 25);
                            playerInteraction.gainItem(2000005, 1000);
                        })

                        eim.setProperty("rewarded", "true");
                    }
                    break;

                    case 450007440: //WILL 
                    if (!rewarded) {
                        players.forEach((chr, index) => {
                            const playerInteraction = chr.getAbstractPlayerInteraction();
                            chr.getClient().getWorldServer().removeUnclaimed(ExpeditionBossLog.BossLogEntry.WILL, chr.getId());

                            playerInteraction.gainItem(4021033, 30);
                            playerInteraction.gainItem(4021034, 15);
                            playerInteraction.gainItem(4021035, 5);
                            playerInteraction.gainItem(2022282, 5);
                            playerInteraction.gainItem(2022179, 25);
                            playerInteraction.gainItem(2000005, 1000);
                        })

                        eim.setProperty("rewarded", "true");
                    }

                    break;
                    case 450010100: //VERUS
                    if (!rewarded) {
                        players.forEach((chr, index) => {
                            const playerInteraction = chr.getAbstractPlayerInteraction();
                            chr.getClient().getWorldServer().removeUnclaimed(ExpeditionBossLog.BossLogEntry.VERUS, chr.getId());

                            playerInteraction.gainItem(4021033, 30);
                            playerInteraction.gainItem(4021034, 15);
                            playerInteraction.gainItem(4021035, 5);
                            playerInteraction.gainItem(2022282, 5);
                            playerInteraction.gainItem(2022179, 25);
                            playerInteraction.gainItem(2000005, 1000);
                        })

                        eim.setProperty("rewarded", "true");
                    }
                    break;

                    case 450012210: //DARKNELL
                    if (!rewarded) {
                        players.forEach((chr, index) => {
                            const playerInteraction = chr.getAbstractPlayerInteraction();
                            chr.getClient().getWorldServer().removeUnclaimed(ExpeditionBossLog.BossLogEntry.DARKNELL, chr.getId());

                            playerInteraction.gainItem(4021033, 30);
                            playerInteraction.gainItem(4021034, 15);
                            playerInteraction.gainItem(4021035, 5);
                            playerInteraction.gainItem(2022282, 5);
                            playerInteraction.gainItem(2022179, 25);
                            playerInteraction.gainItem(2000005, 1000);
                        })

                        eim.setProperty("rewarded", "true");
                    }
                    break;

                    case 450004750: //LUCID
                    if (!rewarded) {
                        players.forEach((chr, index) => {
                            const playerInteraction = chr.getAbstractPlayerInteraction();
                            chr.getClient().getWorldServer().removeUnclaimed(ExpeditionBossLog.BossLogEntry.LUCID, chr.getId());

                            playerInteraction.gainItem(4021033, 30);
                            playerInteraction.gainItem(4021034, 15);
                            playerInteraction.gainItem(4021035, 5);
                            playerInteraction.gainItem(2022282, 5);
                            playerInteraction.gainItem(2022179, 25);
                            playerInteraction.gainItem(2000005, 1000);
                        })

                        eim.setProperty("rewarded", "true");
                    }
                    break;
            }
            
        }else {
            cm.dispose();
        }
            cm.warp(warpToMapId);
        }
    }
}

function getWarpToMapId(mapId) {
    let warpToMapId;

    switch (mapId) {
        case 280030000:
            warpToMapId = 211042400; //ZAKUM
            break;
        case 240060200:
            warpToMapId = 240050600; //HORNTAIL
            break;
        case 450007440:
            warpToMapId = 450007240; //WILL
            break;
        case 450012210:
            warpToMapId = 450012200; //DARKNELL
            break;
        case 450010100:
            warpToMapId = 450011500; //VERUS
            break;
        case 541020800:
            warpToMapId = 541020700; //KREXEL
            break;
        case 211070100:
            warpToMapId = 211070000; //VON LEON
            break;
        case 271040100:
            warpToMapId = 271040000; //CYGNUS
            break;
        case 800040410:
            warpToMapId = 800040401; //CASTELLAN
            break;
        case 450004750:
            warpToMapId = 450003600; //LUCID
            break;
        // Add more cases for other map IDs as needed
        default:
            warpToMapId = 0; // Default warp destination if the map ID is not handled
    }

    return warpToMapId;
}