/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/10th-week-homework/message/main.cpp
* @date    2026-05-15
* @author  GY
* @brief   <这里填写简要说明>
*
* 这个项目展示了如何将 C++ 类导出给 QML 使用：
* message.h/cpp: 定义了一个继承自 QObject 的 Message 类，包含 author 和 creationDate 属性。使用了QML_ELEMENT 宏以便在 QML 中直接实例化。
* Main.qml: 在 QML 中实例化了 Message 对象，并利用属性绑定（Property Binding）将 C++对象的属性显示在界面上。
*  总结流程：
   1. CMake: 定义了模块的“门牌号” (URI "se.qt.message")，并指定扫描哪些文件。
   2. C++: 在类定义里打上“标记” (QML_ELEMENT)。
   3. 编译期: Qt 的 moc 和 qmltyperegistrar 工具会自动生成一些注册代码，将 Message 类型绑定到
      se.qt.message 命名空间下。
   4. QML: 通过 import se.qt.message 找到对应的模块，随后即可直接实例化 Message。

* Change Log:
* [v1.0] GY   2026-05-15
* * Initial creation
*/


#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    // QGuiApplication 类管理 GUI 应用程序的控制流和主要设置
    QGuiApplication app(argc, argv);

    // QQmlApplicationEngine 提供了一个从单个 QML 文件加载应用程序的环境
    QQmlApplicationEngine engine;

    // 连接信号：如果对象创建失败（例如 QML 语法错误），则退出程序
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    // 从模块中加载 Main.qml 文件
    // "se.qt.message" 是在 CMakeLists.txt 中定义的 URI
    // "Main" 是要加载的 QML 类型名（对应 Main.qml）
    engine.loadFromModule("se.qt.message", "Main");

    // 开启应用程序的事件循环，保持程序运行直到关闭窗口
    return QCoreApplication::exec();
}
