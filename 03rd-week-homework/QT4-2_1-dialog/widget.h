/**
* @file    widget.h
* @date    2026-03-22
* @author  GY
* @brief   实现《C++ GUI Qt4编程》2.1节 查找对话框
*
* 定义了一个查找对话框类 Widget，支持输入查找内容、区分大小写以及向后查找。
* 包含 UI 部件的指针声明、信号和私有槽函数。
*
* Change Log:
* [v1.0] GY   2026-03-22
* * Initial creation
*/
#pragma once

#include <QDialog>

// 前向声明，减少头文件依赖
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class Widget : public QDialog
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

// 声明自定义信号
signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

// 声明私有槽函数
private slots:
    void findClicked();
    void enableFindButton(const QString &text);

private:
    // 界面控件指针
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};
