#pragma once

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class GoToCellDialog; }
QT_END_NAMESPACE

class GoToCellDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GoToCellDialog(QWidget *parent = nullptr);
    ~GoToCellDialog();

private slots:
    // 自动连接槽函数：命名格式必须严格为 on_<objectName>_<signalName>
    void on_lineEdit_textChanged();

private:
    Ui::GoToCellDialog *ui;
};
