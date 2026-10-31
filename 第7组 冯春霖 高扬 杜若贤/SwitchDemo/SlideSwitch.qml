// Module
// File: main.cpp   Version: 0.1.0   License: AGPLv3
// Created: Chunlin Feng      2026-06-06 13:51:04
// Description:
//
import QtQuick 2.15

Item {
    id: root; width: 260; height: 50
    Rectangle {
        id:slot; x:15; y:7; height: 36; width:230; radius: 20; color:"grey"
        TapHandler { onTapped: root.state === "" ? root.state = "on" : root.state = "" }
    }
    Rectangle {
        id: ball; radius: 50; width: 50; height: 50;
        gradient: Gradient {
            GradientStop { position: 0.0; color: "red" }
            GradientStop { position: 0.5; color: "yellow" }
            GradientStop { position: 1.0; color: "green" }
        }
    }
    states: [
        State { name: "on"
            PropertyChanges { ball.x: 210 }
            PropertyChanges { slot.color:"black"}
        }
    ]
    transitions: [
        Transition {
            from: "on"
            NumberAnimation { properties: "x,y"; duration: 3000}
            ColorAnimation { properties: "color"; duration: 3000}
        }
        ,Transition {
            from: ""; to: "on"
            NumberAnimation { properties: "x"; duration: 500; easing.type: Easing.InOutQuad }
            ColorAnimation { properties: "color"; duration: 500 }
        }
    ]
}
