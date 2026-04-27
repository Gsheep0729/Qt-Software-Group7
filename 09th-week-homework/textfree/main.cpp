// Module
// File: main.cpp   Version: 0.1.0   License: AGPLv3
// Created: Chunlin Feng  1356962534@qq.com   2026-04-27 17:31:28
// Description:
// save
#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.show();
    return QCoreApplication::exec();
}
