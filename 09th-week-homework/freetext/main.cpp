#include "appcontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ✅ 单例创建，自动显示窗口
    AppController::singleton();

    return a.exec();
}
