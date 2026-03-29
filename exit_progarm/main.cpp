/*
 * 文件名:   main.cpp
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-03-29
 * 描述:     /run/media/root/Windows/study/code/group_7_store/Qt-Software-Group7/Week4/exit_progarm/main.cpp
 * 版权声明: https://github.com/duruoxian
 */
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    AppWindow window;
    window.show();

    return application.exec();
}