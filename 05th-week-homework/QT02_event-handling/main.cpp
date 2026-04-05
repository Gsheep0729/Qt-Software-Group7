#include "event_handling.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    event_handling w;

    w.show();
    return QCoreApplication::exec();
}
