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

/*
 * @Name         KIN
 * @Author:      Signalize
 * @NPC:         9900001
 * @Purpose:     Levels people up.
 */
function start() {
    if (cm.getPlayer().gmLevel() > 1) {
        cm.sendYesNo("Do you want to level up?");
    } else {
        cm.sendOk("Hey wassup?");
    }
}

function action(i, am, pro) {
    if (i > 0 && cm.getPlayer().gmLevel() > 1) {
        cm.getPlayer().levelUp(true);
    }
    cm.dispose();
}