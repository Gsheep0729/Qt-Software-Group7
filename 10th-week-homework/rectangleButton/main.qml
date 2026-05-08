import QtQuick
import QtQuick.Controls
import "."
rectangleButton {
    color: "green"

    rectangleButton {
        color: "blue"
        side: 50

        rectangleButton {
            color: "red"
            side: 25
            property bool hide: false
        }
    }
}
