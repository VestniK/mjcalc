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
    gradient: Gradient {
        GradientStop { position: 0.0; color: "lightgreen" }
        GradientStop { position: 1.0; color: "green" }
    }
    width: 240
    height: 320

    Image {
        anchors.centerIn: parent
        source: "rdragon.svg"
        width: parent.width/2
        fillMode: Image.PreserveAspectFit
        smooth: true
    }

    property variant msgBox: messageBox
    MessageBox {
        id: messageBox
        anchors.centerIn: parent
        z: 1.0
        visible: false;
    }
}
