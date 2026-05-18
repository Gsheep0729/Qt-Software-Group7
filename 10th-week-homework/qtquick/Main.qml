/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/10th-week-homework/qtquick/Main.qml
* @date    2026-05-15
* @author  GY
* @brief   <这里填写简要说明>
*
QML 组件化的核心逻辑：

  如何创建自定义组件？
   1. 文件即组件：每一个 .qml 文件就是一个独立的组件。
   2. 命名规则：文件名必须大写开头（如 BlueRectangle.qml）。这是 QML 引擎识别自定义类型的唯一标识。
   3. 根元素决定基类：组件的行为继承自其根元素。例如 BlueRectangle.qml 的根是
      Rectangle，它就具备矩形的所有属性。
   4. 属性暴露 (property)：在 MyRectangle.qml 中定义的 property int side: 100
      就是一种“接口”，允许外部在使用该组件时进行定制。

  如何使用自定义组件？
   1. 直接引用：在同一个目录下，可以直接像使用系统组件一样使用它：

   1     BlueRectangle { x: 20; y: 30 }
   2. 模块化引用：通过 qt_add_qml_module 将组件打包。
       * 关键点：在 CMakeLists.txt 中必须将所有 .qml 文件列在 QML_FILES
         中，否则这些组件不会被编译进资源系统。

  为什么之前看不到窗口？（关键点）
   * Window vs Item/Rectangle：只有以 Window（或 ApplicationWindow）为根元素，且 visible 属性为 true
     的 QML 文件，在被加载时才会自动创建可视化窗口。
   * 如果加载的是一个以 Rectangle 为根的文件，它只是一个 UI 片段，除非你手动在 C++
     中将其放入一个窗口容器中，否则不会有任何显示。

*
* Change Log:
* [v1.0] GY   2026-05-15
* * Initial creation
*/
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
