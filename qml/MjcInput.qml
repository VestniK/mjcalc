import QtQuick 1.0

Item {
    height: childrenRect.height
    opacity: 0.85

    property string text: ""
    property variant validator: null
    property string icon

    Image {
        id: iconImg
        anchors {
            top: parent.top
            left: parent.left
        }
        source: parent.icon
        height: inputRect.height
        fillMode: Image.PreserveAspectFit
        smooth: true
    }

    Rectangle {
        id: inputRect
        border.color: "black"
        border.width: 1
        radius: 5
        color: "white"
        height: childrenRect.height + inputArea.anchors.topMargin + inputArea.anchors.bottomMargin
        anchors {
            left: iconImg.right
            right: parent.right
            top: parent.top
            leftMargin: 10
        }

        TextInput {
            anchors {
                left: parent.left
                right: parent.right
                top: parent.top
                margins: 5
            }
            id: inputArea
            text: parent.parent.text
            font.family: "Helvetica"
            font.pointSize: 14
            color: "black"
            focus: true
            validator: parent.parent.validator
            onTextChanged: parent.parent.text = text
        }
    }
}