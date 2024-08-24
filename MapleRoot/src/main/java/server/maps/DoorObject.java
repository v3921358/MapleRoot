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
package server.maps;

import client.Character;
import client.Client;
import constants.id.MapId;
import net.server.world.Party;
import tools.PacketCreator;

import java.awt.*;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

/**
 * @author Ronan
 */
public class DoorObject extends AbstractMapObject {
    private final int ownerId;
    private int pairOid;

    private final MapleMap from;
    private final MapleMap to;
    private int linkedPortalId;
    private Point linkedPos;

    private final Lock rlock;
    private final Lock wlock;

    public DoorObject(int owner, MapleMap destination, MapleMap origin, int townPortalId, Point targetPosition, Point toPosition) {
        super();
        setPosition(targetPosition);

        ownerId = owner;
        linkedPortalId = townPortalId;
        from = origin;
        to = destination;
        linkedPos = toPosition;

        ReadWriteLock lock = new ReentrantReadWriteLock(true);
        this.rlock = lock.readLock();
        this.wlock = lock.writeLock();
    }

    public void update(int townPortalId, Point toPosition) {
        wlock.lock();
        try {
            linkedPortalId = townPortalId;
            linkedPos = toPosition;
        } finally {
            wlock.unlock();
        }
    }

    private int getLinkedPortalId() {
        rlock.lock();
        try {
            return linkedPortalId;
        } finally {
            rlock.unlock();
        }
    }

    private Point getLinkedPortalPosition() {
        rlock.lock();
        try {
            return linkedPos;
        } finally {
            rlock.unlock();
        }
    }

    public void warp(final Character chr) {
        Party party = chr.getParty();
        if (chr.getId() == ownerId || (party != null && party.getMemberById(ownerId) != null)) {
            chr.sendPacket(PacketCreator.playPortalSound());

            if (!inTown() && party == null) {
                chr.changeMap(to, getLinkedPortalId());
            } else {
                chr.changeMap(to, getLinkedPortalPosition());
            }
        } else {
            chr.sendPacket(PacketCreator.blockedMessage(6));
            chr.sendPacket(PacketCreator.enableActions());
        }
    }

    @Override
    public void sendSpawnData(Client client) {
        sendSpawnData(client, true);
    }

    public void sendSpawnData(Client client, boolean launched) {
        Character chr = client.getPlayer();
        if (this.getFrom().getId() == chr.getMapId()) {
            if (chr.getParty() != null && (this.getOwnerId() == chr.getId() || chr.getParty().getMemberById(this.getOwnerId()) != null)) {
                chr.sendPacket(PacketCreator.partyPortal(this.getFrom().getId(), this.getTo().getId(), this.toPosition()));
            }

            chr.sendPacket(PacketCreator.spawnPortal(this.getFrom().getId(), this.getTo().getId(), this.toPosition()));
            if (!this.inTown()) {
                chr.sendPacket(PacketCreator.spawnDoor(this.getOwnerId(), this.getPosition(), launched));
            }
        }
    }

    @Override
    public void sendDestroyData(Client client) {
        Character chr = client.getPlayer();
        if (from.getId() == chr.getMapId()) {
            Party party = chr.getParty();
            if (party != null && (ownerId == chr.getId() || party.getMemberById(ownerId) != null)) {
                client.sendPacket(PacketCreator.partyPortal(MapId.NONE, MapId.NONE, new Point(-1, -1)));
            }
            client.sendPacket(PacketCreator.removeDoor(ownerId, inTown()));
        }
    }

    public void sendDestroyData(Client client, boolean partyUpdate) {
        if (client != null && from.getId() == client.getPlayer().getMapId()) {
            client.sendPacket(PacketCreator.partyPortal(MapId.NONE, MapId.NONE, new Point(-1, -1)));
            client.sendPacket(PacketCreator.removeDoor(ownerId, inTown()));
        }
    }

    public int getOwnerId() {
        return ownerId;
    }

    public void setPairOid(int oid) {
        this.pairOid = oid;
    }

    public int getPairOid() {
        return pairOid;
    }

    public boolean inTown() {
        return getLinkedPortalId() == -1;
    }

    public MapleMap getFrom() {
        return from;
    }

    public MapleMap getTo() {
        return to;
    }

    public MapleMap getTown() {
        return inTown() ? from : to;
    }

    public MapleMap getArea() {
        return !inTown() ? from : to;
    }

    public Point getAreaPosition() {
        return !inTown() ? getPosition() : getLinkedPortalPosition();
    }

    public Point toPosition() {
        return getLinkedPortalPosition();
    }

    @Override
    public MapObjectType getType() {
        return MapObjectType.DOOR;
    }
}
