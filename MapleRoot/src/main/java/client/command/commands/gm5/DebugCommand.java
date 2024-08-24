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
package client.command.commands.gm5;

import client.Character;
import client.Client;
import client.command.Command;
import constants.id.NpcId;
import net.server.Server;
import server.TimerManager;
import server.life.Monster;
import server.life.SpawnPoint;
import server.maps.MapObject;
import server.maps.MapObjectType;
import server.maps.Portal;
import server.maps.Reactor;

import java.awt.*;
import java.util.Arrays;
import java.util.List;

public class DebugCommand extends Command {
    private final static String[] debugTypes = {"monster", "packet", "portal", "spawnpoint", "pos", "map", "mobsp", "event", "areas", "reactors", "servercoupons", "playercoupons", "timer", "marriage", "buff", ""};

    {
        setDescription("Show a debug message.");
    }

    @Override
    public void execute(Client c, String[] params) {
        Character player = c.getPlayer();

        if (params.length < 1) {
            player.yellowMessage("Syntax: !debug <type>");
            return;
        }

        switch (params[0]) {
            case "type":
            case "help":
                String msgTypes = "Available #bdebug types#k:\r\n\r\n";
                for (int i = 0; i < debugTypes.length; i++) {
                    msgTypes += ("#L" + i + "#" + debugTypes[i] + "#l\r\n");
                }

                c.getAbstractPlayerInteraction().npcTalk(NpcId.STEWARD, msgTypes);
                break;

            case "monster":
                List<MapObject> monsters = player.getMap().getMapObjectsInRange(player.getPosition(), Double.POSITIVE_INFINITY, Arrays.asList(MapObjectType.MONSTER));
                for (MapObject monstermo : monsters) {
                    Monster monster = (Monster) monstermo;
                    Character controller = monster.getController();
                    player.message("Monster ID: " + monster.getId() + " Aggro target: " + ((controller != null) ? controller.getName() + " Has aggro: " + monster.isControllerHasAggro() + " Knowns aggro: " + monster.isControllerKnowsAboutAggro() : "<none>"));
                }
                break;

            case "packet":
                //player.getMap().broadcastMessage(PacketCreator.customPacket(joinStringFrom(params, 1)));
                break;

            case "portal":
                Portal portal = player.getMap().findClosestPortal(player.getPosition());
                if (portal != null) {
                    player.dropMessage(6, "Closest portal: " + portal.getId() + " '" + portal.getName() + "' Type: " + portal.getType() + " --> toMap: " + portal.getTargetMapId() + " scriptname: '" + portal.getScriptName() + "' state: " + (portal.getPortalState() ? 1 : 0) + ".");
                } else {
                    player.dropMessage(6, "There is no portal on this map.");
                }
                break;

            case "spawnpoint":
                SpawnPoint sp = player.getMap().findClosestSpawnpoint(player.getPosition());
                if (sp != null) {
                    player.dropMessage(6, "Closest mob spawn point: " + " Position: x " + sp.getPosition().getX() + " y " + sp.getPosition().getY() + " Spawns mobid: '" + sp.getMonsterId() + "' --> canSpawn: " + !sp.getDenySpawn() + " canSpawnRightNow: " + sp.shouldSpawn() + ".");
                } else {
                    player.dropMessage(6, "There is no mob spawn point on this map.");
                }
                break;

            case "pos":
                player.dropMessage(6, "Current map position: (" + player.getPosition().getX() + ", " + player.getPosition().getY() + ").");
                break;

            case "map":
                player.dropMessage(6, "Current map id " + player.getMap().getId() + ", event: '" + ((player.getMap().getEventInstance() != null) ? player.getMap().getEventInstance().getName() : "null") + "'; Players: " + player.getMap().getAllPlayers().size() + ", Mobs: " + player.getMap().countMonsters() + ", Reactors: " + player.getMap().countReactors() + ", Items: " + player.getMap().countItems() + ", Objects: " + player.getMap().getMapObjects().size() + ".");
                break;

            case "mobsp":
                player.getMap().reportMonsterSpawnPoints(player);
                break;

            case "event":
                if (player.getEventInstance() == null) {
                    player.dropMessage(6, "Player currently not in an event.");
                } else {
                    player.dropMessage(6, "Current event name: " + player.getEventInstance().getName() + ".");
                }
                break;

            case "areas":
                player.dropMessage(6, "Configured areas on map " + player.getMapId() + ":");

                byte index = 0;
                for (Rectangle rect : player.getMap().getAreas()) {
                    player.dropMessage(6, "Id: " + index + " -> posX: " + rect.getX() + " posY: '" + rect.getY() + "' dX: " + rect.getWidth() + " dY: " + rect.getHeight() + ".");
                    index++;
                }
                break;

            case "reactors":
                player.dropMessage(6, "Current reactor states on map " + player.getMapId() + ":");

                for (MapObject mmo : player.getMap().getReactors()) {
                    Reactor mr = (Reactor) mmo;
                    player.dropMessage(6, "Id: " + mr.getId() + " Oid: " + mr.getObjectId() + " name: '" + mr.getName() + "' -> Type: " + mr.getReactorType() + " State: " + mr.getState() + " Event State: " + mr.getEventState() + " Position: x " + mr.getPosition().getX() + " y " + mr.getPosition().getY() + ".");
                }
                break;

            case "servercoupons":
            case "coupons":
                String s = "Currently active SERVER coupons: ";
                for (Integer i : Server.getInstance().getActiveCoupons()) {
                    s += (i + " ");
                }

                player.dropMessage(6, s);
                break;

            case "playercoupons":
                String st = "Currently active PLAYER coupons: ";
                for (Integer i : player.getActiveCoupons()) {
                    st += (i + " ");
                }

                player.dropMessage(6, st);
                break;

            case "timer":
                TimerManager tMan = TimerManager.getInstance();
                player.dropMessage(6, "Total Task: " + tMan.getTaskCount() + " Current Task: " + tMan.getQueuedTasks() + " Active Task: " + tMan.getActiveCount() + " Completed Task: " + tMan.getCompletedTaskCount());
                break;

            case "marriage":
                c.getChannelServer().debugMarriageStatus();
                break;

            case "buff":
                c.getPlayer().debugListAllBuffs();
                break;
        }
    }
}
