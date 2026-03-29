/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/04th-week-homework/QT02_Exit-program/main.cpp
* @date    2026-03-29
* @author  GY
* @brief   应用程序主入口文件
*
* 本文件是程序的入口点，负责创建QApplication应用程序对象和MainWindow主窗口对象，
* 并启动应用程序的事件循环。这是所有Qt应用程序的标准入口文件。
*
* Change Log:
* [v1.0] GY   2026-03-29
* * Initial creation
*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // 规范：顶层窗口作为栈对象分配
    MainWindow w;
    w.show();

    return a.exec();
}
