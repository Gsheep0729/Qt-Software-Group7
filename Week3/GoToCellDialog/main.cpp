/*
 * 文件名:   main.cpp
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-03-22
 * 描述:     /run/media/root/Windows/study/code/group_7_store/Qt-Software-Group7/GoToCellDialog/main.cpp
 * 版权声明: https://github.com/duruoxian
 */
#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget w;
    w.show();
    return app.exec();
}
