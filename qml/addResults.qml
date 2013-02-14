import QtQuick 1.0

Background {
    Flickable {
        anchors {
            topMargin: 10
            fill: parent
        }
        contentWidth: parent.width
        contentHeight: childrenRect.height
        MjcInput {
            id: playerEast
            text: "0"
            target: resultController
            property: "eastHandScore"
            validator: IntValidator {bottom: 0; top: 1000000;}
            icon: "east.svg"
            anchors {
                left: parent.left
                right: parent.right
                margins: 10
            }
        }
        MjcInput {
            id: playerSouth
            winner: true
            text: "0"
            target: resultController
            property: "southHandScore"
            validator: IntValidator {bottom: 0; top: 1000000;}
            icon: "south.svg"
            anchors {
                left: parent.left
                right: parent.right
                top: playerEast.bottom
                margins: 10
            }
        }
        MjcInput {
            id: playerWest
            text: "0"
            target: resultController
            property: "westHandScore"
            validator: IntValidator {bottom: 0; top: 1000000;}
            icon: "west.svg"
            anchors {
                left: parent.left
                right: parent.right
                top: playerSouth.bottom
                margins: 10
            }
        }
        MjcInput {
            id: playerNorth
            text: "0"
            target: resultController
            property: "northHandScore"
            validator: IntValidator {bottom: 0; top: 1000000;}
            icon: "north.svg"
            anchors {
                left: parent.left
                right: parent.right
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
