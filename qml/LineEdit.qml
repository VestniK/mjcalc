import QtQuick 1.0

Rectangle {
    property alias validator: inputArea.validator
    property alias text: inputArea.text

    border.color: "black"
    border.width: 1
    radius: 5
    color: "white"
    height: childrenRect.height + inputArea.anchors.topMargin + inputArea.anchors.bottomMargin

    TextInput {
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            margins: globalStyle.margins
        }
        id: inputArea
        font.family: globalStyle.labelFont
        font.pointSize: globalStyle.labelFontSize
        color: "black"
        focus: true
    }
}
