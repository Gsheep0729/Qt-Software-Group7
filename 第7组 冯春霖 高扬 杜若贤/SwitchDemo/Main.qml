import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 400
    height: 200
    visible: true
    title: qsTr("开关状态动画")

    SlideSwitch{
        anchors.centerIn: parent
    }
}
