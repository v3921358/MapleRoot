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
package net.server.guild;

import client.Character;

public class GuildCharacter {
    private Character character;
    private int level;
    private final int id;
    private int world, channel;
    private int jobid;
    private int guildrank;
    private int guildid;
    private int allianceRank;
    private boolean online;
    private final String name;

    public GuildCharacter(Character chr) {
        this.character = chr;
        this.name = chr.getName();
        this.level = chr.getLevel();
        this.id = chr.getId();
        this.channel = chr.getClient().getChannel();
        this.world = chr.getWorld();
        this.jobid = chr.getJob().getId();
        this.guildrank = chr.getGuildRank();
        this.guildid = chr.getGuildId();
        this.online = true;
        this.allianceRank = chr.getAllianceRank();
    }

    public GuildCharacter(Character chr, int _id, int _lv, String _name, int _channel, int _world, int _job, int _rank, int _gid, boolean _on, int _allianceRank) {
        this.character = chr;
        this.level = _lv;
        this.id = _id;
        this.name = _name;
        if (_on) {
            this.channel = _channel;
            this.world = _world;
        }
        this.jobid = _job;
        this.online = _on;
        this.guildrank = _rank;
        this.guildid = _gid;
        this.allianceRank = _allianceRank;
    }

    public void setCharacter(Character ch) {
        this.character = ch;
    }

    public Character getCharacter() {
        return character;
    }

    public int getLevel() {
        return level;
    }

    public void setLevel(int l) {
        level = l;
    }

    public int getId() {
        return id;
    }

    public void setChannel(int ch) {
        channel = ch;
    }

    public int getChannel() {
        return channel;
    }

    public int getWorld() {
        return world;
    }

    public int getJobId() {
        return jobid;
    }

    public void setJobId(int job) {
        jobid = job;
    }

    public int getGuildId() {
        return guildid;
    }

    public void setGuildId(int gid) {
        guildid = gid;
        character.setGuildId(gid);
    }

    public int getGuildRank() {
        return guildrank;
    }

    public void setOfflineGuildRank(int rank) {
        guildrank = rank;
    }

    public void setGuildRank(int rank) {
        guildrank = rank;
        character.setGuildRank(rank);
    }

    public int getAllianceRank() {
        return allianceRank;
    }

    public void setAllianceRank(int rank) {
        allianceRank = rank;
        character.setAllianceRank(rank);
    }

    public boolean isOnline() {
        return online;
    }

    public void setOnline(boolean f) {
        online = f;
    }

    public String getName() {
        return name;
    }

    @Override
    public boolean equals(Object other) {
        if (other instanceof GuildCharacter o) {
            return (o.getId() == id && o.getName().equals(name));
        }
        return false;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 19 * hash + this.id;
        hash = 19 * hash + (this.name != null ? this.name.hashCode() : 0);
        return hash;
    }
}
