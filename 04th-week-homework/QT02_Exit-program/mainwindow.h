/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/04th-week-homework/QT02_Exit-program/mainwindow.h
* @date    2026-03-29
* @author  GY
* @brief   主窗口类的头文件声明
*
* 本文件定义了MainWindow类，这是应用程序的主窗口类，继承自QMainWindow。
* 该类使用了Pimpl(指针实现)模式来管理UI界面，通过Ui::MainWindow指针
* 来访问和操作UI界面中的控件，这种方式可以降低编译依赖，提高编译效率。
*
* Change Log:
* [v1.0] GY   2026-03-29
* * Initial creation
*/
#pragma once

#include <QMainWindow>

// 【修正点】：必须补充 QCloseEvent 的前置声明，极大化利用前置声明原则
class QCloseEvent;

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

    // 现代 C++23：禁用拷贝与赋值
    MainWindow(const MainWindow&) = delete;
    MainWindow& operator=(const MainWindow&) = delete;

protected:
    // 重写关闭事件，用于拦截用户点击窗口 [X] 按钮的行为
    void closeEvent(QCloseEvent* event) override;

private slots:
    // 自动关联槽函数：严格遵循 on_<objectName>_<signalName> 命名
    void on_actionExit_triggered();

private:
    // 退出确认逻辑封装
    bool confirmExit();

private:
    // UI 指针管理，生命周期需手动隔离
    Ui::MainWindow* _ui;
};