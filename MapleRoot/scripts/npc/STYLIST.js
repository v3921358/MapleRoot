var status = 0;
var Page = 0;
var selected=-1;
var skin = [0, 1, 2, 3, 4, 5, 9, 10, 11];


var maleHair = [
    33000, 33010, 33020, 33030, 33040, 33050, 33060, 33070, 33080, 33090, 33100, 33110, 33120, 33130, 
    33140, 33150, 33160, 33170, 33180, 33190, 33210, 33220, 33240, 33250, 33260, 33270, 33280, 33290, 
    33310, 33320, 33330, 33340, 33350, 33360, 33370, 33380, 33390, 33400, 33410, 33430, 33440, 33450,
     33460, 33470, 33480, 33500, 33510, 33520, 33530, 33540, 33550, 33580, 33590, 33600, 33610, 33620,
      33630, 33640, 33660, 33670, 33680, 33690, 33700, 33710, 33720, 33730, 33740, 33750, 33760, 33770,
       33780, 33790, 33800, 33810, 33820, 33830, 33930, 33940, 33950, 33960, 33990, 34000, 34010, 34020,
        34030, 34040, 34050, 34060, 34070, 34080, 34090, 34100, 34110, 34120, 34130, 34140, 34150, 34160,
         34170, 34180, 34190, 34210, 34220, 34230, 34240, 34250, 34260, 34270, 34290, 34310, 34320, 34330,
          34340, 34350, 34360, 34370, 34380, 34400, 34410, 34420, 34430, 34440, 34450, 34470, 34480, 34490,
           34510, 34540, 34560, 34580, 34590, 34600, 34610, 34620, 34630, 34640, 34650, 34660, 34670, 34680,
            34690, 34700, 34710, 34720, 34730, 34740, 34750, 34760, 34770, 34780, 34790, 34800, 34810, 34820,
             34830, 34840, 34850, 34860, 34870, 34880, 34890, 34900, 34910, 34940, 34950, 34960, 34970, 34980,
              35000, 35010, 35020, 35040, 35050, 35060, 35070, 35080, 35090, 35100, 35110, 35120, 35130, 35140,
               35150, 35160, 35170, 35180, 35190, 35200, 35210, 35220, 35240, 35260, 35280, 35290, 35300, 35310,
                35330, 35340, 35350, 35360, 35420, 35430, 35440, 35450, 35460, 35470, 35490, 35500, 35510, 35520,
                 35530, 35550, 35590, 35620, 35640, 35650, 35660, 35680, 35690, 35720, 35740, 35760, 35790, 35950,
            35960, 35980, 35990, 36000, 36010, 36020, 36030, 36040, 36050, 36060, 36070, 36080, 36090, 36100, 36110, 
             36130, 36140, 36150, 36160, 36170, 36180, 36190, 36200, 36210, 36220, 36230, 36240, 36250, 36260, 36270, 
             36280, 36300, 36310, 36320, 36330, 36340, 36350, 36380, 36390, 36400, 36410, 36420, 36450, 36460, 36470, 
             36480, 36490, 36500, 36510, 36520, 36530, 36560, 36570, 36590, 36600, 36610, 36630, 36640, 36650, 36670, 
             36680, 36690, 36700, 36720, 36740, 36750, 36760, 36770, 36780, 36790, 36800, 36810, 36820, 36830, 36840, 
             36850, 36860, 36870, 36880, 36890, 36900, 36910, 36920, 36930, 36940, 36950, 36960, 36980, 37000, 37010, 
             37020, 37030, 37040, 37050, 37060, 37070, 37080, 37090, 37100, 37110, 37120, 37130, 37140, 37150, 37160, 
             37170, 37190, 37200, 37210, 37220, 37230, 37240, 37250, 37260, 37270, 37300, 37310, 37320, 37330, 37340, 
             37350, 37370, 37380, 37400, 37420, 37440, 37450, 37460, 37470, 37490, 37500, 37510, 37520, 37530, 37560, 
             37570, 37580, 37590, 37600, 37610, 37640, 37670, 37690, 37700, 37710, 37720, 37750, 37800, 37810, 
             37820, 37830, 37840, 37850, 37860, 37880, 37900, 37920, 37930, 37940, 37950, 37960, 37980, 37990, 38010, 
             38020, 38070, 38090, 38100, 38120, 38140, 38150, 38240, 38270, 38280, 38290, 38310, 38320, 38330, 38350, 
             38380, 38390, 38400, 38410, 38420, 38440, 38450, 38460, 38470, 38480, 38490, 38510, 38540, 38560, 38570, 
             38580, 38590, 38610, 38660, 38670, 38680, 38690, 38730, 38740, 38750, 38760, 38770, 38780, 38790, 38800, 
             38810, 38840, 38860, 38880, 38890, 38900, 38930, 39260, 39340, 40000, 40010, 40020, 40030, 40040, 40050, 
             40060, 40070, 40080, 40090, 40100, 40110, 40120, 40260, 40270, 40280, 40290, 40300, 40310, 40320, 40350, 
             40360, 40370, 40390, 40400, 40410, 40420, 40440, 40450, 40460, 40470, 40480, 40490, 40500, 40510, 40530];

var femaleHair = [];

var SelectedChange ;

var maleFace = 
[
    20000, 20001, 20002, 20003, 20004, 20005, 20006, 20007, 20008, 20009, 20010, 20011, 20012, 20013, 20014, 20015, 20016, 20017, 20018, 20019, 20020, 20021, 20022, 20023, 20024, 20025, 20026, 20027, 20028, 20029, 20030, 20031, 20032, 20033, 20035, 20036, 20037, 20038, 20040, 20043, 20044, 20045, 20046, 20047, 20048, 20049, 20050, 20051, 20052, 20053, 20054, 20055, 20056, 20057, 20058, 20059, 20060, 20061, 20062, 20063, 20064, 20065, 20066, 20067, 20068, 20069, 20070, 20071, 20072, 20073, 20074, 20075, 20076, 20077, 20078, 20079, 20080, 20081, 20082, 20083, 20084, 20085, 20086, 20087, 20088, 20090, 20091, 20092, 20093, 20094, 20095, 20097, 20098, 20099, 23000, 23001, 23002, 23005, 23006, 23007, 23008, 23009, 23010, 23012, 23013, 23014, 23016, 23017, 23018, 23019, 23020, 23023, 23025, 23031, 23033, 23034, 23035, 23038, 23039, 23040, 23041, 23042, 23044, 23053, 23055, 23056, 23059, 23065, 23067, 23068, 23070, 23072, 23073, 23074, 23075, 23076, 23079, 23080, 23081, 23083, 23084, 23085, 23086, 23087, 23088, 23089, 23090, 23092, 23094, 23095, 23096, 23097, 23099, 23100, 25006, 25011, 25017, 25021, 25023, 25025, 25027, 25030, 25031, 25032, 25033, 25034, 25043, 25049, 25050, 25057, 25060, 25079, 25084, 25085, 25089, 25090, 25093, 25097, 27007, 27008, 27017, 27019, 27022, 27025, 27035, 27036, 27037, 27038, 27040, 27041, 27044, 27051, 27052, 27053, 27055, 27064, 27065, 27066, 27067, 27068, 27069, 27070, 27071, 27073, 27074, 27075, 27076, 27078, 27079, 27080, 27085, 27086, 27087, 27090, 27092, 27095, 27096];

var femaleFace = [
    21000, 21001, 21002, 21003, 21004, 21005, 21006, 21007, 21008, 21009, 21010, 21011, 21012, 21013, 21014, 21015, 21016, 21017, 21018, 21019, 21020, 21021, 21022, 21023, 21024, 21025, 21026, 21027, 21028, 21029, 21030, 21031, 21033, 21034, 21035, 21036, 21037, 21038, 21041, 21042, 21043, 21044, 21045, 21046, 21047, 21048, 21049, 21052, 21053, 21054, 21055, 21056, 21057, 21058, 21059, 21060, 21061, 21062, 21063, 21064, 21065, 21066, 21067, 21068, 21069, 21070, 21071, 21072, 21073, 21074, 21075, 21076, 21077, 21078, 21080, 21081, 21082, 21083, 21084, 21085, 21087, 21088, 21089, 21091, 21092, 21093, 21094, 21095, 21096, 21097, 21098, 21100, 24001, 24002, 24003, 24004, 24007, 24008, 24009, 24010, 24013, 24014, 24016, 24019, 24020, 24022, 24028, 24031, 24032, 24036, 24037, 24038, 24039, 24040, 24041, 24050, 24051, 24052, 24053, 24054, 24055, 24057, 24058, 24059, 24060, 24061, 24063, 24066, 24067, 24068, 24071, 24072, 24073, 24075, 24077, 24078, 24079, 24081, 24082, 24083, 24084, 24085, 24086, 24087, 24091, 24092, 24093, 24094, 24095, 24097, 26003, 26011, 26023, 26026, 26027, 26029, 26031, 26032, 26035, 26036, 26037, 26041, 26046, 26053, 26054, 26057, 26061, 26062, 26064, 26078, 26085, 26091, 26095, 26096, 26099, 28001, 28008, 28010, 28011, 28012, 28014, 28020, 28023, 28027, 28030, 28041, 28042, 28043, 28044, 28045, 28046, 28050, 28056, 28057, 28058, 28060, 28070, 28071, 28072, 28073, 28074, 28075, 28076, 28078, 28079, 28080, 28081, 28082, 28083, 28084, 28085, 28087, 28089, 28091, 28094, 28096, 28097
];

var specialFace = new Array(25001, 25003, 25004, 25006, 25007, 25009, 25010, 25011, 25012, 25013, 26000, 26001, 26005, 26006, 26007, 26009, 26010, 26011, 26012, 26013, 26014, 20871, 21900, 22000, 22200, 22300, 22400, 22500, 22600, 22700, 22800, 23058);
var hairsPerPage=24;
var facesPerPage=70;
var MaleHairPages;
var FemaleHairPages;
var MaleFacePages;
var FemaleFacePages;
var haircolor;
var eyecolors;
var SearchHairPages;
var SearchFacePages;
var totalPages;
function start() {
	status = -1;
    action(1, 0, 0);
}

function action(mode, type, selection) {
	if(status==2 &&selection== -1){
		status-=2;
		mode=1;
	}
	status++;
    if (mode != 1){
        cm.dispose();
        return;
    }
	if(((status ==3 && cm.getText()!=null)||status ==2) && selected > 2 && selection <1000 && selection >= 0){
		Page=selection;
		status--;
	}
	if(selection==1000){
		Page--;
		status--;
	}else if(selection==2000){
		Page++;
		status--;
	}
	if (status==0){
		MaleHairPages=Math.floor(maleHair.length/hairsPerPage)+(maleHair.length%hairsPerPage==0?0:1);
		FemaleHairPages=Math.floor(femaleHair.length/hairsPerPage)+(femaleHair.length%hairsPerPage==0?0:1);
		MaleFacePages=Math.floor(maleFace.length/facesPerPage)+(maleFace.length%facesPerPage==0?0:1);
		FemaleFacePages=Math.floor(femaleFace.length/facesPerPage)+(femaleFace.length%facesPerPage==0?0:1);
		msg="\t\t\t\t\t\t\t#eCotton Stylist#n\r\n";
		msg+="#e#L0#Skin#l\t\t\t\t\t#L1#Hair Color#l\t\t\t\t\t#L2#Eye Color#l\r\n";
		msg+="\r\n\t\t\t\t\t\t\t\t\t#b#L3#Hairs#l#k";
		msg+="\r\n\t\t\t#b#L5#Male Faces#l#k\t\t   #d#L6#Female Faces#l#k";
		//msg+="\r\n#e#g\t\t\t\t\t\t\t\t\t#L7#Special#l"
		
		//msg+="\r\n\r\n#e#r\t\t\t\t\t\t\t\t\t#L9#Search#l"
		cm.sendSimple(msg);
    }else if (status == 1) {
		msg="";
		if(selected == -1)
        selected = selection;
		if (selected == 0){
            cm.sendStyle("Choose a style!\r\nThere are " + skin.length + " styles to choose from.", skin);
			SelectedChange=skin;
        }else if (selected == 1){
            var setHairToBlack = setBlack(cm.getPlayer().getHair(), true);
			haircolor = range(setHairToBlack, setHairToBlack + 7, 1);
			cm.sendStyle("Which color?", haircolor);
			SelectedChange=haircolor;
        }else if (selected == 2){
			var setEyeToBlack = setBlack(cm.getPlayer().getFace(), false);
			eyecolors = range(setEyeToBlack, setEyeToBlack + 800, 100);
            cm.sendStyle("Which color?", eyecolors);
			SelectedChange=eyecolors;
		}else if (selected == 3) {//male hairs
			for(i=0;i<MaleHairPages;i++){
			msg+="#b#L"+i+"#Page "+(i+1)+"#l#k";
			if(i%5==4)
				msg+="\r\n";
			}
			msg+="\r\n\r\n-------------------------------"+ (Page+1) +" / "+ MaleHairPages+"-------------------------------\r\n";
			msg+="#b"+(Page>0? "#L1000#Prev#l":"\t")+"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"+(Page < MaleHairPages-1? "#L2000#Next#l":"\t")+"#k";
			msg+=getHairs(maleHair,Page);
			cm.sendSimple(msg);
		}else if (selected == 4) {//female hairs
			for(i=0;i<FemaleHairPages;i++){
			msg+="#d#L"+i+"#Page "+(i+1)+"#l#k";
			if(i%5==4)
				msg+="\r\n";
			}
			msg+="\r\n\r\n-------------------------------"+ (Page+1) +" / "+ FemaleHairPages+"-------------------------------\r\n";
			msg+="#b"+(Page>0? "#L1000#Prev#l":"\t")+"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"+(Page < FemaleHairPages-1? "#L2000#Next#l":"\t")+"#k";
			msg+=getHairs(femaleHair,Page);
			cm.sendSimple(msg)
		}else if (selected == 5) {//male faces
			for(i=0;i<MaleFacePages;i++){
			msg+="#b#L"+i+"#Page "+(i+1)+"#l#k";
			if(i%5==4)
				msg+="\r\n";
			}
			msg+="\r\n\r\n-------------------------------"+ (Page+1) +" / "+ MaleFacePages+"-------------------------------\r\n";
			msg+="#b"+(Page>0? "#L1000#Prev#l":"\t")+"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"+(Page < MaleFacePages-1? "#L2000#Next#l":"\t")+"#k";
			msg+=getFaces(maleFace,Page);
			cm.sendSimple(msg);
		}else if (selected == 6) {//female faces
			for(i=0;i<FemaleFacePages;i++){
			msg+="#d#L"+i+"#Page "+(i+1)+"#l#k";
			if(i%5==4)
				msg+="\r\n";
			}
			msg+="\r\n\r\n-------------------------------"+ (Page+1) +" / "+ FemaleFacePages+"-------------------------------\r\n";
			msg+="#b"+(Page>0? "#L1000#Prev#l":"\t")+"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"+(Page < FemaleFacePages-1? "#L2000#Next#l":"\t")+"#k";
			msg+=getFaces(femaleFace,Page);
			cm.sendSimple(msg);
		}else if(selected == 7){
			cm.dispose();
			cm.openNpc(cm.getNpc(),"SpecialStyle");
			return;
		}else if(selected ==8){
			text = "\t\t\t\t\t\t\t\t Male Hairs";
			text += "\r\n"+StylesToFix(maleHair);
			text += "\r\n\t\t\t\t\t\t\t\t Female Hairs";
			text += "\r\n"+StylesToFix(femaleHair);
			text += "\r\n\t\t\t\t\t\t\t\t Male Faces";
			text += "\r\n"+StylesToFix(maleFace);
			text += "\r\n\t\t\t\t\t\t\t\t Female Faces";
			text += "\r\n"+StylesToFix(femaleFace);
			cm.sendOk(text);
			cm.dispose();
		}else if(selected ==9){
			cm.sendGetText("Please write the name of the style you are looking for!");
		}
    } else if (status == 2) {
		if (selected >= 3 && selected <= 6){
			if(selected <5){
				SelectedChange = range(selection, selection + 7, 1);
			}else{ 
				SelectedChange = range(selection, selection + 800, 100);
			}
			if(SelectedChange.length !=0){
				cm.sendStyle("Which color?", SelectedChange);
			}else{
				cm.sendOk("This hair doesn't exists please talk to the Gm 'afk' to get it fixed");
				cm.dispose();
			}
		}else if (selected == 9){
			var styles = search(cm.getText());
			SearchHairPages = Math.floor(styles[0].length/hairsPerPage)+(styles[0].length%hairsPerPage==0?0:1);
			SearchFacePages = Math.floor(styles[1].length/facesPerPage)+(styles[1].length%facesPerPage==0?0:1);
			totalPages = SearchHairPages+SearchFacePages;
			msg="";
			for(i=0;i<totalPages;i++){
			msg+="#b#L"+i+"#Page "+(i+1)+"#l#k";
			if(i%5==4)
				msg+="\r\n";
			}
			msg+="\r\n\r\n-------------------------------"+ (Page+1) +" / "+ totalPages+"-------------------------------\r\n";
			msg+="#b"+(Page>0? "#L1000#Prev#l":"\t")+"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"+(Page < totalPages-1? "#L2000#Next#l":"\t")+"#k";
			if(Page<SearchHairPages)
				msg+=getHairs(styles[0],Page);
			else
				msg+=getFaces(styles[1],Page-SearchHairPages);
			if(styles[0].length != 0 || styles[1].length != 0){
				cm.sendSimple(msg);
			}else{
				cm.sendOk("None of the styles has '#r"+cm.getText()+"#k' in their name.");
			}
		}else{
			if (selected == 0){
				cm.setSkin(SelectedChange[selection]);
			}else if (selected == 1){
				cm.setHair(SelectedChange[selection]);
			}else if (selected == 2){
				cm.setFace(SelectedChange[selection]);
			}
			cm.dispose();
		}
    }else if (status == 3){
	if (selected == 9){
		if(Page<SearchHairPages){
			SelectedChange = range(selection, selection + 7, 1);
		}else{ 
			SelectedChange = range(selection, selection + 800, 100);
		}
		if(SelectedChange.length !=0){
			cm.sendStyle("Which color?", SelectedChange);
		}else{
			cm.sendOk("This hair doesn't exists please talk to the Gm 'afk' to get it fixed");
			cm.dispose();
		}
	}else{
	if(selected<5)
		cm.setHair(SelectedChange[selection]);
	else
		cm.setFace(SelectedChange[selection]);
	cm.dispose();
	}
	}else if (status == 4){
		if(Page<SearchHairPages)
			cm.setHair(SelectedChange[selection]);
		else
			cm.setFace(SelectedChange[selection]);
	}
}

function range(start, stop, increment) { // Apparently JavaScript does not come with this
	var arr = new Array();
	for (var i = start; i <= stop; i += increment)
		arr.push(i);
	return arr;
}

function setBlack(id, hair) {
	if (hair) {
		return id - (id % 10);
	} else { // eye
		return id - (Math.floor((id / 100) % 10) * 100);
	}
}

function getHairs(Hairs,s) {
	var mssg="";
	for(var i=0;i<hairsPerPage;i++){
		if(i%4==0)
			mssg+="\r\n";
		if(Hairs.length>s*hairsPerPage+i)
			mssg+="#L"+Hairs[s*hairsPerPage+i]+"##fCharacter/Hair/000"+Hairs[s*hairsPerPage+i]+"/default/hairOverHead##l";
	}
	return mssg;
}

function getFaces(Faces,s) {
	var mssg="";
	for(var i=0;i<facesPerPage;i++){
		if(i%7==0)
			mssg+="\r\n";
		if(Faces.length>s*facesPerPage+i)
			mssg+="#L"+Faces[s*facesPerPage+i]+"##fCharacter/Face/000"+Faces[s*facesPerPage+i]+"/default/face##l";
	}
	return mssg;
}

function StylesToFix(styles){
	var toFix = "";
	for(var j=0;j<styles.length;j++){
		var faceData = CharacterProvider.getProvider().getData("Face/000"+styles[j]+".img");
		var hairData = CharacterProvider.getProvider().getData("Hair/000"+styles[j]+".img");
		if(faceData == null && hairData == null)toFix += styles[j]+", ";
	}
	return toFix;
}


function search(name){
	var items =[[],[]];
	for(var j=0;j<maleHair.length;j++ ){
		items[0].push(maleHair[j]);
	}
	for(var j=0;j<femaleHair.length;j++ ){
		items[0].push(femaleHair[j]);
	}
	for(var j=0;j<maleFace.length;j++ ){
		items[1].push(maleFace[j]);
	}
	for(var j=0;j<femaleFace.length;j++ ){
		items[1].push(femaleFace[j]);
	}
	items[0] =cm.FindItemsByName(items[0],name);
	items[1] =cm.FindItemsByName(items[1],name);
	return items;
}