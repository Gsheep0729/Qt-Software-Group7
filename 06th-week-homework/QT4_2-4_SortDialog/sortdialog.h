/**
* @file    sortdialog.h
* @brief   Sort Dialog 界面类声明 - 负责列排序属性配置
* @author  GY
* @date    2026-04-10
*
* Change Log:
* [v1.0] GY 2026-04-10 Initial creation with Pimpl decoupling.
*/

#pragma once

#include <QDialog>

// 降低头文件污染，使用前置声明代替 #include "ui_sortdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui {
    class SortDialog;
}
QT_END_NAMESPACE

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    // 允许作为顶层窗口在栈上分配，默认父对象为空
    explicit SortDialog(QWidget *parent = nullptr);

    // 显式声明析构，确保释放非对象树管理的 UI 指针
    ~SortDialog() override;

    // 身份语义约束：禁止对话框对象的拷贝与赋值
    SortDialog(const SortDialog&) = delete;
    SortDialog& operator=(const SortDialog&) = delete;

    /**
     * @brief 配置下拉列表的字符列范围
     * @param first 起始字符
     * @param last  结束字符
     */
    void setColumnRange(QChar first, QChar last);

private:
    // UI 指针组合模式，隔离生成的布局代码
    Ui::SortDialog *_ui;
};