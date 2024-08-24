function enter(pi) {
    var eim = pi.getEventInstance();
    if (eim != null) {
        if (eim.getIntProperty("glpq6") < 3) {
            pi.playerMessage(5, "The portal is not opened yet.");
            return false;
        } else {
            pi.playPortalSound();
            pi.warp(610030700, 0);
            return true;
        }
    }

    return false;
}