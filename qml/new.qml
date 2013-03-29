import QtQuick 1.0

Background {
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
                width: parent.width
                icon: "east.svg"
                target: game
                property: "player1"
                focus: true
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
            Item {height: globalStyle.margins; width: parent.width}
            TextButton {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Start")
                onButtonClick: game.start()
            }
        }
    }
}
