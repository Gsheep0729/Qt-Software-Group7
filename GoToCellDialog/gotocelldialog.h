/*
 * 文件名:   gotocelldialog.h
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-03-22
 * 描述:     /run/media/root/Windows/study/code/group_7_store/Qt-Software-Group7/GoToCellDialog/gotocelldialog.h
 * 版权声明: https://github.com/duruoxian
 */
#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class GoToCellDialog : public QDialog
{
    Q_OBJECT

public:
    GoToCellDialog(QWidget *parent = nullptr);
    QString getCell() const;

private slots:
    void onLineEditTextChanged();

private:
    QLineEdit *lineEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label;
};
