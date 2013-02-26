import QtQuick 1.0

Item {
    property alias target: binding.target
    property alias property: binding.property
    property alias text: name.text
    property alias icon: image.source

    opacity: 0.85
    height: childrenRect.height

    Image {
        id: image
        anchors {
            top: parent.top
            left: parent.left
            margins: 5
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
            margins: 5
        }
    }
    Binding {
        id: binding
        value: name.text
    }
}
