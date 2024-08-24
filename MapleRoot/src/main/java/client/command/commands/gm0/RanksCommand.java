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
import constants.id.NpcId;
import net.server.Server;
import net.server.guild.GuildPackets;
import tools.Pair;

import java.util.List;

public class RanksCommand extends Command {
    {
        setDescription("Show player rankings.");
    }

    @Override
    public void execute(Client c, String[] params) {
        Character player = c.getPlayer();

        List<Pair<String, Integer>> worldRanking = Server.getInstance().getWorldPlayerRanking(player.getWorld());
        player.sendPacket(GuildPackets.showPlayerRanks(NpcId.MAPLE_ADMINISTRATOR, worldRanking));
    }
}
