/*
 This file is part of the OdinMS Maple Story Server
 Copyright (C) 2008 Patrick Huy <patrick.huy@frz.cc>
 Matthias Butz <matze@odinms.de>
 Jan Christian Meyer <vimes@odinms.de>

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
package net.server.channel.handlers;

import client.Character;
import client.Client;
import client.SkillFactory;
import constants.game.GameConstants;
import constants.skills.Aran;
import net.AbstractPacketHandler;
import net.packet.InPacket;

public class AranComboHandler extends AbstractPacketHandler {

    @Override
    public void handlePacket(InPacket p, Client c) {
        final Character player = c.getPlayer();
        int skillLevel = player.getSkillLevel(SkillFactory.getSkill(Aran.COMBO_ABILITY));
        if (skillLevel > 0) {
            final long currentTime = currentServerTime();
            short combo = player.getCombo();
            if ((currentTime - player.getLastCombo()) > 6000 && combo > 0) {
                combo = 0;
            }
            combo++;
            switch (combo) {
                case 10:
                case 20:
                case 30:
                case 40:
                case 50:
                case 60:
                case 70:
                case 80:
                case 90:
                case 100:
                    if (player.getJob().getId() != 2000 && (combo / 10) > skillLevel) {
                        break;
                    }
                    SkillFactory.getSkill(Aran.COMBO_ABILITY).getEffect(combo / 10).applyComboBuff(player, combo);
                    break;
            }
            player.setCombo(combo);
            player.setLastCombo(currentTime);
        }
    }
}
