import QtQuick 1.0

Item {
    property alias target: binding.target
    property alias property: binding.property
    property alias text: name.text
    property alias icon: image.source

    height: childrenRect.height

    Image {
        id: image
        anchors {
            top: parent.top
            left: parent.left
            margins: globalStyle.margins
        }
        height: name.height
        fillMode: Image.PreserveAspectFit
        smooth: true
    }
    LineEdit {
        id: name
        anchors {
            top: parent.top
            left: image.right
            right: parent.right
            margins: globalStyle.margins
        }
        focus: parent.focus
    }
    Binding {
        id: binding
        value: name.text
    }
}
