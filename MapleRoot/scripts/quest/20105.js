/*
 * Cygnus 1st Job advancement - Thunder Breaker
 */

var status = -1;
var jobType = 5;
var canTryFirstJob = true;

function end(mode, type, selection) {
    if (mode == 0) {
        if (status == 0) {
            qm.sendNext("This is an important decision to make.");
            qm.dispose();
            return;
        }
        status--;
    } else {
        status++;
    }
    if (status == 0) {
        qm.sendYesNo("Have you made your decision? The decision will be final, so think carefully before deciding what to do. Are you sure you want to become a Thunder Breaker?");
    } else if (status == 1) {
        if (canTryFirstJob) {
            canTryFirstJob = false;
            if (qm.getPlayer().getJob().getId() != 1500) {
                if (!qm.canGetFirstJob(jobType)) {
                    qm.sendOk("Train a bit more until you reach #blevel 10, " + qm.getFirstJobStatRequirement(jobType) + "#k and I can show you the way of the #rThunder Breaker#k.");
                    qm.dispose();
                    return;
                }

                if (!(qm.canHoldAll([1482014, 1142066]))) {
                    qm.sendOk("Make some room in your inventory and talk back to me.");
                    qm.dispose();
                    return;
                }

                qm.gainItem(1482014, 1);
                qm.gainItem(1142066, 1);
                const Job = Java.type('client.Job');
                qm.getPlayer().changeJob(Job.THUNDERBREAKER1);
                qm.getPlayer().resetStats();
            }
            qm.forceCompleteQuest();
        }
        qm.sendNext("I have just molded your body to make it perfect for a Thunder Breaker. If you wish to become more powerful, use Stat Window (S) to raise the appropriate stats. If you aren't sure what to raise, just click on #bAuto#k.");
    } else if (status == 2) {
        qm.sendNextPrev("I have also expanded your inventory slot counts for your equipment and etc. inventory. Use those slots wisely and fill them up with items required for Knights to carry.");
    } else if (status == 3) {
        qm.sendNextPrev("I have also given you a hint of #bSP#k, so open the #bSkill Menu#k to acquire new skills. Of course, you can't raise them at all once, and there are some skills out there where you won't be able to acquire them unless you master the basic skills first.");
    } else if (status == 4) {
        qm.sendNextPrev("Unlike your time as a Noblesse, once you become the Thunder Breaker, you will lost a portion of your EXP when you run out of HP, okay?");
    } else if (status == 5) {
        qm.sendNextPrev("Now... I want you to go out there and show the world how the Knights of Cygnus operate.");
    } else if (status == 6) {
        qm.dispose();
    }
}