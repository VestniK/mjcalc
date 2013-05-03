import QtQuick 1.0

Background {
    id: canvas
    Style {id: globalStyle}
    Flickable {
        anchors {
            fill: parent
        }
        contentWidth: parent.width
        contentHeight: childrenRect.height

        Image {
            id: winnerMark
            state: "Unspecified"
            height: playerNorth.iconRect.height
            x: playerEast.x
            source: "winner.svg"
            fillMode: Image.PreserveAspectFit
            smooth: true

            states: [
                State{name:"Unspecified"; PropertyChanges {target: winnerMark; y: -winnerMark.height; visible:false}},
                State{name:"East"; PropertyChanges {target: winnerMark; y: playerEast.y + 0.5*globalStyle.margins; visible:true}},
                State{name:"South"; PropertyChanges {target: winnerMark; y: playerSouth.y + 0.5*globalStyle.margins; visible:true}},
                State{name:"West"; PropertyChanges {target: winnerMark; y: playerWest.y + 0.5*globalStyle.margins; visible:true}},
                State{name:"North"; PropertyChanges {target: winnerMark; y: playerNorth.y + 0.5*globalStyle.margins; visible:true}}
            ]

            transitions: Transition {
                PropertyAnimation {duration: 400; properties: "y"}
            }
        }

        Column {
            spacing: globalStyle.margins
            width: parent.width
            ScoreInput {
                id: playerEast; icon: "east.svg"; width: parent.width
                target: game.currentRound.eastHand; property: "score"
                hand: game.currentRound.eastHand
                name: game.eastPlayer; z: 1
                onSelected: {game.currentRound.setWinner(0); winnerMark.state = "East";}
                focus: true
            }
            ScoreInput {
                id: playerSouth; icon: "south.svg"; width: parent.width
                target: game.currentRound.southHand; property: "score"
                hand: game.currentRound.southHand
                name: game.southPlayer; z: 1
                onSelected: {game.currentRound.setWinner(1); winnerMark.state = "South";}
            }
            ScoreInput {
                id: playerWest; icon: "west.svg"; width: parent.width
                target: game.currentRound.westHand; property: "score"
                hand: game.currentRound.westHand
                name: game.westPlayer; z: 1
                onSelected: {game.currentRound.setWinner(2); winnerMark.state = "West";}
            }
            ScoreInput {
                id: playerNorth; icon: "north.svg"; width: parent.width
                target: game.currentRound.northHand; property: "score"
                hand: game.currentRound.northHand
                name: game.northPlayer; z: 1
                onSelected: {game.currentRound.setWinner(3); winnerMark.state = "North";}
            }
            // TODO: elliminate this spacer somehow
            Item {height: globalStyle.margins; width: parent.width}
            TextButton {
                id: button; width: parent.width/2; text: qsTr("Add")
                anchors.horizontalCenter: parent.horizontalCenter

                onButtonClick: {
                    if (playerEast.text.length == 0) playerEast.text = "0";
                    if (playerSouth.text.length == 0) playerSouth.text = "0";
                    if (playerWest.text.length == 0) playerWest.text = "0";
                    if (playerNorth.text.length == 0) playerNorth.text = "0";
                    if (playerEast.text%2 != 0 || playerSouth.text%2 != 0 || playerWest.text%2 != 0 || playerNorth.text%2 != 0) {
                        canvas.msgBox.text = qsTr("Some players have odd hand score.");
                        canvas.msgBox.visible = true;
                        return;
                    }
                    if (winnerMark.state == "Unspecified") {
                        canvas.msgBox.text = qsTr("Select round winner.");
                        canvas.msgBox.visible = true;
                        return;
                    }
                    game.addScore();
                }
            }
        }
    }
}
