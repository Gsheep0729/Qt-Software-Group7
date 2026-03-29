/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/04th-week-homework/QT02_Exit-program/mainwindow.cpp
* @date    2026-03-29
* @author  GY
* @brief   主窗口类的实现文件
*
* 本文件实现了MainWindow类的功能，包括主窗口的初始化和析构。
* MainWindow类继承自QMainWindow，使用了Pimpl(指针实现)模式来管理UI界面。
*
* Change Log:
* [v1.0] GY   2026-03-29
* * Initial creation
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCloseEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow{parent},
    _ui{new Ui::MainWindow} // 堆分配
{
    _ui->setupUi(this);

    // 1. 设置菜单栏动作：假设已经在 Designer 中创建了名为 actionExit 的 Action
    // 如果是纯代码创建，需在此处 new QAction 并传入 this

    // 2. 信号与槽：现代 Qt 6 强类型连接（如果 Designer 未自动关联）
    connect(_ui->actionExit, &QAction::triggered, this, &MainWindow::on_actionExit_triggered);
}

MainWindow::~MainWindow() {
    delete _ui; // 必须手动释放，Ui 类不在对象树中
}

/**
 * @brief 点击菜单“退出”或工具栏退出按钮时触发
 */
void MainWindow::on_actionExit_triggered() {
    // 调用 close() 会触发 closeEvent
    this->close();
}

/**
 * @brief 核心拦截逻辑：无论是点击 [X] 还是点击菜单“退出”，最终都会进入此函数
 */
void MainWindow::closeEvent(QCloseEvent* event) {
    if (confirmExit()) {
        event->accept(); // 允许关闭，程序进入析构流程
    } else {
        event->ignore(); // 忽略事件，程序继续运行
    }
}

/**
 * @brief 退出确认对话框
 */
bool MainWindow::confirmExit() {
    const QMessageBox::StandardButton btn = QMessageBox::question(
        this,
        tr("退出程序"),
        tr("您确定要退出吗？"),
        QMessageBox::Yes | QMessageBox::No,
        QMessageBox::No
        );

    return (btn == QMessageBox::Yes);
}