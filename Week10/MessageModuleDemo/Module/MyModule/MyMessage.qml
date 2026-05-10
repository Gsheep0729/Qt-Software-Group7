//杜若贤
import QtQuick 2.15

Rectangle {
    width: 350
    height: 40
    color: "lightgreen"
    radius: 8

    property string text: "Default Module Message"

    Text {
        anchors.centerIn: parent
        text: parent.text
    }
}