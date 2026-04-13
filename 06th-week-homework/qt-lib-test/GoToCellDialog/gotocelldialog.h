/**
* @file    gotocelldialog.h
* @date    2026-04-11
* @author  GY
* @brief   定位单元格对话框
*
* Change Log:
* [v1.0] GY   2026-04-11
* * Initial creation
* [v3.0] GY   2026-04-11
* * 使用多重继承方式
* [v4.0] GY   2026-04-11
* * 使用成员变量方式
* [v5.0] GY   2026-04-11
* * 使用 Pimpl（私有指针）实现完全解耦
*/
#pragma once

#include <QDialog>

// 前置声明 UI 类
QT_BEGIN_NAMESPACE
namespace Ui { class GoToCellDialog; }
QT_END_NAMESPACE

// 使用成员变量方式
class GoToCellDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GoToCellDialog(QWidget *parent = nullptr);
    ~GoToCellDialog() override;

    // 禁用拷贝和赋值
    GoToCellDialog(const GoToCellDialog&) = delete;
    GoToCellDialog& operator=(const GoToCellDialog&) = delete;

private slots:
    // 文本改变时更新按钮状态
    void onTextChanged();

private:
    // 使用 Pimpl 模式
    Ui::GoToCellDialog *ui;
};
