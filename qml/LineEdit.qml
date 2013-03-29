import QtQuick 1.0

Rectangle {
    property alias validator: inputArea.validator
    property alias text: inputArea.text

    border.color: globalStyle.textArea.borderColor
    border.width: globalStyle.textArea.borderWidth
    radius: globalStyle.textArea.borderRadius
    color: globalStyle.textArea.bgColor
    opacity: globalStyle.textArea.opacity
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
        focus: parent.focus
        Timer {
            id: onFocusSelectDelayer; interval: 100; repeat: false; triggeredOnStart: false
            onTriggered: {inputArea.selectAll()}
        }
        onActiveFocusChanged: {
            if (activeFocus == true)
                onFocusSelectDelayer.start();
        }
    }
}
