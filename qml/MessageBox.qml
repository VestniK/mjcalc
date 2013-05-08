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
    property alias text: message.text

    width: parent.width/2
    height: message.height + okBtn.height + 3*globalStyle.margins
    border.color: globalStyle.textArea.borderColor
    border.width: globalStyle.textArea.borderWidth
    radius: globalStyle.textArea.borderRadius
    color: globalStyle.textArea.bgColor
    opacity: globalStyle.textArea.opacity

    Text {
        id: message
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            margins: globalStyle.margins
        }
        font.family: globalStyle.labelFont
        font.pointSize: globalStyle.labelFontSize
        horizontalAlignment: Text.AlignJustify
        verticalAlignment: Text.AlignTop
        text: ""
        wrapMode: Text.WordWrap
    }
    TextButton {
        id: okBtn
        anchors {
            top: message.bottom
            horizontalCenter: parent.horizontalCenter
        }
        text: qsTr("Ok")
        onButtonClick: {
            parent.visible = false;
        }
    }
}
