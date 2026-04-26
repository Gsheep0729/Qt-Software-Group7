/*
 * 文件名:   main.cpp
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-04-17
 * 描述:     /run/media/root/Windows/study/code/Qt-Software-Group7/Week7/Spreadsheet/main.cpp
 * 版权声明: https://github.com/duruoxian
 */
#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window mainWindow;
    mainWindow.show();
    return QApplication::exec();
}
