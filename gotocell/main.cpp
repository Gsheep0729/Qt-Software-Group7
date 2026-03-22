#include <QApplication>
#include "gotocelldialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GoToCellDialog w;
    w.show();
    return a.exec();
}
