/**
* @file    /root/Qt-Software-Group7/03rd-week-homework/QT4-2_3-gotocell/main.cpp
* @date    2026-03-22
* @author  GY
* @brief   程序入口文件
*
* 初始化 Qt 应用程序，并创建并显示跳转到单元格对话框
* 作为独立对话框的主控入口。
*
* Change Log:
* [v1.0] GY   2026-03-22
* * Initial creation
*/
#include "gotocelldialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GoToCellDialog w;
    w.show();
    return a.exec();
}
