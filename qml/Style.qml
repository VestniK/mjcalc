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

QtObject {
    property int margins: 5
    property variant textArea: QtObject {
        property int borderRadius: 5
        property int borderWidth: 1
        property color borderColor: "black"
        property color bgColor: "white"
        property double opacity: 0.85
    }

    property string labelFont: "Helvetica"
    property double labelFontSize: 20
    property string descriptionFont: "Helvetica"
    property double descriptionFontSize: 16
    property bool descriptionItalic: true
    property bool descriptionBold: false
}
