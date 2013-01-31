import QtQuick 1.0

Rectangle {
    property string text: "Button"

    height: label.height
    radius: height/2
    width: label.width + 2*radius
    property variant pressedGrad: Gradient{
        GradientStop { position: 0.0; color: "lightgray" }
        GradientStop { position: 0.5; color: "gray" }
        GradientStop { position: 1.0; color: "lightgray" }
    }
    property variant normalGrad: Gradient{
        GradientStop { position: 0.0; color: "gray" }
        GradientStop { position: 0.5; color: "lightgray" }
        GradientStop { position: 1.0; color: "gray" }
    }
    gradient: normalGrad

    Text {
        id: label
        text: parent.text
        anchors.centerIn: parent
        font.family: "Helvetica"
        font.pointSize: 14
    }

    signal buttonClick()

    MouseArea {
        anchors.fill: parent
        onPressed: parent.gradient=parent.pressedGrad
        onReleased: parent.gradient=parent.normalGrad
        onCanceled: parent.gradient=parent.normalGrad
        onClicked: buttonClick()
    }
}