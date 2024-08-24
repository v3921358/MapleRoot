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
package client.processor.npc;

import client.Character;
import client.Client;
import client.autoban.AutobanFactory;
import client.inventory.Inventory;
import client.inventory.InventoryType;
import client.inventory.Item;
import client.inventory.ItemFactory;
import client.inventory.manipulator.InventoryManipulator;
import net.server.Server;
import net.server.world.World;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import server.ItemInformationProvider;
import server.maps.HiredMerchant;
import server.maps.PlayerShopItem;
import service.NoteService;
import tools.DatabaseConnection;
import tools.FilePrinter;
import tools.PacketCreator;
import tools.Pair;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.sql.ResultSet;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.LinkedList;
import java.util.List;

import static java.util.concurrent.TimeUnit.DAYS;

/**
 * @author RonanLana - synchronization of Fredrick modules and operation results
 */
public class FredrickProcessor {
    private static final Logger log = LoggerFactory.getLogger(FredrickProcessor.class);
    private static final int[] dailyReminders = new int[]{2, 5, 10, 15, 30, 60, 90, Integer.MAX_VALUE};

    private final NoteService noteService;

    public FredrickProcessor(NoteService noteService) {
        this.noteService = noteService;
    }

    private static byte canRetrieveFromFredrick(Character chr, List<Pair<Item, InventoryType>> items) {
        if (!Inventory.checkSpotsAndOwnership(chr, items)) {
            List<Integer> itemids = new LinkedList<>();
            for (Pair<Item, InventoryType> it : items) {
                itemids.add(it.getLeft().getItemId());
            }

            if (chr.canHoldUniques(itemids)) {
                return 0x22;
            } else {
                return 0x20;
            }
        }

        int netMeso = chr.getMerchantNetMeso();
        if (netMeso > 0) {
            if (!chr.canHoldMeso(netMeso)) {
                return 0x1F;
            }
        } else {
            if (chr.getMeso() < -1 * netMeso) {
                return 0x21;
            }
        }

        return 0x0;
    }

    public static int timestampElapsedDays(Timestamp then, long timeNow) {
        return (int) ((timeNow - then.getTime()) / DAYS.toMillis(1));
    }

    private static String fredrickReminderMessage(int daynotes) {
        String msg;

        if (daynotes < 4) {
            msg = "Hi customer! I am Fredrick, the Union Chief of the Hired Merchant Union. A reminder that " + dailyReminders[daynotes] + " days have passed since you used our service. Please reclaim your stored goods at FM Entrance.";
        } else {
            msg = "Hi customer! I am Fredrick, the Union Chief of the Hired Merchant Union. " + dailyReminders[daynotes] + " days have passed since you used our service. Consider claiming back the items before we move them away for refund.";
        }

        return msg;
    }

    public static void removeFredrickLog(int cid) {
        try (Connection con = DatabaseConnection.getConnection()) {
            removeFredrickLog(con, cid);
        } catch (SQLException sqle) {
            sqle.printStackTrace();
        }
    }

    private static void removeFredrickLog(Connection con, int cid) throws SQLException {
        try (PreparedStatement ps = con.prepareStatement("DELETE FROM `fredstorage` WHERE `cid` = ?")) {
            ps.setInt(1, cid);
            ps.executeUpdate();
        }
    }

    public static void insertFredrickLog(int cid) {
        try (Connection con = DatabaseConnection.getConnection()) {

            removeFredrickLog(con, cid);
            try (PreparedStatement ps = con.prepareStatement("INSERT INTO `fredstorage` (`cid`, `daynotes`, `timestamp`) VALUES (?, 0, ?)")) {
                ps.setInt(1, cid);
                ps.setTimestamp(2, new Timestamp(System.currentTimeMillis()));
                ps.executeUpdate();
            }
        } catch (SQLException sqle) {
            sqle.printStackTrace();
        }
    }

    private static void removeFredrickReminders(List<Pair<Integer, Integer>> expiredCids) {
        List<String> expiredCnames = new LinkedList<>();
        for (Pair<Integer, Integer> id : expiredCids) {
            String name = Character.getNameById(id.getLeft());
            if (name != null) {
                expiredCnames.add(name);
            }
        }

        try (Connection con = DatabaseConnection.getConnection();
             PreparedStatement ps = con.prepareStatement("DELETE FROM `notes` WHERE `from` LIKE ? AND `to` LIKE ?")) {
            ps.setString(1, "FREDRICK");

            for (String cname : expiredCnames) {
                ps.setString(2, cname);
                ps.executeBatch();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void runFredrickSchedule() {
        try (Connection con = DatabaseConnection.getConnection()) {
            List<Pair<Integer, Integer>> expiredCids = new LinkedList<>();
            List<Pair<Pair<Integer, String>, Integer>> notifCids = new LinkedList<>();
            try (PreparedStatement ps = con.prepareStatement("SELECT * FROM fredstorage f LEFT JOIN (SELECT id, name, world, lastLogoutTime FROM characters) AS c ON c.id = f.cid");
                 ResultSet rs = ps.executeQuery()) {
                long curTime = System.currentTimeMillis();

                while (rs.next()) {
                    int cid = rs.getInt("cid");
                    int world = rs.getInt("world");
                    Timestamp ts = rs.getTimestamp("timestamp");
                    int daynotes = Math.min(dailyReminders.length - 1, rs.getInt("daynotes"));

                    int elapsedDays = timestampElapsedDays(ts, curTime);
                    if (elapsedDays > 100) {
                        expiredCids.add(new Pair<>(cid, world));
                    } else {
                        int notifDay = dailyReminders[daynotes];

                        if (elapsedDays >= notifDay) {
                            do {
                                daynotes++;
                                notifDay = dailyReminders[daynotes];
                            } while (elapsedDays >= notifDay);

                            Timestamp logoutTs = rs.getTimestamp("lastLogoutTime");
                            int inactivityDays = timestampElapsedDays(logoutTs, curTime);

                            if (inactivityDays < 7 || daynotes >= dailyReminders.length - 1) {  // don't spam inactive players
                                String name = rs.getString("name");
                                notifCids.add(new Pair<>(new Pair<>(cid, name), daynotes));
                            }
                        }
                    }
                }

            }

            if (!expiredCids.isEmpty()) {
                try (PreparedStatement ps = con.prepareStatement("DELETE FROM `inventoryitems` WHERE `type` = ? AND `characterid` = ?")) {
                    ps.setInt(1, ItemFactory.MERCHANT.getValue());

                    for (Pair<Integer, Integer> cid : expiredCids) {
                        ps.setInt(2, cid.getLeft());
                        ps.addBatch();
                    }

                    ps.executeBatch();
                }

                try (PreparedStatement ps = con.prepareStatement("UPDATE `characters` SET `MerchantMesos` = 0 WHERE `id` = ?")) {
                    for (Pair<Integer, Integer> cid : expiredCids) {
                        ps.setInt(1, cid.getLeft());
                        ps.addBatch();

                        World wserv = Server.getInstance().getWorld(cid.getRight());
                        if (wserv != null) {
                            Character chr = wserv.getPlayerStorage().getCharacterById(cid.getLeft());
                            if (chr != null) {
                                chr.setMerchantMeso(0);
                            }
                        }
                    }

                    ps.executeBatch();
                }

                removeFredrickReminders(expiredCids);

                try (PreparedStatement ps = con.prepareStatement("DELETE FROM `fredstorage` WHERE `cid` = ?")) {
                    for (Pair<Integer, Integer> cid : expiredCids) {
                        ps.setInt(1, cid.getLeft());
                        ps.addBatch();
                    }

                    ps.executeBatch();
                }
            }

            if (!notifCids.isEmpty()) {
                try (PreparedStatement ps = con.prepareStatement("UPDATE `fredstorage` SET `daynotes` = ? WHERE `cid` = ?")) {
                    for (Pair<Pair<Integer, String>, Integer> cid : notifCids) {
                        ps.setInt(1, cid.getRight());
                        ps.setInt(2, cid.getLeft().getLeft());
                        ps.addBatch();

                        String msg = fredrickReminderMessage(cid.getRight() - 1);
                        noteService.sendNormal(msg, "FREDRICK", cid.getLeft().getRight());
                    }

                    ps.executeBatch();
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static boolean deleteFredrickItems(int cid) {
        try (Connection con = DatabaseConnection.getConnection();
             PreparedStatement ps = con.prepareStatement("DELETE FROM `inventoryitems` WHERE `type` = ? AND `characterid` = ?")) {
            ps.setInt(1, ItemFactory.MERCHANT.getValue());
            ps.setInt(2, cid);
            ps.executeUpdate();

            return true;
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }

    public void fredrickRetrieveItems(Client c) {     // thanks Gustav for pointing out the dupe on Fredrick handling
        if (c.tryacquireClient()) {
            try {
                Character chr = c.getPlayer();

                List<Pair<Item, InventoryType>> items;
                try {
                    items = ItemFactory.MERCHANT.loadItems(chr.getId(), false);

                    byte response = canRetrieveFromFredrick(chr, items);
                    if (response != 0) {
                        chr.sendPacket(PacketCreator.fredrickMessage(response));
                        return;
                    }

                    chr.withdrawMerchantMesos();

                    for (Pair<Item, InventoryType> it : items) {
                        Item item = it.getLeft();
                        String itemName = ItemInformationProvider.getInstance().getName(item.getItemId());
                        FilePrinter.print(FilePrinter.FREDRICK + chr.getName() + ".txt", chr.getName() + " put into Fredrick " + item.getQuantity() + " " + itemName + " (" + item.getItemId() + ")");
                    }

                    if (deleteFredrickItems(chr.getId())) {
                        HiredMerchant merchant = chr.getHiredMerchant();

                        if (merchant != null) {
                            StringBuilder itemsString = new StringBuilder();
                            for (PlayerShopItem playerShopItem : merchant.getItems()) {
                                itemsString.append(playerShopItem.getItem().getItemId()).append(":").append(playerShopItem.getItem().getQuantity()).append("\n");
                            }

                            AutobanFactory.PACKET_EDIT.alert(c.getPlayer(), c.getPlayer().getName() + " tried to packet edit (dupe) with merchant and Fredrick. This could be a false positive, the data has been logged.");

                            String logMessage = "[%s] %s tried to withdraw items from Fredrick with a merchant open. Items: %s".formatted(new SimpleDateFormat("HH:mm:ss").format(new Date()), c.getPlayer().getName(), itemsString);

                            FilePrinter.print(FilePrinter.FREDRICK + c.getPlayer().getName() + "_cleareditems.txt", logMessage);
                            log.debug(logMessage);

                            merchant.clearItems();

                            chr.getClient().disconnect(false, false);
                            //chr.autoban("duping");
                            return;
                        }

                        for (Pair<Item, InventoryType> it : items) {
                            Item item = it.getLeft();
                            InventoryManipulator.addFromDrop(chr.getClient(), item, false);
                            String itemName = ItemInformationProvider.getInstance().getName(item.getItemId());
                            FilePrinter.print(FilePrinter.FREDRICK + chr.getName() + ".txt", chr.getName() + " gained " + item.getQuantity() + " " + itemName + " (" + item.getItemId() + ")");                            log.debug("Chr {} gained {}x {} ({})", chr.getName(), item.getQuantity(), itemName, item.getItemId());
                        }

                        chr.sendPacket(PacketCreator.fredrickMessage((byte) 0x1E));
                        removeFredrickLog(chr.getId());
                    } else {
                        chr.message("An unknown error has occured.");
                    }
                } catch (SQLException ex) {
                    ex.printStackTrace();
                }
            } finally {
                c.releaseClient();
            }
        }
    }
}
