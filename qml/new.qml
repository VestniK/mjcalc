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
            NameInput {
                width: parent.width
                icon: "east.svg"
                target: game
                property: "player1"
            }
            NameInput {
                width: parent.width
                icon: "south.svg"
                target: game
                property: "player2"
            }
            NameInput {
                width: parent.width
                icon: "west.svg"
                target: game
                property: "player3"
            }
            NameInput {
                width: parent.width
                icon: "north.svg"
                target: game
                property: "player4"
            }
            // TODO: elliminate this spacer somehow
            Item {height: 5; width: parent.width}
            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Start")
                onButtonClick: game.start()
            }
        }
    }
}
