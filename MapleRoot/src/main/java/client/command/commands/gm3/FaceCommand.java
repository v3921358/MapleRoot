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
import client.Stat;
import client.command.Command;
import constants.inventory.ItemConstants;
import server.ItemInformationProvider;

public class FaceCommand extends Command {
    {
        setDescription("Change face of a player.");
    }

    @Override
    public void execute(Client c, String[] params) {
        Character player = c.getPlayer();
        if (params.length < 1) {
            player.yellowMessage("Syntax: !face [<playername>] <faceid>");
            return;
        }

        try {
            if (params.length == 1) {
                int itemId = Integer.parseInt(params[0]);
                if (!ItemConstants.isFace(itemId) || ItemInformationProvider.getInstance().getName(itemId) == null) {
                    player.yellowMessage("Face id '" + params[0] + "' does not exist.");
                    return;
                }

                player.setFace(itemId);
                player.updateSingleStat(Stat.FACE, itemId);
                player.equipChanged();
            } else {
                int itemId = Integer.parseInt(params[1]);
                if (!ItemConstants.isFace(itemId) || ItemInformationProvider.getInstance().getName(itemId) == null) {
                    player.yellowMessage("Face id '" + params[1] + "' does not exist.");
                }

                Character victim = c.getChannelServer().getPlayerStorage().getCharacterByName(params[0]);
                if (victim != null) {
                    victim.setFace(itemId);
                    victim.updateSingleStat(Stat.FACE, itemId);
                    victim.equipChanged();
                } else {
                    player.yellowMessage("Player '" + params[0] + "' has not been found on this channel.");
                }
            }
        } catch (Exception e) {
        }

    }
}
