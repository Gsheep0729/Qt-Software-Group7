#include "appcontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppController::singleton();          // 单例，内部创建并显示 Window
    return QCoreApplication::exec();
}