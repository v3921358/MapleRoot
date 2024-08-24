/*  Von Leon (boss spawner)
    Audience room (211070100)
    Talkable NPC that spawns the boss.
 */

    var status;
    const ExpeditionType = Java.type('server.expeditions.ExpeditionType');
    var exped = ExpeditionType.CYGNUS;

    function start() {
            status = -1;
            action(1, 0, 0);
    }
    
    function action(mode, type, selection) {
            if (mode == -1) {
                    cm.dispose();
            } else {
                    if (mode == 0 && type > 0) {
                            cm.dispose();
                            return;
                    }
                    if (mode == 1)
                            status++;
                    else
                            status--;
    
                    if(status == 0) {
                        expedition = cm.getExpedition(exped);
                        if (expedition.isLeader(cm.getPlayer())) {
                            cm.sendYesNo("Dark energy emanates from her, are you sure you want to disturb her sleep?");
                        }
                    } else if (status == 1) {
                            cm.getMap().spawnMonsterOnGroundBelow(8850011, -104, 115);
                            cm.getMap().destroyNPC(3003903);
                            cm.getMap().killMonster(8840010);
                            cm.dispose();
                    }
    
            }
    }