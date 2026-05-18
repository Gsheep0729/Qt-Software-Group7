import QtQuick 2.15

Rectangle {
    property int side: 100
    color: "red"
    width: side
    height: side

    TapHandler {
        onTapped: console.log("Button clicked")
    }
}
