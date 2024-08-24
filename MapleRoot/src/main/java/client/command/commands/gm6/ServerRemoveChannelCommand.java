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
import server.ThreadManager;

public class ServerRemoveChannelCommand extends Command {
    {
        setDescription("Remove channel from a world.");
    }

    @Override
    public void execute(Client c, String[] params) {
        final Character player = c.getPlayer();

        if (params.length < 1) {
            player.dropMessage(5, "Syntax: @removechannel <worldid>");
            return;
        }

        final int worldId = Integer.parseInt(params[0]);
        ThreadManager.getInstance().newTask(() -> {
            if (Server.getInstance().removeChannel(worldId)) {
                if (player.isLoggedinWorld()) {
                    player.dropMessage(5, "Successfully removed a channel on World " + worldId + ". Current channel count: " + Server.getInstance().getWorld(worldId).getChannelsSize() + ".");
                }
            } else {
                if (player.isLoggedinWorld()) {
                    player.dropMessage(5, "Failed to remove last Channel on world " + worldId + ". Check if either that world exists or there are people currently playing there.");
                }
            }
        });
    }
}
