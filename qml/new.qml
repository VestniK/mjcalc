import QtQuick 1.0

Background {
    id: canvas
    Style {id: globalStyle}
    Flickable {
        anchors {
            fill: parent
        }
        contentWidth: parent.width
        contentHeight: childrenRect.height

        Column {
            spacing: globalStyle.margins
            width: parent.width
            NameInput {
                id: eastName
                width: parent.width
                icon: "east.svg"
                target: game
                property: "player1"
                focus: true
            }
            NameInput {
                id: southName
                width: parent.width
                icon: "south.svg"
                target: game
                property: "player2"
            }
            NameInput {
                id: westName
                width: parent.width
                icon: "west.svg"
                target: game
                property: "player3"
            }
            NameInput {
                id: northName
                width: parent.width
                icon: "north.svg"
                target: game
                property: "player4"
            }
            // TODO: elliminate this spacer somehow
            Item {height: globalStyle.margins; width: parent.width}
            TextButton {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Start")
                onButtonClick: {
                    if (eastName.text.length == 0 || southName.text.length == 0 || westName.text.length == 0 || northName.text.length == 0) {
                        canvas.msgBox.visible = true;
                        canvas.msgBox.text = qsTr("Some names are missing");
                        return;
                    }
                    game.start()
                }
            }
        }
    }
}
