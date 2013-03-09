import QtQuick 1.0

Item {
    property string name: ""
    property alias icon: iconImg.source
    property alias text: score.text
    property alias target: binding.target
    property alias property: binding.property
    property alias winner: iconBG.visible

    height: score.height + nameLbl.height + 3*globalStyle.margins

    Image {
        id: iconImg
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            margins: globalStyle.margins
        }
        z: 1
        height: score.height + nameLbl.height
        fillMode: Image.PreserveAspectFit
        smooth: true
    }
    Image {
        id: iconBG
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            margins: globalStyle.margins
        }
        source: "winner.svg"
        height: iconImg.height
        fillMode: Image.PreserveAspectFit
        smooth: true
        visible: false
    }

    Text {
        id: nameLbl
        font.family: globalStyle.descriptionFont
        font.pointSize: globalStyle.descriptionFontSize
        font.italic: globalStyle.descriptionItalic
        font.bold: globalStyle.descriptionBold
        text: parent.name + ":"
        anchors {
            top: parent.top
            left: iconImg.right
            right: parent.right
            margins: globalStyle.margins
        }
    }

    LineEdit {
        id: score
        text: "0"
        opacity: globalStyle.inputOpacity
        anchors {
            top: nameLbl.bottom
            left: iconImg.right
            right: parent.right
            margins: globalStyle.margins
        }
        validator: IntValidator {bottom: 0; top: 1000000;}
    }

    Binding {
        id: binding
        value: score.text
        when: score.text.length != 0
    }
}
