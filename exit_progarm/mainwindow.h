/*
 * 文件名:   mainwindow.h
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-03-29
 * 描述:     /run/media/root/Windows/study/code/group_7_store/Qt-Software-Group7/Week4/exit_progarm/mainwindow.h
 * 版权声明: https://github.com/duruoxian
 */
#pragma once

#include <QMainWindow>

class QCloseEvent;
class QAction;

class AppWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit AppWindow(QWidget* parent = nullptr);
    ~AppWindow();

    AppWindow(const AppWindow&) = delete;
    AppWindow& operator=(const AppWindow&) = delete;

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void onExitTriggered();

private:
    bool checkBeforeClose();
    void createMenu();

private:
    QAction* exitAction;
};