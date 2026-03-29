/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/04th-week-homework/QT4-2_2-dialog/widget.h
* @date    2026-03-28
* @author  GY
* @brief   查找对话框类的头文件声明
*
* 本文件定义了Widget类，这是一个查找对话框，提供了查找文本的功能。
* 该类使用了多重继承的方式，同时继承自QDialog和Ui::Widget，
* 这样可以直接访问UI界面中的控件，而不需要通过ui指针。
*
* Change Log:
* [v1.0] GY   2026-03-28
* * Initial creation
*/
#pragma once

#include <QDialog>
// 前置声明 Ui::Widget，避免在头文件中直接包含 ui_widget.h，从而降低编译依赖
namespace Ui { class Widget; }

// 多重继承：同时继承 QDialog 和 Ui::Widget
class Widget : public QDialog
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    // 显式声明析构函数，用于释放 ui 指针指向的堆内存
    virtual ~Widget();

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);      // 向前查找信号
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);   // 向后查找信号

private slots:
    // 使用Qt自动关联机制：函数名格式为 on_控件名_信号名()
    void on_lineEdit_textChanged(const QString &text);  // 文本变化槽
    void on_findButton_clicked();                        // 查找按钮点击槽

private:
    // 采用类指针成员的方式来实现 Widget 类和 Ui::Widget 类的组合关系
    Ui::Widget *ui;

};