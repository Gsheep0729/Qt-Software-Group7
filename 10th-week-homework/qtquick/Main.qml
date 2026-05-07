import QtQuick

Window {
    visible: true
    width: 400
    height: 300
    title: "QML Runtime Demo"

    BlueRectangle {
        x: 20; y: 30
    }

    GreenRectangle{
        x: 50; y: 100;
    }

    Rectangle {
        x: 150; y: 30
        width: 100; height: 80
        color: "orange"
    }
}
