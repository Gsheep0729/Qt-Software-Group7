//Created By Chunlin Feng 1356962534@qq.com
//2026-3-19
//this is the headers files for null ptr use

#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

class FindDialog : public QDialog
{
    Q_OBJECT
public:
    explicit FindDialog(QWidget *parent = nullptr);

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void findClicked();
    void enableFindButton(const QString &text);
//这里的private不使用指针的形式要完成相同的效果 故可以直接使用成员函数的类型进行操作
private:
    QLabel      label;
    QLineEdit   lineEdit;
    QCheckBox   caseCheckBox;
    QCheckBox   backwardCheckBox;
    QPushButton findButton;
    QPushButton closeButton;

    QHBoxLayout topLayout;
    QHBoxLayout checkLayout;
    QHBoxLayout btnLayout;
    QVBoxLayout mainLayout;
};

#endif // FINDDIALOG_H