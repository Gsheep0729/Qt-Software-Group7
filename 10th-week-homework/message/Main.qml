import QtQuick
// 导入我们在 C++ 中定义的模块，URI 与 CMakeLists.txt 中一致
import se.qt.message

// Window 是 QML 中最基本的窗口容器
Window {
    visible: true           // 设置窗口可见
    width: 400              // 窗口宽度
    height: 100             // 增加一点高度，避免文字重叠
    title: qsTr("Register an instantiable object type") // 窗口标题

    // 实例化我们在 C++ 中定义的 Message 类
    // 因为在 C++ 中使用了 QML_ELEMENT，所以这里可以直接使用类型名
    Message {
        id: m               // 为该实例指定一个唯一的 ID，方便在其他地方引用
        author: "Amelie"    // 设置作者属性
        creationDate: new Date() // 设置创建日期属性，这里使用了 JavaScript 的 Date 对象
    }

    // Column 是一个定位器，将其子组件垂直排列
    Column {
        anchors.centerIn: parent // 将该列居中显示在父容器（Window）中

        // 显示作者名字
        Text {
            // 通过 ID 'm' 访问 Message 实例的属性
            // 这就是 QML 的属性绑定：如果 m.author 在 C++ 中改变，这里的文字会自动更新
            text: "Author: " + m.author
            color: "red"
            font.pixelSize: 16
        }

        // 显示创建时间
        Text {
            // 显示 creationDate 属性
            text: "Date: " + m.creationDate
            color: "blue"
            font.pixelSize: 16
        }
    }
}
