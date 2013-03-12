import QtQuick 1.0

QtObject {
    property int margins: 5
    property variant textArea: QtObject {
        property int borderRadius: 5
        property int borderWidth: 1
        property color borderColor: "black"
        property color bgColor: "white"
        property double opacity: 0.85
    }

    property string labelFont: "Helvetica"
    property double labelFontSize: 14
    property string descriptionFont: "Helvetica"
    property double descriptionFontSize: 10
    property bool descriptionItalic: true
    property bool descriptionBold: false
}
