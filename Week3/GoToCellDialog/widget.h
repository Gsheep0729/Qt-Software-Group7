/*
 * 文件名:   widget.h
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-03-22
 * 描述:     /run/media/root/Windows/study/code/group_7_store/Qt-Software-Group7/GoToCellDialog/widget.h
 * 版权声明: https://github.com/duruoxian
 */
#pragma once

#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onGoToCellClicked();

private:
    QPushButton *goToCellButton;
};


