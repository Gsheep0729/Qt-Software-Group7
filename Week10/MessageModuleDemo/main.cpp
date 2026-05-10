/*
 * 文件名:   main.cpp
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-05-10
 * 描述:     /run/media/root/Windows/study/code/Qt-Software-Group7/Week10/MessageModuleDemo/main.cpp
 * 版权声明: https://github.com/duruoxian
 */
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // 向 QML Context 传递 C++ 数据
    QString welcomeText = "Hello from C++!";
    engine.rootContext()->setContextProperty("welcomeText", welcomeText);
    engine.load(QUrl::fromLocalFile("../../Main.qml"));
    engine.addImportPath("Module");
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}