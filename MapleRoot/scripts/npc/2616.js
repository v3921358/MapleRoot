/**
 * MapleRoot
 * Gwen Stacy Starforce
 * @author Gwen
 */
let enabled = true;
let status = 0;
let slot;
let item;
let playermesos = 0;
let sfmesocost = 0;
let spelltracecost = 0;
let restart;

function start() {
    status = 0;
    restart = false;
    if (enabled) {
        cm.sendNext("Please select the item you would like to starforce");
    } else {
        cm.sendOk("Disabled for now");
        cm.dispose();
    }
}

function action(m, t, s) {
    if (m !== 1) {
        cm.sendOk("Cya around kid.");
        cm.dispose();
    } else {
        status++;
        if (status === 1) {
            cm.sendSimple("Which item would you like to enhance?\r\n" + cm.getStarForceEquipSlot());
        } else if (status === 2) {
            slot = slot || s;
            item = cm.getSFItem(slot);
            if (item.getUpgradeSlots() === 0) {
                cm.sendOk("This item cannot be enhanced any further.");
                cm.dispose();
                return;
            }
            if(item.getItemId())
            playermesos = cm.getMeso();
            sfmesocost = cm.getMesoStarforceCost(item.getLevel(), cm.getReqLevel(item.getItemId()), cm.isSuperior(item.getItemId()));
            spelltracecost = cm.getSpellTraceCost(item.getLevel(), cm.getReqLevel(item.getItemId()), cm.isSuperior(item.getItemId()));
            cm.sendYesNo("Attempt to enhance #i" + item.getItemId() + "# from level " + item.getLevel() + " to " + (item.getLevel() + 1) + " will cost you \r\n\r\n"
            + "#fUI/UIWindow.img/Shop/meso# " + cm.numberWithCommas(sfmesocost) + "\r\n\r\n" + "#fUI/UIWindow.img/Shop/trace# " + spelltracecost + "\r\n\r\n Is that okay?");
        } else if (status === 3) {
            if(playermesos < sfmesocost) {
                cm.sendOk("You don't possess enough mesos.");
                cm.dispose();
            } else if (!cm.haveItem(4000999, spelltracecost)) {
                cm.sendOk("You don't possess enough spell traces");
                cm.dispose();
            } else {
                cm.gainMeso(-sfmesocost);
                cm.gainItem(4000999, -spelltracecost);
                cm.StarForceEquip(cm.getSFItem(slot));
                cm.sendOk('Complete');
                status = 1;
            }
        }
    }
}