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
package server.maps;

import client.Character;
import client.Client;
import client.SkillFactory;
import tools.PacketCreator;

import java.awt.*;

/**
 * @author Jan
 */
public class Summon extends AbstractAnimatedMapObject {
    private final Character owner;
    private final byte skillLevel;
    private final int skill;
    private int hp;
    private final SummonMovementType movementType;

    public Summon(Character owner, int skill, Point pos, SummonMovementType movementType) {
        if (!owner.arrowplatterrunning && skill == 3121013) {
            owner.prepareArrowPlatter();
        } else if(!owner.arrowplatterrunning1 && skill == 3121013 && owner.getReborns() >= 1) {
            skill= 8001002;
            owner.prepareArrowPlatter1();
        } else if(!owner.arrowplatterrunning2 && skill == 3121013 && owner.getReborns() >= 2) {
            skill = 8001003;
            owner.prepareArrowPlatter2();
        } else if(!owner.arrowplatterrunning3 && skill == 3121013 && owner.getReborns() == 3) {
            skill = 8001004;
            owner.prepareArrowPlatter3();
        }
        this.skill = skill;
        owner.currsummonid = this.skill;
        this.owner = owner;
        this.skillLevel = owner.getSkillLevel(SkillFactory.getSkill(skill));
        if (skillLevel == 0) {
            throw new RuntimeException();
        }

        this.movementType = movementType;
        setPosition(pos);
    }

    @Override
    public void sendSpawnData(Client client) {
        client.sendPacket(PacketCreator.spawnSummon(this, false));
    }

    @Override
    public void sendDestroyData(Client client) {
        client.sendPacket(PacketCreator.removeSummon(this, true));
    }

    public Character getOwner() {
        return owner;
    }

    public int getSkill() {
        return skill;
    }

    public int getHP() {
        return hp;
    }

    public void addHP(int delta) {
        this.hp += delta;
    }

    public SummonMovementType getMovementType() {
        return movementType;
    }

    public boolean isStationary() {
        return (skill == 3111002 || skill == 3211002 || skill == 5211001 || skill == 13111004);
    }

    public byte getSkillLevel() {
        return skillLevel;
    }

    @Override
    public MapObjectType getType() {
        return MapObjectType.SUMMON;
    }

    public final boolean isPuppet() {
        switch (skill) {
            case 3111002:
            case 3211002:
            case 13111004:
                return true;
        }
        return false;
    }
}
