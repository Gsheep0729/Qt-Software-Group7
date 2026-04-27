#include "spreadsheet.h"

Spreadsheet::Spreadsheet(QWidget *parent)
    : QTableWidget(parent)
{
    setRowCount(10);
    setColumnCount(6);
    QStringList headers = {"A", "B", "C", "D", "E", "F"};
    setHorizontalHeaderLabels(headers);
    setShowGrid(true);
}