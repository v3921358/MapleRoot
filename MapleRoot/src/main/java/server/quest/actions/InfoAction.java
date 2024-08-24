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
package server.quest.actions;

import client.Character;
import provider.Data;
import provider.DataTool;
import server.quest.Quest;
import server.quest.QuestActionType;

/**
 * @author Ronan
 */
public class InfoAction extends AbstractQuestAction {

    private String info;
    private final int questID;

    public InfoAction(Quest quest, Data data) {
        super(QuestActionType.INFO, quest);
        questID = quest.getId();
        processData(data);
    }

    @Override
    public void processData(Data data) {
        info = DataTool.getString(data, "");
    }


    @Override
    public void run(Character chr, Integer extSelection) {
        chr.getAbstractPlayerInteraction().setQuestProgress(questID, info);
    }

}
