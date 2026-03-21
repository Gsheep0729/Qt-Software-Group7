/**
* @file    main.cpp
* @date    2026-03-19
* @author  GY
* @brief   项目入口文件，启动查找对话框
*
* 创建 QApplication 实例并显示查找对话框主窗口。
*
* Change Log:
* [v1.0] GY   2026-03-19
* * Initial creation
*/
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
