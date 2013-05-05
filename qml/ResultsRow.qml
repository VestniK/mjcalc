import QtQuick 1.0

Item {
    property alias column1: col1.text
    property alias column2: col2.text
    property alias column3: col3.text
    property alias column4: col4.text
    property bool head: false
    height: childrenRect.height
    Text {
        id: col1
        text: "0"
        anchors.left: parent.left
        anchors.top: parent.top
        width: parent.width/4
        font.bold: parent.head
    }
    Text {
        id: col2
        text: "0"
        anchors.left: col1.right
        anchors.top: parent.top
        width: parent.width/4
        font.bold: parent.head
    }
    Text {
        id: col3
        text: "0"
        anchors.left: col2.right
        anchors.top: parent.top
        width: parent.width/4
        font.bold: parent.head
    }
    Text {
        id: col4
        text: "0"
        anchors.left: col3.right
        anchors.top: parent.top
        width: parent.width/4
        font.bold: parent.head
    }
}
