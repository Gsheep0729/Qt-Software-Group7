import QtQuick 2.15

Rectangle {
    width: 300
    height: 50
    color: "lightblue"
    radius: 10

    property string text: ""

    Text {
        anchors.centerIn: parent
        text: parent.text
        font.bold: true
    }
}