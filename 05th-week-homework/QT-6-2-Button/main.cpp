#include <QApplication>
#include <QMainWindow>
#include "button.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 窗口
    QMainWindow w;
    w.resize(800, 600);

    // 按钮
    Button btn(&w);
    btn.setText("Test Button");
    btn.setGeometry(200, 200, 220, 60);
    btn.setCheckable(true);

    w.show();
    return a.exec();
}