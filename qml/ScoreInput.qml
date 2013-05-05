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
    property string name: ""
    property variant hand: null
    property alias icon: icon.source
    property alias text: score.text
    property alias target: binding.target // TODO: find out why cant just use "target: parent.hand" in the binding
    property alias property: binding.property // TODO: find out why cant just use "target: parent.hand" in the binding
    property alias iconRect: icon.childrenRect

    height: score.height + nameLbl.height + 3*globalStyle.margins

    signal selected()

    Image {
        id: icon
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            margins: globalStyle.margins
        }
        z: 1
        height: score.height + nameLbl.height
        fillMode: Image.PreserveAspectFit
        smooth: true

        MouseArea {
            anchors.fill: parent
            onClicked: parent.parent.selected()
        }
    }

    Text {
        id: nameLbl
        font.family: globalStyle.descriptionFont
        font.pointSize: globalStyle.descriptionFontSize
        font.italic: globalStyle.descriptionItalic
        font.bold: globalStyle.descriptionBold
        text: parent.name + ":"
        anchors {
            top: parent.top
            left: icon.right
            right: parent.right
            margins: globalStyle.margins
        }
    }

    LineEdit {
        id: score
        text: "0"
        anchors {
            top: nameLbl.bottom
            left: icon.right
            right: handIcon.left
            margins: globalStyle.margins
        }
        validator: IntValidator {bottom: 0; top: 1000000;}
        focus: parent.focus
    }

    Image {
        id: handIcon
        anchors {
            verticalCenter: parent.verticalCenter
            right: parent.right
            margins: globalStyle.margins
        }
        z: 1
        height: score.height + nameLbl.height
        fillMode: Image.PreserveAspectFit
        smooth: true
        source: parent.hand.dead ? "deadHand.svg" : "normalHand.svg"
        MouseArea {
            anchors.fill: parent
            onClicked: parent.parent.hand.dead = !parent.parent.hand.dead;
        }
    }

    Binding {
        id: binding
        value: score.text
        when: score.text.length != 0
    }
}
