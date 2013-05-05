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

Rectangle {
    property alias validator: inputArea.validator
    property alias text: inputArea.text

    border.color: globalStyle.textArea.borderColor
    border.width: globalStyle.textArea.borderWidth
    radius: globalStyle.textArea.borderRadius
    color: globalStyle.textArea.bgColor
    opacity: globalStyle.textArea.opacity
    height: childrenRect.height + inputArea.anchors.topMargin + inputArea.anchors.bottomMargin

    TextInput {
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            margins: globalStyle.margins
        }
        id: inputArea
        font.family: globalStyle.labelFont
        font.pointSize: globalStyle.labelFontSize
        color: "black"
        focus: parent.focus
        Timer {
            id: onFocusSelectDelayer; interval: 100; repeat: false; triggeredOnStart: false
            onTriggered: {inputArea.selectAll()}
        }
        onActiveFocusChanged: {
            if (activeFocus == true)
                onFocusSelectDelayer.start();
        }
    }
}
