/*
 * 文件名:   mainwindow.cpp
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-03-29
 * 描述:     /run/media/root/Windows/study/code/group_7_store/Qt-Software-Group7/Week4/exit_progarm/mainwindow.cpp
 * 版权声明: https://github.com/duruoxian
 */
#include "mainwindow.h"

#include <QCloseEvent>
#include <QMessageBox>
#include <QMenuBar>
#include <QAction>

AppWindow::AppWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("应用程序"));
    resize(400, 300);

    createMenu();
}

AppWindow::~AppWindow() {
}

void AppWindow::createMenu() {
    QMenu* fileMenu = menuBar()->addMenu(tr("文件"));

    exitAction = fileMenu->addAction(tr("退出"));
    connect(exitAction, &QAction::triggered, this, &AppWindow::onExitTriggered);
}

void AppWindow::onExitTriggered() {
    close();
}

void AppWindow::closeEvent(QCloseEvent* event) {
    if (checkBeforeClose()) {
        event->accept();
    } else {
        event->ignore();
    }
}

bool AppWindow::checkBeforeClose() {
    const QMessageBox::StandardButton result = QMessageBox::question(
        this,
        tr("确认退出"),
        tr("您要退出程序吗？"),
        QMessageBox::Yes | QMessageBox::No,
        QMessageBox::No
        );

    return (result == QMessageBox::Yes);
}