/**
* @file    finddialog.h
* @date    2026-04-16
* @author  GY
* @brief   查找对话框类声明
*
* 提供非模态查找界面，支持大小写敏感与正向/反向搜索切换，
* 通过信号机制与 Spreadsheet 核心业务解耦。
*
* Change Log:
* [v1.0] GY   2026-04-16
* * Initial creation
*/
#pragma once

#include <QDialog>

//class QLabel;
//class QLineEdit;
//class QCheckBox;
//class QPushButton;
//class QString;

// 查找对话框类：非模态设计，通过信号通知父窗口执行查找
class FindDialog : public QDialog
{
    Q_OBJECT
public:
    FindDialog(QWidget *parent = nullptr);

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);      // 正向查找信号
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);  // 反向查找信号

private slots:
    void enableFindButton(const QString &text);  // 输入为空时禁用查找按钮
    void findClicked();                          // 触发查找并发射信号

private:
    /*下面的指针都是便利指针: 便于访问FindDialog的孩子对象*/
    //private:
    //    QLabel *_label = nullptr;
    //    QLineEdit *_lineEdit = nullptr;
    //    QCheckBox *_caseCheckBox = nullptr;
    //    QCheckBox *_backwardCheckBox = nullptr;
    //    QPushButton *_findButton = nullptr;
    //    QPushButton *_closeButton = nullptr;
};