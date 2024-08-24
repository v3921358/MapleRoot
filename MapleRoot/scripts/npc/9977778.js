var status = 0;
var skills = [];
var jobs;
var c_job = 0;
var c_skill = 0;
var p_job = 0;
const GameConstants = Java.type('constants.game.GameConstants');
var jobOptions = "";

function start() {
    status = -1;
    action(1, 0, 0);
}

function action(mode, type, selection) {
    
    if (mode == -1) {
        cm.dispose();
        return;
    } else if (mode == 1) {
        status++;
    } else if (mode == 0 && status == 4) {
        cm.dispose();
        return;
    } else {
        cm.dispose();
        return;        
    }

    if (status == 0) {          
        cm.sendSimple("Hi #r#h #! #kWhat would you like to do today?\r\n#b#L0#Learn Previous Rebirth Skills#l");
        // cm.sendYesNo("Hey there! Do you want to learn some skills?");                       
    } else if (status == 1) {
        if(selection === 0){
            var message = "Please select a class:\r\n";   
            rebornDataString = cm.getChar().getAllRebornDataCerezeth(); // get rebirth data, check characters_rebirth table
            rebornData = JSON.parse(rebornDataString); // change it to json object
       
            if (rebornData.length == 0) {
                cm.sendOk("You have not rebirthed yet!");
                cm.dispose();
            } else {
                var counter = 0;
               
                for (var rbc = 0; rbc < rebornData.length; rbc++) {
                    jobOptions += `#L${counter}##b${GameConstants.getJobName(rebornData[rbc].job)}#l \r\n`;
                    counter++;
                }
            
                cm.sendSimple("I see... which job class? \r\n"  + jobOptions);
            }
        }
        else if(selection === 1){
            cm.teachSkill(4111006, 20, 20, -1)
            c_skill = 4111006, 20, 20; // 4111006 flash jump
            status = 4; //go to binding step
            cm.sendSimple("Which key do you want #e#r#q" + c_skill + "##n#k on? #b\r\n#L59#F1#L60#F2#L61#F3#L62#F4#L63#F5#L64#F6#L65#F7#L66#F8#L67#F9 \r\n #L68#F10#L87#F11#L88#F12 \r\n#L2#1#L3#2#L4#3#L5#4#L6#5#L7#6#L8#7#L9#8#L10#9#L11#0#L12#-#L13#= \r\n#L16#Q#L17#W#L18#E#L19#R#L20#T#L21#Y#L22#U#L23#I#L24#O#L25#P#L26#[#L27#] \r\n#L30#A#L31#S#L32#D#L33#F#L34#G#L35#H#L36#J#L37#K#L38#L#L39#;#L40#' \r\n#L42#Shift#L44#Z#L45#X#L46#C#L47#V#L48#B#L49#N#L50#M#L51#,#L52#.#L42#Shift \r\n#L29#Ctrl#L56#Alt#L57#SPACE#L56#Alt#L29#Ctrl \r\n#L82#Ins#L71#Hm#L73#Pup#L83#Del#L79#End#L81#Pdn");
        }
        // cm.sendSimple(message);
        // cm.sendSimple("Which key do you want #e#r#q" + c_skill + "##n#k on? #b\r\n" +
        //     "#L59#F1\r\n#L60#F2\r\n#L61#F3\r\n#L62#F4\r\n#L63#F5\r\n#L64#F6\r\n#L65#F7\r\n#L66#F8\r\n#L67#F9\r\n" +
        //     "#L68#F10\r\n#L87#F11\r\n#L88#F12\r\n" +
        //     "#L2#1\r\n#L3#2\r\n#L4#3\r\n#L5#4\r\n#L6#5\r\n#L7#6\r\n#L8#7\r\n#L9#8\r\n#L10#9\r\n#L11#0\r\n#L12#-\r\n#L13#=\r\n" +
        //     "#L16#Q\r\n#L17#W\r\n#L18#E\r\n#L19#R\r\n#L20#T\r\n#L21#Y\r\n#L22#U\r\n#L23#I\r\n#L24#O\r\n#L25#P\r\n#L26#[\r\n#L27#]\r\n" +
        //     "#L30#A\r\n#L31#S\r\n#L32#D\r\n#L33#F\r\n#L34#G\r\n#L35#H\r\n#L36#J\r\n#L37#K\r\n#L38#L\r\n#L39#;\r\n#L40#'\r\n" +
        //     "#L42#Shift\r\n#L44#Z\r\n#L45#X\r\n#L46#C\r\n#L47#V\r\n#L48#B\r\n#L49#N\r\n#L50#M\r\n#L51#,\r\n#L52#.\r\n#L42#Shift\r\n" +
        //     "#L29#Ctrl\r\n#L56#Alt\r\n#L57#SPACE\r\n#L56#Alt\r\n#L29#Ctrl\r\n#L82#Ins\r\n#L71#Hm\r\n#L73#Pup\r\n#L83#Del\r\n#L79#End\r\n#L81#Pdn");
        // }
    } else if (status == 2) {        
        if (mode == 1) c_job = rebornData[selection].job;
        else c_job = p_job;
        p_job = c_job;

        job_primary_id = roundDownToNearest100(c_job);      //example: turns 132, 122, 112 into 100
        job_sub_id = extractTensPlaceValue(c_job) * 10;     //example: turns 132, 122, 112 into 3, 2, 1 respectively | then multiplies by 10 to achieve 30, 20, 10

        var message = "" //empty message to build with
        //start at current job id (ie: 132)
        //value must stay above our job primary id(ie: 100)
        //decrement (i--) every iteration until we can no longer (ie: 132 -> 100)
        for (var i = c_job; i >= job_primary_id; i--) {

            //if we are above or equal to our primary id and sub id
            //(ie: 100 + 30 = 130 | 130, 131, 132)
            //OR
            //if we are equal to our job primary id (ie: 100, first job)
            //then we may execute
            if(i >= job_primary_id + job_sub_id || i == job_primary_id) {
                message += addJobSkillsToSelectionList(i, skills.length);
            }
        }

        cm.sendSimple(message);
    } else if (status == 3) {
        c_skill = skills[selection];
        cm.sendNextPrev("#s" + c_skill + "# #b#q" + c_skill + "##k\r\n\r\n" + cm.getSkillDesc(c_skill));
    } else if (status == 4) {
        cm.sendSimple("Which key do you want #e#r#q" + c_skill + "##n#k on? #b\r\n#L59#F1#L60#F2#L61#F3#L62#F4#L63#F5#L64#F6#L65#F7#L66#F8#L67#F9 \r\n #L68#F10#L87#F11#L88#F12 \r\n#L2#1#L3#2#L4#3#L5#4#L6#5#L7#6#L8#7#L9#8#L10#9#L11#0#L12#-#L13#= \r\n#L16#Q#L17#W#L18#E#L19#R#L20#T#L21#Y#L22#U#L23#I#L24#O#L25#P#L26#[#L27#] \r\n#L30#A#L31#S#L32#D#L33#F#L34#G#L35#H#L36#J#L37#K#L38#L#L39#;#L40#' \r\n#L42#Shift#L44#Z#L45#X#L46#C#L47#V#L48#B#L49#N#L50#M#L51#,#L52#.#L42#Shift \r\n#L29#Ctrl#L56#Alt#L57#SPACE#L56#Alt#L29#Ctrl \r\n#L82#Ins#L71#Hm#L73#Pup#L83#Del#L79#End#L81#Pdn");
    } else if (status == 5) {
        cm.sendOk("Enjoy your new skill!");
        cm.changeKeyBinding(selection, 1, c_skill);
        cm.dispose();
    } else {
        cm.sendOk("See you next time then.");
        cm.dispose();
    }
} 



function roundDownToNearest100(number) {
    //example output
    //112 hero
    //122 pally
    //132 dark-knight
    //outputs
    //100 primary job id

    //example output
    //1412 night walker >> 1400
    //1512 thunder breaker >> 1500

    //example output
    //2112 aran >> 2100
    return Math.floor(number / 100) * 100;
}

function extractTensPlaceValue(number) {
    //example output
    //112 hero >> 1
    //122 pally >> 2
    //132 dark-knight >> 3
    //output * 10 = 10, 20, 30

    //example output
    //1412 night walker >> 1
    //1512 thunder breaker >> 1

    //example output
    //2112 aran >> 1
    return Math.floor(number / 10) % 10;
}

function addJobSkillsToSelectionList(job_id) {
    var starting_index = skills.length;          //current skill count
    var curJobSkills = cm.getSkillsByJob(job_id) //current target job skills
    if(curJobSkills.length == 0) return "";      //if we have no skills return empty string(prettify)
    skills = [...skills, ...curJobSkills];       //concate current skills onto whole array

    //message to build with
    var message = ""
    //if we are above index 0, it is an additional list and should start two lines lower(prettify)
    if(starting_index > 0) message += "\r\n\r\n";
    //start message, black color | target job skill count, with job name | then set color blue for the skill entries
    message += "#k" + curJobSkills.length + " " + GameConstants.getJobName(job_id) + " Skills Available.\r\n#b";
    //add each skill entry from the main skill array
    for (var i = starting_index; i < skills.length; i++) {
        message += "#L" + i + "#"           //list entry
        message += "#s" + skills[i] + "#";  //icon
        message += " #q" + skills[i] + "#"; //name
        message += "#l\r\n"                 //close entry + return
    }
    
    return message;
}