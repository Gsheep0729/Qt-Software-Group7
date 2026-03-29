/*
 * 文件名:   dialog.h
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-03-29
 * 描述:     /run/media/root/Windows/study/code/group_7_store/Qt-Software-Group7/Week4/finddialog/dialog.h
 * 版权声明: https://github.com/duruoxian
 */
#pragma once

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;
class QCheckBox;

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    // 构造函数
    explicit SearchDialog(QWidget *parent = nullptr);
    // 析构函数
    ~SearchDialog();

    // 禁用拷贝构造和赋值操作
    SearchDialog(const SearchDialog&) = delete;
    SearchDialog& operator=(const SearchDialog&) = delete;

signals:
    // 向前查找信号
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    // 向后查找信号
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    // 文本框文本变化槽
    void onLineEditTextChanged(const QString &text);
    // 查找按钮点击槽
    void onFindButtonClicked();

private:
    // 创建界面元素
    void createWidgets();

private:
    // UI 控件指针
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *findButton;
    QPushButton *closeButton;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
};