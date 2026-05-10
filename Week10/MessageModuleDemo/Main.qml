//杜若贤
import "Module/MyModule"
import QtQuick 2.15
import QtQuick.Window 2.15


Window {
    id: root
    visible: true
    width: 400
    height: 300
    title: "Message & Module Demo"

    // 使用 C++ context property
    Text {
        id: messageLabel
        text: welcomeText
        anchors.centerIn: parent
    }

    // 使用自定义组件
    Message {
        anchors.top: messageLabel.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Hello from QML Component!"
    }

    MyMessage {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Hello from Module!"
    }
}