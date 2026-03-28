#include "age_widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AgeWidget w;
    w.show();
    return QCoreApplication::exec();
}
