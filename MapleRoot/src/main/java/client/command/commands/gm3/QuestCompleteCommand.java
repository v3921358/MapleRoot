/*
    This file is part of the HeavenMS MapleStory Server, commands OdinMS-based
    Copyleft (L) 2016 - 2019 RonanLana

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation version 3 as published by
    the Free Software Foundation. You may not use, modify or distribute
    this program under any other version of the GNU Affero General Public
    License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
   @Author: Arthur L - Refactored command content into modules
*/
package client.command.commands.gm3;

import client.Character;
import client.Client;
import client.command.Command;
import server.quest.Quest;

public class QuestCompleteCommand extends Command {
    {
        setDescription("Complete an active quest.");
    }

    @Override
    public void execute(Client c, String[] params) {
        Character player = c.getPlayer();

        if (params.length < 1) {
            player.yellowMessage("Syntax: !completequest <questid>");
            return;
        }

        int questId = Integer.parseInt(params[0]);

        if (player.getQuestStatus(questId) == 1) {
            Quest quest = Quest.getInstance(questId);
            if (quest != null && quest.getNpcRequirement(true) != -1) {
                c.getAbstractPlayerInteraction().forceCompleteQuest(questId, quest.getNpcRequirement(true));
            } else {
                c.getAbstractPlayerInteraction().forceCompleteQuest(questId);
            }

            player.dropMessage(5, "QUEST " + questId + " completed.");
        } else {
            player.dropMessage(5, "QUESTID " + questId + " not started or already completed.");
        }
    }
}
