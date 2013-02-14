import QtQuick 1.0

Item {
    height: childrenRect.height
    opacity: 0.85

    property variant validator: null
    property string icon
    property alias text: inputArea.text
    property alias target: binding.target
    property alias property: binding.property
    property alias winner: iconBG.visible

    Image {
        id: iconImg
        anchors {
            top: parent.top
            left: parent.left
        }
        z: 1
        source: parent.icon
        height: 1.4*inputRect.height
        fillMode: Image.PreserveAspectFit
        smooth: true
    }
    Image {
        id: iconBG
        anchors {
            top: parent.top
            left: parent.left
        }
        source: "winner.svg"
        height: iconImg.height
        fillMode: Image.PreserveAspectFit
        smooth: true
        visible: false
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
            font.family: "Helvetica"
            font.pointSize: 14
            color: "black"
            focus: true
            validator: parent.parent.validator
        }
    }

    Binding {
        id: binding
        value: inputArea.text
        when: inputArea.text.length != 0
    }
}