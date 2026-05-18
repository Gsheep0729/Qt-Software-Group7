/**
* @file    module-demo.qml
* @date    2026-05-11
* @author  GY
* @brief   演示如何导入和使用自定义 QML 模块
*
* 本项目展示了 QML 模块系统的使用方式：
* - 通过 import 语句导入自定义模块 (se.qt.MyModule)
* - 使用模块中导出的组件：MyTextConstants、MyClock、MyTextBox、MyButton
* - 演示了模块版本控制 (import se.qt.MyModule 2)
* - 展示了组件间的交互：点击按钮修改文本框内容和样式
*
* 对于 C++ 开发者：
* QML 模块类似于 C++ 的命名空间或库，将相关组件组织在一起。
* import 语句类似于 C++ 的 #include，但更灵活，支持版本管理。
*
* Change Log:
* [v1.0] GY   2026-05-11
* * Initial creation
*/
import QtQuick 2.15
import QtQuick.Window 2.15
//import "../lib" as MyModule
import se.qt.MyModule 1

Window {
    visible: true
    width: 400
    height: 300
    title: qsTr("Module Demo")

    Column {
        anchors.centerIn: parent
        spacing: 2

        MyTextConstants{id:constants}
        MyClock{color:"red"}
        MyTextBox{id:textBox}
        MyButton{
            text:qsTr("OK")
            onClicked:{
                textBox.textColor = "red"
                textBox.text = constants.welcomeText.arg("Ver 2.1")
                textBox.width = 150
            }
        }
    }
}
