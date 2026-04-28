/*
 * 文件名:   finddialog.h
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-04-17
 * 描述:     /run/media/root/Windows/study/code/Qt-Software-Group7/Week7/Spreadsheet/finddialog.h
 * 版权声明: https://github.com/duruoxian
 */
#pragma once

#include <QDialog>

// 查找对话框类：非模态设计，通过信号通知父窗口执行查找
class FindDialog : public QDialog
{
    Q_OBJECT
public:
    FindDialog(QWidget *parent = nullptr);

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void enableFindButton(const QString &text);
    void findClicked();

private:
    // 便利指针：便于访问FindDialog的孩子对象
};