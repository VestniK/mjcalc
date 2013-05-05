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
    property alias text: label.text

    height: label.height
    radius: height/2
    width: label.width + 2*radius
    property variant pressedGrad: Gradient{
        GradientStop { position: 0.0; color: "lightgray" }
        GradientStop { position: 0.5; color: "gray" }
        GradientStop { position: 1.0; color: "lightgray" }
    }
    property variant normalGrad: Gradient{
        GradientStop { position: 0.0; color: "gray" }
        GradientStop { position: 0.5; color: "lightgray" }
        GradientStop { position: 1.0; color: "gray" }
    }
    gradient: normalGrad

    Text {
        id: label
        anchors.centerIn: parent
        font.family: globalStyle.labelFont
        font.pointSize: globalStyle.labelFontSize
    }

    signal buttonClick()

    MouseArea {
        anchors.fill: parent
        onPressed: parent.gradient=parent.pressedGrad
        onReleased: parent.gradient=parent.normalGrad
        onCanceled: parent.gradient=parent.normalGrad
        onClicked: buttonClick()
    }
}
