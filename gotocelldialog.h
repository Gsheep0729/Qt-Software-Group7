#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QMainWindow>  // 改成 QMainWindow

namespace Ui {
class GoToCellDialog;
}

class GoToCellDialog : public QMainWindow  // 改成 QMainWindow
{
    Q_OBJECT

public:
    explicit GoToCellDialog(QWidget *parent = nullptr);
    ~GoToCellDialog();

private slots:
    void on_lineEdit_textChanged();

private:
    Ui::GoToCellDialog *ui;
};

#endif // GOTOCELLDIALOG_H
