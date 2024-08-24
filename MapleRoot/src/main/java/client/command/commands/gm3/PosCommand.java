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

public class PosCommand extends Command {
    {
        setDescription("Show current position and foothold.");
    }

    @Override
    public void execute(Client c, String[] params) {
        Character player = c.getPlayer();
        float xpos = player.getPosition().x;
        float ypos = player.getPosition().y;
        float fh = player.getMap().getFootholds().findBelow(player.getPosition()).getId();
        player.dropMessage(6, "Position: (" + xpos + ", " + ypos + ")");
        player.dropMessage(6, "Foothold ID: " + fh);
    }
}
