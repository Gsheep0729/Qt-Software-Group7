#include "button_program.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Button_program w;
    w.show();
    return QCoreApplication::exec();
}
