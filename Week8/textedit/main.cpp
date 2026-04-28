/*
 * 文件名:   main.cpp
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-04-28
 * 描述:     /root/textedit/main.cpp
 * 版权声明: https://github.com/duruoxian
 */
#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.show();
    return QCoreApplication::exec();
}
