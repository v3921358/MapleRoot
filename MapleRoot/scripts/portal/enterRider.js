function enter(pi) {
    if (pi.isQuestStarted(21610) && pi.haveItem(4001193, 1) == 0) {
        var em = pi.getEventManager("Aran_2ndmount");
        if (em == null) {
            pi.message("Sorry, but the 2nd mount quest (Scadur) is closed.");
            return false;
        } else {
            var em = pi.getEventManager("Aran_2ndmount");
            if (!em.startInstance(pi.getPlayer())) {
                pi.message("There is currently someone in this map, come back later.");
                return false;
            } else {
                pi.playPortalSound();
                return true;
            }
        }
    } else {
        pi.playerMessage(5, "Only attendants of the 2nd Wolf Riding quest may enter this field.");
        return false;
    }
}