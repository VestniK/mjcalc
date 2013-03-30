import QtQuick 1.1

Rectangle {
    gradient: Gradient {
        GradientStop { position: 0.0; color: "lightgreen" }
        GradientStop { position: 1.0; color: "green" }
    }
    width: 240
    height: 320

    Image {
        anchors.centerIn: parent
        source: "rdragon.svg"
        width: parent.width/2
        fillMode: Image.PreserveAspectFit
        smooth: true
    }

    property variant msgBox: messageBox
    MessageBox {
        id: messageBox
        anchors.centerIn: parent
        z: 1.0
        visible: false;
    }
}
