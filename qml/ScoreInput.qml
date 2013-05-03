import QtQuick 1.0

Item {
    property string name: ""
    property variant hand: null
    property alias icon: icon.source
    property alias text: score.text
    property alias target: binding.target // TODO: find out why cant just use "target: parent.hand" in the binding
    property alias property: binding.property // TODO: find out why cant just use "target: parent.hand" in the binding
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
        anchors {
            top: nameLbl.bottom
            left: icon.right
            right: handIcon.left
            margins: globalStyle.margins
        }
        validator: IntValidator {bottom: 0; top: 1000000;}
        focus: parent.focus
    }

    Image {
        id: handIcon
        anchors {
            verticalCenter: parent.verticalCenter
            right: parent.right
            margins: globalStyle.margins
        }
        z: 1
        height: score.height + nameLbl.height
        fillMode: Image.PreserveAspectFit
        smooth: true
        source: parent.hand.dead ? "deadHand.svg" : "normalHand.svg"
        MouseArea {
            anchors.fill: parent
            onClicked: parent.parent.hand.dead = !parent.parent.hand.dead;
        }
    }

    Binding {
        id: binding
        value: score.text
        when: score.text.length != 0
    }
}
