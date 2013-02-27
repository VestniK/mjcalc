import QtQuick 1.0

Background {
    Flickable {
        anchors {
            topMargin: 10
            fill: parent
        }
        contentWidth: parent.width
        contentHeight: childrenRect.height
        ScoreInput {
            id: playerEast
            target: resultController
            property: "eastHandScore"
            icon: "east.svg"
            width: parent.width
            anchors {
                margins: 10
            }
        }
        ScoreInput {
            id: playerSouth
            winner: true
            target: resultController
            property: "southHandScore"
            icon: "south.svg"
            width: parent.width
            anchors {
                top: playerEast.bottom
                margins: 10
            }
        }
        ScoreInput {
            id: playerWest
            target: resultController
            property: "westHandScore"
            icon: "west.svg"
            width: parent.width
            anchors {
                top: playerSouth.bottom
                margins: 10
            }
        }
        ScoreInput {
            id: playerNorth
            target: resultController
            property: "northHandScore"
            icon: "north.svg"
            width: parent.width
            anchors {
                top: playerWest.bottom
                margins: 10
            }
        }
        Button {
            id: button
            width: parent.width/2
            text: qsTr("Add")
            anchors {
                top: playerNorth.bottom
                horizontalCenter: parent.horizontalCenter
                margins: 10
            }

            onButtonClick: {
                if (playerEast.text.length == 0) playerEast.text = "0";
                if (playerSouth.text.length == 0) playerSouth.text = "0";
                if (playerWest.text.length == 0) playerWest.text = "0";
                if (playerNorth.text.length == 0) playerNorth.text = "0";
                resultController.addScore();
            }
        }
    }
}
