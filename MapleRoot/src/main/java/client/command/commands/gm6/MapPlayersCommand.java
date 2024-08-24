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
package client.command.commands.gm6;

import client.Character;
import client.Client;
import client.command.Command;
import net.server.Server;
import net.server.world.World;

public class MapPlayersCommand extends Command {
    {
        setDescription("Show all players on the map.");
    }

    @Override
    public void execute(Client c, String[] params) {
        Character player = c.getPlayer();
        String names = "";
        int map = player.getMapId();
        for (World world : Server.getInstance().getWorlds()) {
            for (Character chr : world.getPlayerStorage().getAllCharacters()) {
                int curMap = chr.getMapId();
                String hp = Integer.toString(chr.getHp());
                String maxhp = Integer.toString(chr.getCurrentMaxHp());
                String name = chr.getName() + ": " + hp + "/" + maxhp;
                if (map == curMap) {
                    names = names.equals("") ? name : (names + ", " + name);
                }
            }
        }
        player.message("Players on mapid " + map + ": " + names);
    }
}
