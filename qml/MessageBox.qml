import QtQuick 1.1

Rectangle {
    property alias text: message.text

    width: Math.min(parent.width/2, implicitWidth)
    border.color: globalStyle.textArea.borderColor
    border.width: globalStyle.textArea.borderWidth
    radius: globalStyle.textArea.borderRadius
    color: globalStyle.textArea.bgColor
    opacity: globalStyle.textArea.opacity
    implicitHeight: message.implicitHeight + okBtn.height + 3*globalStyle.margins
    implicitWidth: message.implicitWidth + 2*globalStyle.margins

    Text {
        id: message
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            margins: globalStyle.margins
        }
        font.family: globalStyle.labelFont
        font.pointSize: globalStyle.labelFontSize
        horizontalAlignment: Text.AlignJustify
        verticalAlignment: Text.AlignTop
        text: ""
        wrapMode: Text.WordWrap
    }
    TextButton {
        id: okBtn
        anchors {
            top: message.bottom
            horizontalCenter: parent.horizontalCenter
        }
        text: qsTr("Ok")
        onButtonClick: {
            parent.visible = false;
        }
    }
}
