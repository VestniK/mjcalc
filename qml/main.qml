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
    Style {id: globalStyle}

    Rectangle {
        border.color: globalStyle.textArea.borderColor
        border.width: globalStyle.textArea.borderWidth
        radius: globalStyle.textArea.borderRadius
        color: globalStyle.textArea.bgColor
        opacity: globalStyle.textArea.opacity

        anchors {
            margins: globalStyle.margins
            top: parent.top
            bottom: toolbar.top
            left: parent.left
            right: parent.right
        }

        ResultsRow {
            id: header
            head: true
            anchors {
                margins: globalStyle.margins
                left: parent.left
                right: parent.right
            }
            column1: game.player1; column2: game.player2; column3: game.player3; column4: game.player4;
        }
        ListView {
            anchors {
                margins: globalStyle.margins
                left: parent.left
                right: parent.right
                top: header.bottom
                bottom: parent.bottom
            }
            clip: true
            model: game.results
            delegate: ResultsRow {
                anchors {
                    margins: globalStyle.margins
                    left: parent.left
                    right: parent.right
                }
                column1: totals1; column2: totals2; column3: totals3; column4: totals4;
            }
        }
    }

    Pannel {
        id: toolbar
        PannelButton {
            id: newBtn
            icon: "new.svg"
            onButtonClicked: game.showNewPage()
        }
        PannelButton {
            id: addBtn
            icon: "add.svg"
            onButtonClicked: game.showAddScores()
        }
    }
}
