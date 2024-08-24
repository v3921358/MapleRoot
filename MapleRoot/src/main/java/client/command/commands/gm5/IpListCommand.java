/*
    This file is part of the HeavenMS MapleStory Server
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
package client.command.commands.gm5;

import client.Character;
import client.Client;
import client.command.Command;
import constants.game.GameConstants;
import net.server.Server;
import net.server.world.World;

import java.util.Collection;

/**
 * @author Mist
 * @author Blood (Tochi)
 * @author Ronan
 */
public class IpListCommand extends Command {
    {
        setDescription("Show IP of all players.");
    }

    @Override
    public void execute(Client c, String[] params) {
        String str = "Player-IP relation:";

        for (World w : Server.getInstance().getWorlds()) {
            Collection<Character> chars = w.getPlayerStorage().getAllCharacters();

            if (!chars.isEmpty()) {
                str += "\r\n" + GameConstants.WORLD_NAMES[w.getId()] + "\r\n";

                for (Character chr : chars) {
                    str += "  " + chr.getName() + " - " + chr.getClient().getRemoteAddress() + "\r\n";
                }
            }
        }

        c.getAbstractPlayerInteraction().npcTalk(22000, str);
    }

}