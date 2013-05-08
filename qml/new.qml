/*
 * Mahjong calculator is simple tool to calculate totals by hands scores.
 * Copyright (C) 2013  Sergey Vidyuk <sir.vestnik@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

import QtQuick 1.0

Background {
    id: canvas
    Style {id: globalStyle}
    Flickable {
        anchors {
            fill: parent
        }
        contentWidth: parent.width
        contentHeight: childrenRect.height

        Column {
            spacing: globalStyle.margins
            width: parent.width
            NameInput {
                id: eastName
                width: parent.width
                icon: "east.svg"
                focus: true
            }
            NameInput {
                id: southName
                width: parent.width
                icon: "south.svg"
            }
            NameInput {
                id: westName
                width: parent.width
                icon: "west.svg"
            }
            NameInput {
                id: northName
                width: parent.width
                icon: "north.svg"
            }
        }
    }

    Pannel {
        id: toolbar
        backButton: !game.isEmpty()
        onBack: game.showMainPage()
        PannelButton {
            id: newBtn
            icon: "new.svg"
            onButtonClicked: {
                if (eastName.text.length == 0 || southName.text.length == 0 || westName.text.length == 0 || northName.text.length == 0) {
                    canvas.riseError(qsTr("Some names are missing."));
                    return;
                }
                game.player1 = eastName.text;
                game.player2 = southName.text;
                game.player3 = westName.text;
                game.player4 = northName.text;
                game.start();
            }
        }
    }
}
