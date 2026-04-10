#include "sortdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SortDialog dialog;
    dialog.show();
    return QCoreApplication::exec();
}
