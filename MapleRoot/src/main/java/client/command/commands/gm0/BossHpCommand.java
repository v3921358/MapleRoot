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
package client.command.commands.gm0;

import client.Character;
import client.Client;
import client.command.Command;
import server.life.Monster;

public class BossHpCommand extends Command {
    {
        setDescription("Show HP of bosses on current map.");
    }

    @Override
    public void execute(Client c, String[] params) {
        Character player = c.getPlayer();
        for (Monster monster : player.getMap().getAllMonsters()) {
            if (monster != null && monster.isBoss() && monster.getHp() > 0) {
                long percent = monster.getHp() * 100L / monster.getMaxHp();
                String bar = "[";
                for (int i = 0; i < 100; i++) {
                    bar += i < percent ? "|" : ".";
                }
                bar += "]";
                player.yellowMessage(monster.getName() + " (" + monster.getId() + ") has " + percent + "% HP left.");
                player.yellowMessage("HP: " + bar);
            }
        }
    }
}
