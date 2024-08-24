/**
 * STORAGE NPC
 * Rosen, personal infinity storage
 * Maple Art Online
 * @author Chronos
 */

let status;
let tempsel;
let choice;
let restart;

let selectedItem;

let item;
let amount;

function start() {
    status = 0;
    restart = false;

    if (item === undefined) {
        item = cm.getStoredItem();
        amount = cm.getStoredAmount()
    }

    var str = cm.letters("Bank") + "\r\n\r\nHello master #r#h ##k";
    if (item === 0) { // no item stored
        str += ", it appears you have nothing in the bank at the moment...\r\n#b" +
            "#L0#I want to store an item.#l\r\n" +
            "#L1#What can you do for me?#l";
    } else { // item stored
        str += ".\r\n\r\nYou currently have #r" + amount + "#k #i" + item + "# #b#t" + item + "#" + (amount === 1 ? "" : "s") + "#k stored.\r\n" +
            "What would you like to do?\r\n#b" +
            "#L0#I want to deposit more #t" + item + "#s#l\r\n" +
            "#L1#I want to retrieve some #t" + item + "#s#l\r\n\r\n" +
            "#L2##r#eI want to destroy all of my stored #t" + item + "#s#l";
    }
    cm.sendSimple(str);
}

function action(m, t, s) {
    if (m !== 1) {
        cm.sendOk("You can trust my discretion, young master...");
        cm.dispose();
    } else {
        if (restart) {
            start();
            return;
        }
        status++;
        if (item === 0) {
            noItemStored(m, t, s);
        } else {
            itemStored(m, t, s);
        }
    }
}

function itemStored(m, t, s) {
    if (status === 1) {
        tempsel = s;
        if (s === 0) { // I want to deposit more...
            var quantity = cm.itemQuantity(item);
            if (quantity === 0) {
                cm.sendOk("You do not seem to have any #b#t" + item + "#s#k on you.");
                restart = true;
            } else {
                cm.sendGetNumber(cm.letters("Deposit") + "\r\n\r\nHow much of #i" + item + "# #b#t" + item + "##k do you wish to store?\r\n(max: #r" + quantity + "#k)", quantity, 1, quantity);
            }
        } else if (s === 1) { // I want to retrieve some...
            cm.sendGetNumber(cm.letters("Retrieve") + "\r\n\r\nHow much of #i" + item + "# #b#t" + item + "##k do you wish to retrieve?\r\n(stored: #r" + amount + "#k)", amount, 1, amount);
        } else if (s === 2) { // I want to destroy all of my stored...
            cm.sendYesNo(cm.letters("DESTROY") + "\r\n\r\nAre you sure you want to #r#eDESTROY#n #r" + amount + "#kx #i" + item + "#\r\n" +
                "This action can't be undone, you will #r#eNEVER#n#k see these items again.");
        }
    } else if (status === 2) {
        if (tempsel === 0) { // I want to deposit more...
            if (antiCheatCheck(item, s, cm.itemQuantity(item))) {
                var newAmount = amount + s;
                cm.gainItem(item, -s);
                cm.updateStoredAmount(newAmount);
                cm.sendOk("I will make sure to keep the items save.\r\nYou now have a total of #r" + newAmount + "#k #b#t" + item + "##k stored.");
                cm.dispose();
            }
        } else if (tempsel === 1) { // I want to retrieve some...
            if (antiCheatCheck(item, s, amount)) {
                var slotsNeeded = s / cm.getMIIP().getSlotMax(cm.getClient(), item);
                if (cm.getFreeSlots(item) > slotsNeeded) {
                    cm.gainItem(item, s);
                    var newAmount = amount - s;
                    if (newAmount !== 0) {
                        cm.updateStoredItem(item, -s);
                        amount = newAmount;
                    } else {
                        cm.updateStoredItem(0, 0);
                        item = 0;
                        amount = 0;
                    }
                    cm.sendOk("As you please...");
                } else {
                    cm.sendOk("You do not have enough inventory space available.");
                }
            }
            restart = true;
        } else if (tempsel === 2) { // I want to destroy all of my stored...
            cm.updateStoredItem(0, 0);
            cm.sendOk("As you asked, the items have been destroyed.");
            item = 0;
            amount = 0;
            restart = true;
        }
    }
}

function noItemStored(m, t, s) {
    if (status === 1) {
        if (s === 0) { // I want to store an item
            cm.sendSimple("Please, select a category:\r\n#b" +
                "#L0#Use#l\r\n" +
                "#L1#Etc#l");
        } else if (s === 1) { // What can you do for me?
            cm.sendOk("I can store a single type of item for you.\r\n" +
                "But unlike a regular storage, I can hold an infinite amount of this item.\r\n" +
                "Later on you can withdraw any number of stacks of this item whenever you desire.\r\n\r\n" +
                "All this for the price of nothing. #rI live to serve#k.");
            restart = true;
        }
    } else if (status === 2) {
        tempsel = s;
        cm.sendSimple(cm.getInventoryAsString(s === 0 ? "Consume" : "Etc"));
    } else if (status === 3) {
        selectedItem = cm.getPlayer().getItemByTypeAndPos(tempsel === 0 ? "Consume" : "Etc", s).getItemId();
        var max = cm.itemQuantity(selectedItem);
        cm.sendGetNumber("How much of #i" + selectedItem + "# #b#t" + selectedItem + "##k do you wish to store?\r\n(max: #r" + max + "#k)", max, 1, max);
    } else if (status === 4) {
        if (antiCheatCheck(selectedItem, s, cm.itemQuantity(selectedItem))) {
            cm.gainItem(selectedItem, -s);
            cm.updateStoredItem(selectedItem, s);
            cm.sendOk("I've stored #r" + s + "#k #t" + selectedItem + "#" + (s === 1 ? "" : "s") + ".");
            cm.dispose();
        }
    }
}

function antiCheatCheck(item, amount, max) {
    if (amount > max) {
        cm.getPlayer().autoban(cm.getName() + " tried to packet edit the Infinity Storage (Selection Manipulation - exceeding)");
        return false;
    } else if (amount < 1) {
        cm.getPlayer().autoban(cm.getName() + " tried to packet edit the Infinity Storage (Selection Manipulation - negative input)");
        return false;
    }
    return true;
}