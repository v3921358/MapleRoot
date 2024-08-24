function enter(pi) {
    const player = pi.getPlayer();

    if (player.gmLevel() >= 2 || player.getReborns() >= 2) {
        pi.playPortalSound();
        pi.warp(910000004, 0);
        return true;
    }
    pi.playerMessage(5, "You need at least 2 rebirths to enter Dkingdom.");
    return false;
}