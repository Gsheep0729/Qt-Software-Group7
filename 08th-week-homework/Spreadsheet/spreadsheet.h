#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QTableWidget>   // 注意是 TableWidget，不是 TabletWidget

class Spreadsheet : public QTableWidget   // 注意继承 QTableWidget
{
    Q_OBJECT
public:
    explicit Spreadsheet(QWidget *parent = nullptr);
};

#endif