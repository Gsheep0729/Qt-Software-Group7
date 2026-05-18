/**
* @file    main.cpp
* @date    2026-05-18
* @author  GY
* @brief   演示如何使用 C++ 动态加载 QML 内容
*
* 本项目展示了另一种加载 QML 的方式（与 QQmlApplicationEngine 不同）：
* - 使用 QQmlEngine + QQmlComponent 组合动态加载 QML
* - 通过 setData() 直接在 C++ 中内联 QML 代码（无需独立的 .qml 文件）
* - 使用 qobject_cast 将创建的对象转换为 QQuickWindow
*
* 与 QQmlApplicationEngine 的区别：
* - QQmlApplicationEngine: 适合加载完整的 QML 文件，自动处理窗口创建
* - QQmlEngine + QQmlComponent: 更灵活，可动态创建 QML 对象，适合需要精细控制的场景
*
* 适用场景：
* - 需要在 C++ 中动态生成 QML 界面
* - QML 内容较短，不值得单独创建文件
* - 需要在运行时根据条件加载不同的 QML 片段
*
* Change Log:
* [v1.0] GY   2026-05-18
* * Initial creation
*/

#include <QGuiApplication>
#include <QQmlEngine>        // ← 注意：不是 QQmlApplicationEngine
#include <QQmlComponent>
#include <QQuickWindow>      // ← 用于 qobject_cast

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlEngine engine;
    QQmlComponent component(&engine);

    component.setData(
        "import QtQuick\n"
        "import QtQuick.Controls\n"
        "ApplicationWindow{ visible:true; width:400; height:300; Text{text:\"hello QML!\"} }",
        QUrl());

    auto *window = qobject_cast<QQuickWindow *>(component.create());
    window->setHeight(768);

    return app.exec();
}
