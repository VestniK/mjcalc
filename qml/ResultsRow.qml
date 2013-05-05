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

Item {
    property alias column1: col1.text
    property alias column2: col2.text
    property alias column3: col3.text
    property alias column4: col4.text
    property bool head: false
    height: childrenRect.height
    Text {
        id: col1
        text: "0"
        anchors.left: parent.left
        anchors.top: parent.top
        width: parent.width/4
        font.bold: parent.head
    }
    Text {
        id: col2
        text: "0"
        anchors.left: col1.right
        anchors.top: parent.top
        width: parent.width/4
        font.bold: parent.head
    }
    Text {
        id: col3
        text: "0"
        anchors.left: col2.right
        anchors.top: parent.top
        width: parent.width/4
        font.bold: parent.head
    }
    Text {
        id: col4
        text: "0"
        anchors.left: col3.right
        anchors.top: parent.top
        width: parent.width/4
        font.bold: parent.head
    }
}
