/* Pi
	Ludibrium Village (220000300)
	
	Refining NPC: 
	* Minerals
	* Jewels
	* Moon/Star Rocks
	* Crystals (minus Dark)
	* Processed Wood/Screws
	* Arrows/Bronze Arrows/Steel Arrows
* Commented out minerals, jewels, rocks and crystals from being refined
*/

var status = 0;
var selectedType = -1;
var selectedItem = -1;
var item;
var mats;
var matQty;
var cost;
var qty;
var equip;

function start() {
    status = -1;
    action(1, 0, 0);
}

function action(mode, type, selection) {
    if (mode == 1) {
        status++;
    } else {
        cm.dispose();
    }
    if (status == 0 && mode == 1) {
        var selStr = "Ah, are you looking to refine some ores? \r\n\r\nMy apologies, I have since #rretired#k from that profession; but #b#eKibbles#n#k in the #bFree Market#k has become a \r\n#emaster#n in her trade. I heard she can even #renhance advanced equipment#n#k for you when crafting.\r\n\r\nI am, however, still a great #rcarpenter#k. I'd be glad to process some of your materials.#b"
        var options = [/*"Refine a mineral ore", "Refine a jewel ore", "Refine a rare jewel", "Refine a crystal ore",*/ "Create materials", "Create Arrows"];
        for (var i = 0; i < options.length; i++) {
            selStr += "\r\n#L" + i + "# " + options[i] + "#l";
        }

        cm.sendSimple(selStr);
    } else if (status == 1 && mode == 1) {
        selectedType = selection;
        /*if (selectedType == 0) { //mineral refine
            var selStr = "So, what kind of mineral ore would you like to refine?#b";
            var minerals = ["Bronze", "Steel", "Mithril", "Adamantium", "Silver", "Orihalcon", "Gold"];
            for (var i = 0; i < minerals.length; i++) {
                selStr += "\r\n#L" + i + "# " + minerals[i] + "#l";
            }
            equip = false;
            cm.sendSimple(selStr);
        } else if (selectedType == 1) { //jewel refine
            var selStr = "So, what kind of jewel ore would you like to refine?#b";
            var jewels = ["Garnet", "Amethyst", "Aquamarine", "Emerald", "Opal", "Sapphire", "Topaz", "Diamond", "Black Crystal"];
            for (var i = 0; i < jewels.length; i++) {
                selStr += "\r\n#L" + i + "# " + jewels[i] + "#l";
            }
            equip = false;
            cm.sendSimple(selStr);
        } else if (selectedType == 2) { //rock refine
            var selStr = "A rare jewel? Which one were you thinking of?#b";
            var items = ["Moon Rock", "Star Rock"];
            for (var i = 0; i < items.length; i++) {
                selStr += "\r\n#L" + i + "# " + items[i] + "#l";
            }
            equip = false;
            cm.sendSimple(selStr);
        } else if (selectedType == 3) { //crystal refine
            var selStr = "Crystal ore? I love refining those!#b";
            var crystals = ["Power Crystal", "Wisdom Crystal", "DEX Crystal", "LUK Crystal"];
            for (var i = 0; i < crystals.length; i++) {
                selStr += "\r\n#L" + i + "# " + crystals[i] + "#l";
            }
            equip = false;
            cm.sendSimple(selStr);
        */if (selectedType == 0) { //material refine
            var selStr = "Materials? I know of a few materials that I can make for you...#b";
            var materials = ["Make Processed Wood with Tree Branch", "Make Processed Wood with Firewood", "Make Screws (packs of 15)"];
            for (var i = 0; i < materials.length; i++) {
                selStr += "\r\n#L" + i + "# " + materials[i] + "#l";
            }
            equip = false;
            cm.sendSimple(selStr);
        } else if (selectedType == 1) { //arrow refine
            var selStr = "Arrows? Not a problem at all.#b";
            var arrows = ["Arrow for Bow", "Arrow for Crossbow", "Bronze Arrow for Bow", "Bronze Arrow for Crossbow", "Steel Arrow for Bow", "Steel Arrow for Crossbow"];
            for (var i = 0; i < arrows.length; i++) {
                selStr += "\r\n#L" + i + "# " + arrows[i] + "#l";
            }
            equip = true;
            cm.sendSimple(selStr);
        }
        if (equip) {
            status++;
        }
    } else if (status == 2 && mode == 1) {
        selectedItem = selection;
        /*if (selectedType == 0) { //mineral refine
            var itemSet = [4011000, 4011001, 4011002, 4011003, 4011004, 4011005, 4011006];
            var matSet = [4010000, 4010001, 4010002, 4010003, 4010004, 4010005, 4010006];
            var matQtySet = [10, 10, 10, 10, 10, 10, 10];
            var costSet = [270, 270, 270, 450, 450, 450, 720];
            item = itemSet[selectedItem];
            mats = matSet[selectedItem];
            matQty = matQtySet[selectedItem];
            cost = costSet[selectedItem];
        } else if (selectedType == 1) { //jewel refine
            var itemSet = [4021000, 4021001, 4021002, 4021003, 4021004, 4021005, 4021006, 4021007, 4021008];
            var matSet = [4020000, 4020001, 4020002, 4020003, 4020004, 4020005, 4020006, 4020007, 4020008];
            var matQtySet = [10, 10, 10, 10, 10, 10, 10, 10, 10];
            var costSet = [450, 450, 450, 450, 450, 450, 450, 900, 2700];
            item = itemSet[selectedItem];
            mats = matSet[selectedItem];
            matQty = matQtySet[selectedItem];
            cost = costSet[selectedItem];
        } else if (selectedType == 2) { //rock refine
            var itemSet = [4011007, 4021009];
            var matSet = [[4011000, 4011001, 4011002, 4011003, 4011004, 4011005, 4011006], [4021000, 4021001, 4021002, 4021003, 4021004, 4021005, 4021006, 4021007, 4021008]];
            var matQtySet = [[1, 1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1, 1, 1, 1]];
            var costSet = [9000, 13500];
            item = itemSet[selectedItem];
            mats = matSet[selectedItem];
            matQty = matQtySet[selectedItem];
            cost = costSet[selectedItem];
        } else if (selectedType == 3) { //crystal refine
            var itemSet = [4005000, 4005001, 4005002, 4005003];
            var matSet = [4004000, 4004001, 4004002, 4004003];
            var matQtySet = [10, 10, 10, 10];
            var costSet = [4500, 4500, 4500, 4500];
            item = itemSet[selectedItem];
            mats = matSet[selectedItem];
            matQty = matQtySet[selectedItem];
            cost = costSet[selectedItem];
        */
        if (selectedType == 0) { //material refine
            var itemSet = [4003001, 4003001, 4003000];
            var matSet = [4000003, 4000018, [4011000, 4011001]];
            var matQtySet = [10, 5, [1, 1]];
            var costSet = [0, 0, 0];
            item = itemSet[selectedItem];
            mats = matSet[selectedItem];
            matQty = matQtySet[selectedItem];
            cost = costSet[selectedItem];
        }

        var prompt = "So, you want me to make some #t" + item + "#s? In that case, how many do you want me to make?";

        cm.sendGetNumber(prompt, 1, 1, 100)
    } else if (status == 3 && mode == 1) {
        if (equip) {
            selectedItem = selection;
            qty = 1;
        } else {
            qty = (selection > 0) ? selection : (selection < 0 ? -selection : 1);
        }

        // thanks kvmba for noticing arrow selection crashing players
        if (selectedType == 1) { //arrow refine
            var itemSet = [2060000, 2061000, 2060001, 2061001, 2060002, 2061002];
            var matSet = [[4003001, 4003004], [4003001, 4003004], [4011000, 4003001, 4003004], [4011000, 4003001, 4003004],
                [4011001, 4003001, 4003005], [4011001, 4003001, 4003005]];
            var matQtySet = [[1, 1], [1, 1], [1, 3, 10], [1, 3, 10], [1, 5, 15], [1, 5, 15]];
            var costSet = [0, 0, 0, 0, 0, 0];
            item = itemSet[selectedItem];
            mats = matSet[selectedItem];
            matQty = matQtySet[selectedItem];
            cost = costSet[selectedItem];
        }

        var prompt = "You want me to make ";
        if (qty == 1) {
            prompt += "a #t" + item + "#?";
        } else {
            prompt += qty + " #t" + item + "#?";
        }

        prompt += " In that case, I'm going to need specific items from you in order to make it. Make sure you have room in your inventory, though!#b";

        if (mats instanceof Array) {
            for (var i = 0; i < mats.length; i++) {
                prompt += "\r\n#i" + mats[i] + "# " + matQty[i] * qty + " #t" + mats[i] + "#";
            }
        } else {
            prompt += "\r\n#i" + mats + "# " + matQty * qty + " #t" + mats + "#";
        }

        if (cost > 0) {
            prompt += "\r\n#i4031138# " + cost * qty + " meso";
        }

        cm.sendYesNo(prompt);
    } else if (status == 4 && mode == 1) {
        var complete = true;
        var recvItem = item, recvQty;

        if (item >= 2060000 && item <= 2060002) //bow arrows
        {
            recvQty = 1000 - (item - 2060000) * 100;
        } else if (item >= 2061000 && item <= 2061002) //xbow arrows
        {
            recvQty = 1000 - (item - 2061000) * 100;
        } else if (item == 4003000)//screws
        {
            recvQty = 15 * qty;
        } else {
            recvQty = qty;
        }

        if (!cm.canHold(recvItem, recvQty)) {
            cm.sendOk("I'm afraid you have no slots available for this transaction.");
        } else if (cm.getMeso() < cost * qty) {
            cm.sendOk("I'm afraid you cannot afford my services.");
        } else {
            if (mats instanceof Array) {
                for (var i = 0; complete && i < mats.length; i++) {
                    if (matQty[i] * qty == 1) {
                        if (!cm.haveItem(mats[i] * qty)) {
                            complete = false;
                        }
                    } else {
                        if (!cm.haveItem(mats[i], matQty[i] * qty)) {
                            complete = false;
                        }
                    }
                }
            } else {
                if (!cm.haveItem(mats, matQty * qty)) {
                    complete = false;
                }
            }

            if (!complete) {
                cm.sendOk("Hold it, I can't finish that without all of the proper materials. Bring them first, then we'll talk.");
            } else {
                if (mats instanceof Array) {
                    for (var i = 0; i < mats.length; i++) {
                        cm.gainItem(mats[i], -matQty[i] * qty);
                    }
                } else {
                    cm.gainItem(mats, -matQty * qty);
                }

                if (cost > 0) {
                    cm.gainMeso(-cost * qty);
                }

                cm.gainItem(recvItem, recvQty);
                cm.sendOk("All done. If you need anything else, you know where to find me.");
            }
        }

        cm.dispose();
    }
}