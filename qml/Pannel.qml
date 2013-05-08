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

import QtQuick 1.1

Rectangle {
    default property alias buttons: buttonsRow.children
    property alias backButton: backBtn.visible
    anchors {
        bottom: parent.bottom
        left: parent.left
        right: parent.right
    }
    height: globalStyle.toolbar.height
    color: globalStyle.toolbar.bgColor
    opacity: globalStyle.toolbar.opacity

    signal back()

    PannelButton {
        id: backBtn
        anchors.left: parent.left
        anchors.margins: globalStyle.margins
        icon: "back.svg"
        onButtonClicked: back()
    }
    Row {
        id:buttonsRow
        spacing: globalStyle.margins
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            margins: globalStyle.margins
        }
    }
}
