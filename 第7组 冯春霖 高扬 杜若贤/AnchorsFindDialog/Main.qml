// Module
// File: main.cpp   Version: 0.1.0   License: AGPLv3
// Created: Chunlin Feng     2026-06-06 15:57:42
// Description:
//
import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 420
    height: 200
    visible: true
    title: "查找"
    color: "#f0f0f0"

    Label {
        id: findLabel
        text: "查找内容(&N):"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 16
    }

    TextField {
        id: findInput
        anchors.left: findLabel.right
        anchors.top: findLabel.top
        anchors.right: parent.right
        anchors.margins: 16
        placeholderText: "请输入要查找的内容"
    }

    CheckBox {
        id: caseCheck
        text: "区分大小写(&C)"
        anchors.top: findInput.bottom
        anchors.left: parent.left
        anchors.margins: 16
        anchors.topMargin: 12
    }

    CheckBox {
        id: wholeCheck
        text: "全字匹配(&W)"
        anchors.top: caseCheck.top
        anchors.left: caseCheck.right
        anchors.margins: 16
    }

    Button {
        id: findBtn
        text: "查找(&F)"
        anchors.right: closeBtn.left
        anchors.top: caseCheck.top
        anchors.margins: 8
        width: 80

        enabled: findInput.text !== ""

        onClicked: {
            console.log("查找内容:", findInput.text)
            console.log("区分大小写:", caseCheck.checked)
            console.log("全字匹配:", wholeCheck.checked)
        }
    }

    Button {
        id: closeBtn
        text: "关闭"
        anchors.right: parent.right
        anchors.top: findBtn.top
        anchors.margins: 16
        width: 80

        onClicked: Qt.quit()
    }
}
