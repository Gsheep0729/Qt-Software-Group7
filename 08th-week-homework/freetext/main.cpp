// A simple text editor demo.

// File: main.cpp   Version: 0.1.0   License: AGPLv3
// Created: stardust   open-src@qq.com   2026-04-22 23:11:55
// Description:
//   use AppController as the application-level controller and the editing-flow controller

#include "appcontroller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppController::singleton();

    return QCoreApplication::exec();
}
