/**
* @file    /root/Qt-Software-Group7/03rd-week-homework/QT4-2_3-gotocell/gotocelldialog.h
* @date    2026-03-22
* @author  GY
* @brief   GoToCellDialog 类定义
*
* 定义了跳转到单元格对话框的类结构，包含 UI 界面和输入验证逻辑。
*
* Change Log:
* [v1.0] GY   2026-03-22
* * Initial creation
*/
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
