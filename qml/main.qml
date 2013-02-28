import QtQuick 1.0

Background {
    Style {id: style}
    Flickable {
        anchors {
            fill: parent
        }
        contentWidth: parent.width
        contentHeight: childrenRect.height

        Column {
            spacing: style.margins
            width: parent.width
            TextButton {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("New"); width: parent.width/2
                onButtonClick: game.showNewPage()
            }
            TextButton {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Add scores"); width: parent.width/2
                onButtonClick: game.showAddScores()
            }
        }
    }
}
