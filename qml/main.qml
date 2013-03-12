import QtQuick 1.0

Background {
    Style {id: globalStyle}

    Item {
        id: buttons
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
        height: childrenRect.height + globalStyle.margins
        TextButton {
            anchors {
                left: parent.left
                top: parent.top
                margins: globalStyle.margins
            }
            text: qsTr("New"); width: parent.width/2 - 2*globalStyle.margins
            onButtonClick: game.showNewPage()
        }
        TextButton {
            anchors {
                right: parent.right
                top: parent.top
                margins: globalStyle.margins
            }
            text: qsTr("Add scores"); width: parent.width/2 - 2*globalStyle.margins
            onButtonClick: game.showAddScores()
        }
    }
    Rectangle {
        border.color: globalStyle.textArea.borderColor
        border.width: globalStyle.textArea.borderWidth
        radius: globalStyle.textArea.borderRadius
        color: globalStyle.textArea.bgColor
        opacity: globalStyle.textArea.opacity

        anchors {
            margins: globalStyle.margins
            top: buttons.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }

        ResultsRow {
            anchors {
                margins: globalStyle.margins
                left: parent.left
                right: parent.right
            }
            column1: game.player1; column2: game.player2; column3: game.player3; column4: game.player4;
        }
    }
}
