import QtQuick 1.0

Item {
    property alias icon: iconImg.source
    property alias text: score.text
    property alias target: binding.target
    property alias property: binding.property
    property alias winner: iconBG.visible

    height: childrenRect.height
    opacity: style.inputOpacity

    Image {
        id: iconImg
        anchors {
            top: parent.top
            left: parent.left
            margins: style.margins
        }
        z: 1
        height: score.height
        fillMode: Image.PreserveAspectFit
        smooth: true
    }
    Image {
        id: iconBG
        anchors {
            top: parent.top
            left: parent.left
            margins: style.margins
        }
        source: "winner.svg"
        height: iconImg.height
        fillMode: Image.PreserveAspectFit
        smooth: true
        visible: false
    }

    LineEdit {
        id: score
        text: "0"
        anchors {
            top: parent.top
            left: iconImg.right
            right: parent.right
            margins: style.margins
        }
        validator: IntValidator {bottom: 0; top: 1000000;}
    }

    Binding {
        id: binding
        value: score.text
        when: score.text.length != 0
    }
}
