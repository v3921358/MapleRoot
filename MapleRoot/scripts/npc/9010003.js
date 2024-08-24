/*
* Job Master
* ID: 9010003
*/

let depression;
let jobs = [];
let level = 0;
let job;

function start() {
    level = cm.getPlayer().getLevel();
    depression = 0;

    if (cm.getJobId() === 700) {
        cm.sendOk("You're now a Super Beginner.");
        cm.dispose();
        return;
    }

    if (cm.getPlayer().getSkillLevel(1051) !== 0) {
        if (level < 200) {
            cm.sendOk("Come back when you're good, kiddo.");
        } else {
            cm.changeJobById(700);
            cm.teachSkill(1051, -1, 1, -1);   // Chain Attack 2
            cm.teachSkill(1052, -1, 1, -1);   // Chain Attack
        }
        cm.dispose();
        return;
    }

    if (jobs.length === 0) {
        fillJobs();
    }

    if (jobs.length === 0) {
        cm.sendOk("You are not eligible for a new job.");
        cm.dispose();
        return;
    }

    let str = "Choose your Job:#b";
    for (let i = 0; i < jobs.length; i++) {
        str += `\r\n#L${i}#${cm.getJobName(jobs[i])}#l`;
    }

    cm.sendSimple(str);
}

function action(m, t, s) {
    if (cm.isEndChat(m, t)) {
        cm.sendOk("The end, you're dead.");
        cm.dispose();
        return;
    }
    depression++;

    if (depression === 1) {
        job = jobs[s];
        cm.sendYesNo(`Are you sure you want job advance to a (#r${cm.getJobName(jobs[s])}#k)?`);
    } else if (depression === 2) {
        if (m === 0) { // no
            start();
        } else { // yes
            jobAdvance();
            cm.dispose();
        }
    }
}

function jobAdvance() {
    if (job !== 700) {
        cm.changeJobById(job);
    }
    giveRewards();
}

function giveRewards() {
    // everyone gets these depressions
    if (job === 0 || job === 1000 || job === 2000) return;
    cm.gainItem(2000005, 50); // Power Elixirs

    // job specific depressions
    switch (job) {
        case 100: // both 100 and 1100
        case 1100:
            cm.gainItem(1302077, 1);
            break;
        case 700:
            cm.gainItem(1302024, 1);
            cm.gainItem(1040014, 1);
            cm.gainItem(1002419, 1);
            cm.gainItem(1060004, 1);
            cm.gainItem(1072368, 1);
            cm.gainItem(1082245, 1);
            cm.gainItem(1102174, 1);
            cm.gainItem(1092003, 1);
            cm.teachSkill(1051, 1, 1, -1);   // Chain Attack 2
            cm.teachSkill(1052, 1, 1, -1);   // Chain Attack
            cm.sendOk("You're on the right path now.");
            break;
        case 2100:
            // Teach skills after advancing to job ID 2100
            cm.teachSkill(21000000, 0, 10, -1);   // Combo Ability
            cm.teachSkill(21110002, 0, 20, -1);   // Full Swing
            cm.teachSkill(21100000, 0, 20, -1);   // Polearm Mastery
            cm.teachSkill(21100002, 0, 30, -1);   // Final Charge
            cm.teachSkill(21100004, 0, 20, -1);   // Combo Smash
            cm.teachSkill(21100005, 0, 20, -1);   // Combo Drain
            break;
        case 200:
        case 1200:
                // Job advancement from 1000 to 1200
            cm.gainItem(1372043, 1); // First item ID and quantity
            cm.gainItem(1382100, 1); // Second item ID and quantity
            break;
        case 232:
                // BAHAMUT SKILL AT LEVEL 30 FOR BISHOP
            cm.teachSkill(2321003, 0, 30, -1);   // BAHAMUT
            break;     
        case 300:
        case 1300:  
            cm.gainItem(1452051, 1); // First item ID and quantity
            cm.gainItem(1462092, 1); // Second item ID and quantity
            cm.gainItem(2060000, 999); // Third item ID and quantity
            cm.gainItem(2061000, 999); // Fourth item ID and quantity
            break;   
        case 400:
        case 1400:  
            cm.gainItem(1472061, 1); // Item ID and quantity
            cm.gainItem(1332063, 1); // Second ID and quantity
            cm.gainItem(2070015, 999); // Third item ID and quantity
            break;
        case 500:
        case 1500:
            cm.gainItem(1492014, 1); // Item ID and quantity
            cm.gainItem(1482063, 1); // Second ID and quantity
            cm.gainItem(2330000, 999); // Third item ID and quantity
        break;
        case 1411:
        case 411:
            cm.teachSkill(4111002, 30, 30, -1);   // Shadow Partner
            cm.teachSkill(14111000, 30, 30, -1);   // Shadow Partner
        break;

    }
}

function fillJobs() {
    const currentJobId = cm.getJobId();

    if (level === 1) {
        jobs.push(...[0, 1000, 2000]);
        return;
    }

    // Allow 4th job only if level is 120 is job id nod 10 is equal to 1
    if (level >= 120 && (currentJobId % 10) === 1) {
        jobs.push(currentJobId + 1);
        return;
    }

    // 3rd job
    if (level >= 70 && (currentJobId % 100) % 10 === 0 && !cm.getPlayer().isBeginnerJob() && currentJobId % 100 !== 0) {
        jobs.push(currentJobId + 1);
        return;
    }

    // 2nd job
    if (!cm.getPlayer().isBeginnerJob() && level >= 30 && currentJobId % 100 === 0) {
        switch (currentJobId) {
            case 100:
                jobs.push(...[110, 120, 130]);
                break;
            case 200:
                jobs.push(...[210, 220, 230]);
                break;
            case 300:
                jobs.push(...[310, 320]);
                break;
            case 400:
                jobs.push(...[410, 420]);
                break;
            case 500:
                jobs.push(...[510, 520]);
                break;
            case 1100:
                jobs.push(1110);
                break;
            case 1200:
                jobs.push(1210);
                break;
            case 1300:
                jobs.push(1310);
                break;
            case 1400:
                jobs.push(1410);
                break;
            case 1500:
                jobs.push(1510);
                break;
            case 2100:
                jobs.push(2110);
                break;
        }
        return;
    }

    // first job beginner
    if (currentJobId === 0 && level >= 8) {
        jobs.push(200);
        if (level >= 10) {
            jobs.push(...[100, 300, 400, 500, 700]);
        }
        return;
    }

    // first job cygnus
    if (currentJobId === 1000 && level >= 10) {
        jobs.push(...[1100, 1200, 1300, 1400, 1500]);
        return;
    }

    // first job aran
    if (currentJobId === 2000 && level >= 10) {
        jobs.push(2100);
        return;
    }
}