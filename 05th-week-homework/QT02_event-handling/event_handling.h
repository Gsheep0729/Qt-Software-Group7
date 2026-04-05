/**
* @file    event_handling.h
* @date    2026-04-05
* @author  GY
* @brief   Qt事件处理示例项目的主窗口头文件
*
* 本文件定义了event_handling类，这是一个QMainWindow的子类，
* 用于演示Qt中的事件处理机制和线程操作。该类负责：
* 1. 初始化用户界面
* 2. 创建并管理工作线程
* 3. 将Worker对象移动到子线程执行耗时任务
* 4. 通过信号槽机制实现线程间通信
*
* Change Log:
* [v1.0] GY   2026-04-05
* * Initial creation
*/
#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class event_handling; } // 前置声明
QT_END_NAMESPACE

class event_handling : public QMainWindow {
    Q_OBJECT

public:
    explicit event_handling(QWidget *parent = nullptr);
    ~event_handling() override;

private:
    Ui::event_handling *_ui; // UI界面对象指针
};