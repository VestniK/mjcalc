import QtQuick 1.0

Item {
    property string name: ""
    property alias icon: icon.source
    property alias text: score.text
    property alias target: binding.target
    property alias property: binding.property
    property alias iconRect: icon.childrenRect

    height: score.height + nameLbl.height + 3*globalStyle.margins

    signal selected()

    Image {
        id: icon
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            margins: globalStyle.margins
        }
        z: 1
        height: score.height + nameLbl.height
        fillMode: Image.PreserveAspectFit
        smooth: true

        MouseArea {
            anchors.fill: parent
            onClicked: parent.parent.selected()
        }
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
            left: icon.right
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
            left: icon.right
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
