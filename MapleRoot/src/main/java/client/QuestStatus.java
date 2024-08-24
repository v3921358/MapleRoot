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
package client;

import server.quest.Quest;
import tools.StringUtil;

import java.util.*;

/**
 * @author Matze
 */
public class QuestStatus {
    public enum Status {
        UNDEFINED(-1),
        NOT_STARTED(0),
        STARTED(1),
        COMPLETED(2);
        final int status;

        Status(int id) {
            status = id;
        }

        public int getId() {
            return status;
        }

        public static Status getById(int id) {
            for (Status l : Status.values()) {
                if (l.getId() == id) {
                    return l;
                }
            }
            return null;
        }
    }

    private final short questID;
    private Status status;
    //private boolean updated;   //maybe this can be of use for someone?
    private final Map<Integer, String> progress = new LinkedHashMap<>();
    private final List<Integer> medalProgress = new LinkedList<>();
    private int npc;
    private long completionTime, expirationTime;
    private int forfeited = 0, completed = 0;
    private String customData;

    public QuestStatus(Quest quest, Status status) {
        this.questID = quest.getId();
        this.setStatus(status);
        this.completionTime = System.currentTimeMillis();
        this.expirationTime = 0;
        //this.updated = true;
        if (status == Status.STARTED) {
            registerMobs();
        }
    }

    public QuestStatus(Quest quest, Status status, int npc) {
        this.questID = quest.getId();
        this.setStatus(status);
        this.setNpc(npc);
        this.completionTime = System.currentTimeMillis();
        this.expirationTime = 0;
        //this.updated = true;
        if (status == Status.STARTED) {
            registerMobs();
        }
    }

    public Quest getQuest() {
        return Quest.getInstance(questID);
    }

    public short getQuestID() {
        return questID;
    }

    public Status getStatus() {
        return status;
    }

    public final void setStatus(Status status) {
        this.status = status;
    }
    
    /*
    public boolean wasUpdated() {
        return updated;
    }
    
    private void setUpdated() {
        this.updated = true;
    }
    
    public void resetUpdated() {
        this.updated = false;
    }
    */

    public int getNpc() {
        return npc;
    }

    public final void setNpc(int npc) {
        this.npc = npc;
    }

    private void registerMobs() {
        for (int i : Quest.getInstance(questID).getRelevantMobs()) {
            progress.put(i, "000");
        }
        //this.setUpdated();
    }

    public boolean addMedalMap(int mapid) {
        if (medalProgress.contains(mapid)) {
            return false;
        }
        medalProgress.add(mapid);
        //this.setUpdated();
        return true;
    }

    public int getMedalProgress() {
        return medalProgress.size();
    }

    public List<Integer> getMedalMaps() {
        return medalProgress;
    }

    public boolean progress(int id) {
        String currentStr = progress.get(id);
        if (currentStr == null) {
            return false;
        }

        int current = Integer.parseInt(currentStr);
        if (current >= this.getQuest().getMobAmountNeeded(id)) {
            return false;
        }

        String str = StringUtil.getLeftPaddedStr(Integer.toString(++current), '0', 3);
        progress.put(id, str);
        //this.setUpdated();
        return true;
    }

    public void setProgress(int id, String pr) {
        progress.put(id, pr);
        //this.setUpdated();
    }

    public boolean madeProgress() {
        return progress.size() > 0;
    }

    public String getProgress(int id) {
        String ret = progress.get(id);
        if (ret == null) {
            return "";
        } else {
            return ret;
        }
    }

    public void resetProgress(int id) {
        setProgress(id, "000");
    }

    public void resetAllProgress() {
        for (Map.Entry<Integer, String> entry : progress.entrySet()) {
            setProgress(entry.getKey(), "000");
        }
    }

    public Map<Integer, String> getProgress() {
        return Collections.unmodifiableMap(progress);
    }

    public short getInfoNumber() {
        Quest q = this.getQuest();
        Status s = this.getStatus();

        return q.getInfoNumber(s);
    }

    public String getInfoEx(int index) {
        Quest q = this.getQuest();
        Status s = this.getStatus();

        return q.getInfoEx(s, index);
    }

    public List<String> getInfoEx() {
        Quest q = this.getQuest();
        Status s = this.getStatus();

        return q.getInfoEx(s);
    }

    public long getCompletionTime() {
        return completionTime;
    }

    public void setCompletionTime(long completionTime) {
        this.completionTime = completionTime;
    }

    public long getExpirationTime() {
        return expirationTime;
    }

    public void setExpirationTime(long expirationTime) {
        this.expirationTime = expirationTime;
    }

    public int getForfeited() {
        return forfeited;
    }

    public int getCompleted() {
        return completed;
    }

    public void setForfeited(int forfeited) {
        if (forfeited >= this.forfeited) {
            this.forfeited = forfeited;
        } else {
            throw new IllegalArgumentException("Can't set forfeits to something lower than before.");
        }
    }

    public void setCompleted(int completed) {
        if (completed >= this.completed) {
            this.completed = completed;
        } else {
            throw new IllegalArgumentException("Can't set completes to something lower than before.");
        }
    }

    public final void setCustomData(final String customData) {
        this.customData = customData;
    }

    public final String getCustomData() {
        return customData;
    }

    public String getProgressData() {
        StringBuilder str = new StringBuilder();
        for (String ps : progress.values()) {
            str.append(ps);
        }
        return str.toString();
    }
}
