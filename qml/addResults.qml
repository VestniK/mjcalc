import QtQuick 1.0

Background {
    Flickable {
        anchors {
            fill: parent
        }
        contentWidth: parent.width
        contentHeight: childrenRect.height

        Column {
            spacing: 5
            width: parent.width
            ScoreInput {
                id: playerEast; icon: "east.svg"; width: parent.width
                target: resultController; property: "eastHandScore"
            }
            ScoreInput {
                id: playerSouth; icon: "south.svg"; width: parent.width
                winner: true
                target: resultController; property: "southHandScore"
            }
            ScoreInput {
                id: playerWest; icon: "west.svg"; width: parent.width
                target: resultController; property: "westHandScore"
            }
            ScoreInput {
                id: playerNorth; icon: "north.svg"; width: parent.width
                target: resultController; property: "northHandScore"
            }
            // TODO: elliminate this spacer somehow
            Item {height: 5; width: parent.width}
            Button {
                id: button; width: parent.width/2; text: qsTr("Add")
                anchors.horizontalCenter: parent.horizontalCenter

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
}
