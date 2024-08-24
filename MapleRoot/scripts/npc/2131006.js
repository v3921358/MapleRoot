var status = -1;
var exchangeItem = 4000440;

function start() {
    action(1, 0, 0);
}

function action(mode, type, selection) {
    if (mode == 1) {
        status++;
    } else {
        cm.dispose();
        return;
    }
    if (status == 0) {
        cm.sendSimple("The monsters are advancing.. I can't fight. I was badly injured by the Primitive Boars...#b\r\n#L0#Hey, take these boar hides. You can recover from them.#l");
    } else if (status == 1) {
        if (!cm.haveItem(exchangeItem, 100)) {
            cm.sendNext("You don't have enough... I need at least 100.");
            cm.dispose();
        } else {
            cm.sendGetNumber("Hey, that's a good idea! I can give you #i4001126#Maple Leaf for each 100 #i" + exchangeItem + "##t" + exchangeItem + "# you give me. How many do you want? (Current Items: " + cm.itemQuantity(exchangeItem) + ")", Math.min(300, Math.floor(cm.itemQuantity(exchangeItem) / 100)), 1, Math.min(300, Math.floor(cm.itemQuantity(exchangeItem) / 100)));
        }
    } else if (status == 2) {
        if (selection >= 1 && selection <= Math.floor(cm.itemQuantity(exchangeItem) / 100)) {
            if (!cm.canHold(4001126, selection)) {
                cm.sendOk("Please make some space in ETC tab.");
            } else {
                cm.gainItem(4001126, selection);
                cm.gainItem(exchangeItem, -(selection * 100));
                cm.sendOk("Thanks!");
            }
        }
        cm.dispose();
    }
}