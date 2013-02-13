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
            text: qsTr("Calculate")
            anchors {
                top: playerNorth.bottom
                horizontalCenter: parent.horizontalCenter
                margins: 10
            }

            onButtonClick: resultController.addScore()
        }
    }
}
