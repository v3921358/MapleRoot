class ExpeditionLeaderboardInteraction {
    constructor(cm) {
        this.cm = cm;
        this.handlerRegistry = new InteractionHandlerRegistry();

        this.leaderboardTypeOptions = [ LeaderboardType.Global, LeaderboardType.Personal ];
        this.expeditionBossOptions = [ BossOption.SCARGA, BossOption.PAPULATUS, BossOption.KREXEL, BossOption.CASTELLAN,
            BossOption.ZAKUM, BossOption.HORNTAIL, BossOption.PINKBEAN, BossOption.VONLEON, BossOption.CYGNUS,
            BossOption.LUCID, BossOption.WILLSPIDER, BossOption.VERUS, BossOption.DARKNELL, BossOption.EASYMAGNUS,
            BossOption.NORMALMAGNUS, BossOption.HARDMAGNUS, BossOption.NORMALLOTUS, BossOption.HARDLOTUS ];

        this.ExpeditionLeaderboard = Java.type("server.expeditions.ExpeditionLeaderboard");
        this.BossLogEntry = Java.type("server.expeditions.ExpeditionBossLog.BossLogEntry");

        this.selectedLeaderboardTypeOption = null;
        this.selectedBossOption = null;

        this.lastStatus = null;

        this.initializeHandlers();
    }

    initializeHandlers() {
        this.handlerRegistry.register(1, null, this.showLeaderboardTypeSelectionMenu.bind(this));

        this.handlerRegistry.register(2, null, this.showBossSelectionMenu.bind(this));

        this.handlerRegistry.register(3, LeaderboardType.Global, this.showGlobalLeaderboard.bind(this));
        this.handlerRegistry.register(3, LeaderboardType.Personal, this.showPersonalLeaderboard.bind(this));
    }

    action(mode, type, selection, status) {
        if (this.cm.isEndChat(mode, type)) {
            return ScriptInteractionResult.Dispose;
        }

        try {
            if (status === 2) {
                if (this.lastStatus > status) {
                    this.selectedLeaderboardTypeOption = this.selectedLeaderboardTypeOption || selection;
                } else {
                    this.selectedLeaderboardTypeOption = selection;
                }
            }

            const handler = this.handlerRegistry.getHandler(status, this.selectedLeaderboardTypeOption);
            return handler.call(this, mode, type, selection, status);
        } catch (error) {
            this.cm.logToConsole(`[ExpeditionLeaderboardInteraction] HandlerError: ${error}`);
            return ScriptInteractionResult.HandlerError;
        }
    }

    showLeaderboardTypeSelectionMenu(mode, type, selection, status) {
        // set null to allow a new selection
        this.selectedLeaderboardTypeOption = null;
        let selectionString = "Select the type of leaderboard you would like to view.\r\n\r\n"

        for (let option of this.leaderboardTypeOptions) {
            selectionString += `#L${option}# ${LeaderboardType.StringMap[option]}\r\n`;
        }

        this.cm.sendSimple(selectionString);
        return status;
    }

    showBossSelectionMenu(mode, type, selection, status) {
        let selectionString = "Select the boss.\r\n\r\n"

        for (let option of this.expeditionBossOptions) {
            selectionString += `#L${option}# ${BossOption.StringMap[option]}\r\n`;
        }

        this.cm.sendSimple(selectionString);
        return status;
    }

    showGlobalLeaderboard(mode, type, selection, status) {
        this.selectedBossOption = selection;

        const leaderboardRecords =
            this.ExpeditionLeaderboard.getGlobalLeaderboardStringForBoss(
                this.BossLogEntry.getBossEntryByName(BossOption.StringMap[this.selectedBossOption]));

        this.cm.sendPrev(leaderboardRecords);
        return --status;
    }

    showPersonalLeaderboard(mode, type, selection, status) {
        this.selectedBossOption = selection;

        const leaderboardRecords =
            this.ExpeditionLeaderboard.getPersonalLeaderboardStringForBoss(this.cm.getPlayer().getId(),
                this.BossLogEntry.getBossEntryByName(BossOption.StringMap[this.selectedBossOption]));

        this.cm.sendPrev(leaderboardRecords);
        return --status;
    }
}



const LeaderboardType = {
    StringMap: {
        1 : "Global",
        2 : "Personal",
    },
    Global: 1,
    Personal: 2
}

const BossOption = {
    StringMap: {
        1 : "SCARGA",
        2 : "PAPULATUS",
        3 : "KREXEL",
        4 : "CASTELLAN",
        5 : "ZAKUM",
        6 : "HORNTAIL",
        7 : "PINKBEAN",
        8 : "VONLEON",
        9 : "CYGNUS",
        10 : "LUCID",
        11 : "WILLSPIDER",
        12 : "VERUS",
        13 : "DARKNELL",
        14 : "EASY MAGNUS",
        15 : "NORMAL MAGNUS",
        16 : "HARD MAGNUS",
        17 : "NORMAL LOTUS",
        18 : "HARD LOTUS",
    },
    SCARGA: 1,
    PAPULATUS: 2,
    KREXEL: 3,
    CASTELLAN: 4,
    ZAKUM: 5,
    HORNTAIL: 6,
    PINKBEAN: 7,
    VONLEON: 8,
    CYGNUS: 9,
    LUCID: 10,
    WILLSPIDER: 11,
    VERUS: 12,
    DARKNELL: 13,
    EASYMAGNUS: 14,
    NORMALMAGNUS: 15,
    HARDMAGNUS: 16,
    NORMALLOTUS: 17,
    HARDLOTUS: 18
}