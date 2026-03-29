#include "closeevent.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CloseEvent w;
    w.show();
    return QCoreApplication::exec();
}
