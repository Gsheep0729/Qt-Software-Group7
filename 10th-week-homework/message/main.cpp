// Module
// File: main.cpp   Version: 0.1.0   License: AGPLv3
// Created: Chunlin Feng  1356962534@qq.com   2026-05-08 16:31:03
// Description:
// message complete

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
    engine.loadFromModule("se.qt.message", "Main");//加载se.qt.message模块里面的Main.qml文件

    return QCoreApplication::exec();
}
