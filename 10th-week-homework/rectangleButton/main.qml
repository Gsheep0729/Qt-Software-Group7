/**
* @file    main.qml
* @date    2026-05-18
* @author  GY
* @brief   演示 QML 自定义组件的嵌套和交互处理
*
* 本项目是纯 QML 项目（无 C++ 代码），展示以下 QML 功能：
* - 自定义组件：RectangleButton.qml 定义了可复用的矩形按钮组件
* - 属性定义：使用 property int side 自定义组件属性
* - 事件处理：通过 TapHandler 处理点击事件
* - 组件嵌套：在 main.qml 中演示多层组件嵌套（大矩形套小矩形）
* - 本地导入：使用 import "." 导入当前目录的组件
*
* 运行方式：
* - 使用 qmlscene 或 Qt Design Studio 直接加载
* - 项目文件为 .qmlproject（非 CMake）
*
* 对于 C++ 开发者：
* QML 组件嵌套类似于 C++ 中的组合模式（Composition Pattern），
* 每个组件封装自己的属性和行为，通过嵌套构建复杂的 UI 层次结构。
*
* Change Log:
* [v1.0] GY   2026-05-18
* * Initial creation
*/
import QtQuick 2.15
import QtQuick.Controls 2.15
import "."

RectangleButton {
    color: "green"

    RectangleButton {
        color: "blue"
        side: 50

        RectangleButton {
            color: "red"
            side: 25
            property bool hide: false
        }
    }
}
