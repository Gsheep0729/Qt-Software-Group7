/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/05th-week-homework/QT02_Button-program/button.h
* @date    2026-04-05
* @author  GY
* @brief   自定义按钮类，继承自QPushButton，提供特殊的鼠标事件处理
*
* 该类实现了自定义的按钮控件，具有以下特性：
* 1. 按钮可以被拖拽移动（通过鼠标释放事件）
* 2. 支持双击事件，发射自定义信号
* 3. 重写了鼠标释放和双击事件处理函数
*
* Change Log:
* [v1.0] GY   2026-04-05
* * Initial creation
*/
#pragma once

#include <QPushButton>

class Button : public QPushButton {
    Q_OBJECT

public:

    explicit Button(QWidget *parent = nullptr);

    // 禁用拷贝构造和赋值操作，防止对象复制
    Button(const Button&) = delete;
    Button& operator=(const Button&) = delete;


    virtual ~Button() override = default;

signals:
    void doubleClicked(bool checked = false);

protected:

    //重写鼠标释放事件，实现按钮拖拽功能,event 鼠标事件对象
    void mouseReleaseEvent(QMouseEvent *event) override;
    
    //重写鼠标双击事件，发射双击信号,event 鼠标事件对象
    void mouseDoubleClickEvent(QMouseEvent *event) override;
};