/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/05th-week-homework/QT02_Button-program/button_program.h
* @date    2026-04-05
* @author  GY
* @brief   Qt主窗口类，用于创建和管理应用程序界面
*
* 该类是程序的主窗口，继承自QMainWindow。它负责创建并管理自定义Button控件，
* 处理按钮的双击事件信号。通过信号槽机制，实现按钮事件与主窗口的通信。
*
* Change Log:
* [v1.0] GY   2026-04-05
* * Initial creation
*/
#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class Button_program; // 前置声明，避免循环依赖
}
QT_END_NAMESPACE


class Button_program : public QMainWindow {
    Q_OBJECT

public:

    explicit Button_program(QWidget *parent = nullptr);
    
    ~Button_program() override;

private:
    Ui::Button_program *_ui; // UI界面对象指针，由Qt Designer生成的类管理
};