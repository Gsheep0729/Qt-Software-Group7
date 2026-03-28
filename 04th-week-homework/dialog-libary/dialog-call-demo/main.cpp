/**
* @file    /root/Qt-Software-Group7/04th-week-homework/dialog-libary/dialog-call-demo/main.cpp
* @date    2026-03-29
* @author  GY
* @brief   这是一个测试QT4_2-3_dialog-library打包成.so库文件的demo
*
*运行前需要将dialog-call-demo和QT4_2-3_dialog-library项目文件夹都移到ext4格式的硬盘路径下。
*然后修改dialog-call-demo项目cmake文件第24行库文件路径中
*先运行QT4_2-3_dialog-library项目生成.so库文件，然后再运行此demo项目测试调用库
*
* Change Log:
* [v1.0] GY   2026-03-29
* * Initial creation
*/
#include <QApplication>
#include "widget.h" // 此时通过 CMake 的路径配置，它会找到库里的 widget.h

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 实例化库里的类
    Widget w;
    w.setWindowTitle("来自动态库的对话框");
    w.show();

    // 注意：Qt6 建议使用 a.exec() 或 QApplication::exec()
    return a.exec();
}