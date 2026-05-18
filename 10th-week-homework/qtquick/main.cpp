/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/10th-week-homework/qtquick/main.cpp
* @date    2026-05-15
* @author  GY
* @brief   <这里填写简要说明>
*
这个项目练习了如何创建和使用自定义的 QML 组件：
   - BlueRectangle.qml / GreenRectangle.qml: 定义了带圆角和特定颜色的矩形组件。
   - MyRectangle.qml: 定义了一个带自定义属性 side 的红色正方形。
   - Main.qml: 展示了如何像使用原生组件一样使用这些自定义组件。
*
* Change Log:
* [v1.0] GY   2026-05-15
* * Initial creation
*/
#include <QGuiApplication>
#include <QQmlApplicationEngine>



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("se.qt.qtquick", "Main");

    return QCoreApplication::exec();
}
