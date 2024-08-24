function act() {
    var eim = rm.getEventInstance();
    if (eim != null) {
        var mapId = rm.getMap().getId();

        if (mapId == 610030200) {
            eim.dropMessage(6, "The Archer Sigil has been activated!");
            eim.setIntProperty("glpq2", eim.getIntProperty("glpq2") + 1);
            if (eim.getIntProperty("glpq2") == 5) { //all 5 done
                eim.dropMessage(6, "The Antellion grants you access to the next portal! Proceed!");

                eim.showClearEffect(mapId, "2pt", 2);
                eim.giveEventPlayersStageReward(2);
            }
        } else if (mapId == 610030300) {
            eim.dropMessage(6, "The Archer Sigil has been activated! You hear gears turning! The Menhir Defense System is active! Run!");
            eim.setIntProperty("glpq3", eim.getIntProperty("glpq3") + 1);
            rm.getMap().moveEnvironment("menhir1", 1);
            rm.getMap().moveEnvironment("menhir2", 1);
            if (eim.getIntProperty("glpq3") == 5 && eim.getIntProperty("glpq3_p") == 5) {
                eim.dropMessage(6, "The Antellion grants you access to the next portal! Proceed!");

                eim.showClearEffect(mapId, "3pt", 2);
                eim.giveEventPlayersStageReward(3);
            }
        }
    }
}