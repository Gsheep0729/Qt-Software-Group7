//Created By Chunlin Feng 1356962534@qq.com
//2026-3-19
//this is the headers files for null ptr use
#include "finddialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FindDialog w;
    w.show();
    return a.exec();
}