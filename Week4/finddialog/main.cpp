/*
 * 文件名:   main.cpp
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-03-29
 * 描述:     /run/media/root/Windows/study/code/group_7_store/Qt-Software-Group7/Week4/finddialog/main.cpp
 * 版权声明: https://github.com/duruoxian
 */
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // 创建应用程序对象
    QApplication app(argc, argv);

    // 创建搜索对话框
    SearchDialog dialog;
    dialog.show();

    // 进入事件循环
    return app.exec();
}