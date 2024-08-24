/*
	This file is part of the OdinMS Maple Story Server
    Copyright (C) 2008 Patrick Huy <patrick.huy@frz.cc>
		       Matthias Butz <matze@odinms.de>
		       Jan Christian Meyer <vimes@odinms.de>

    Copyleft (L) 2016 - 2019 RonanLana (HeavenMS)

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
package client.processor.stat;

import client.Character;
import client.Client;
import client.Skill;
import client.SkillFactory;
import client.autoban.AutobanFactory;
import constants.game.GameConstants;
import constants.skills.Aran;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import tools.PacketCreator;

/**
 * @author RonanLana - synchronization of SP transaction modules
 */
public class AssignSPProcessor {
    private static final Logger log = LoggerFactory.getLogger(AssignSPProcessor.class);

    public static boolean canSPAssign(Client c, int skillid) {
        if (skillid == Aran.HIDDEN_FULL_DOUBLE || skillid == Aran.HIDDEN_FULL_TRIPLE || skillid == Aran.HIDDEN_OVER_DOUBLE || skillid == Aran.HIDDEN_OVER_TRIPLE) {
            c.sendPacket(PacketCreator.enableActions());
            return false;
        }

        Character player = c.getPlayer();
        if ((!GameConstants.isPqSkillMap(player.getMapId()) && GameConstants.isPqSkill(skillid)) || (!player.isGM() && GameConstants.isGMSkills(skillid)) || (!GameConstants.isInJobTree(skillid, player.getJob().getId()) && !player.isGM())) {
            AutobanFactory.PACKET_EDIT.alert(player, "tried to packet edit in distributing sp.");
            log.warn("Chr {} tried to use skill {} without it being in their job.", c.getPlayer().getName(), skillid);

            c.disconnect(true, false);
            return false;
        }

        return true;
    }

    public static void SPAssignAction(Client c, int skillid) {
        c.lockClient();
        try {
            if (!canSPAssign(c, skillid)) {
                return;
            }

            Character player = c.getPlayer();
            int remainingSp = player.getRemainingSps()[GameConstants.getSkillBook(skillid / 10000)];
            boolean isBeginnerSkill = false;

            if (skillid % 10000000 > 999 && skillid % 10000000 < 1003) {
                int total = 0;
                for (int i = 0; i < 3; i++) {
                    total += player.getSkillLevel(SkillFactory.getSkill(player.getJobType() * 10000000 + 1000 + i));
                }
                remainingSp = Math.min((player.getLevel() - 1), 6) - total;
                isBeginnerSkill = true;
            }
            Skill skill = SkillFactory.getSkill(skillid);
            int curLevel = player.getSkillLevel(skill);
            if ((remainingSp > 0 && curLevel + 1 <= (skill.isFourthJob() ? player.getMasterLevel(skill) : skill.getMaxLevel()))) {
                if (!isBeginnerSkill) {
                    player.gainSp(-1, GameConstants.getSkillBook(skillid / 10000), false);
                } else {
                    player.sendPacket(PacketCreator.enableActions());
                }
                if (skill.getId() == Aran.FULL_SWING) {
                    player.changeSkillLevel(skill, (byte) (curLevel + 1), player.getMasterLevel(skill), player.getSkillExpiration(skill));
                    player.changeSkillLevel(SkillFactory.getSkill(Aran.HIDDEN_FULL_DOUBLE), player.getSkillLevel(skill), player.getMasterLevel(skill), player.getSkillExpiration(skill));
                    player.changeSkillLevel(SkillFactory.getSkill(Aran.HIDDEN_FULL_TRIPLE), player.getSkillLevel(skill), player.getMasterLevel(skill), player.getSkillExpiration(skill));
                } else if (skill.getId() == Aran.OVER_SWING) {
                    player.changeSkillLevel(skill, (byte) (curLevel + 1), player.getMasterLevel(skill), player.getSkillExpiration(skill));
                    player.changeSkillLevel(SkillFactory.getSkill(Aran.HIDDEN_OVER_DOUBLE), player.getSkillLevel(skill), player.getMasterLevel(skill), player.getSkillExpiration(skill));
                    player.changeSkillLevel(SkillFactory.getSkill(Aran.HIDDEN_OVER_TRIPLE), player.getSkillLevel(skill), player.getMasterLevel(skill), player.getSkillExpiration(skill));
                } else {
                    player.changeSkillLevel(skill, (byte) (curLevel + 1), player.getMasterLevel(skill), player.getSkillExpiration(skill));
                }
            }
            if(skill.getId() == 3121013) {
                player.changeSkillLevel(SkillFactory.getSkill(3121013), (byte) (player.getReborns() + 1), (player.getReborns() + 1), -1);
                player.changeSkillLevel(SkillFactory.getSkill(8001002), (byte) (player.getReborns() + 1), (player.getReborns() + 1), -1);
                player.changeSkillLevel(SkillFactory.getSkill(8001003), (byte) (player.getReborns() + 1), (player.getReborns() + 1), -1);
                player.changeSkillLevel(SkillFactory.getSkill(8001004), (byte) (player.getReborns() + 1), (player.getReborns() + 1), -1);
            }
        } finally {
            c.unlockClient();
        }
    }
}
