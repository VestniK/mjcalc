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
    property alias text: name.text
    property alias icon: image.source

    height: childrenRect.height

    Image {
        id: image
        anchors {
            top: parent.top
            left: parent.left
            margins: globalStyle.margins
        }
        height: name.height
        fillMode: Image.PreserveAspectFit
        smooth: true
    }
    LineEdit {
        id: name
        anchors {
            top: parent.top
            left: image.right
            right: parent.right
            margins: globalStyle.margins
        }
        focus: parent.focus
    }
}
