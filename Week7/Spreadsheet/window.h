/*
 * 文件名:   window.h
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-04-19
 * 描述:     /run/media/root/Windows/study/code/Qt-Software-Group7/Week7/Spreadsheet/window.h
 * 版权声明: https://github.com/duruoxian
 */
#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QToolBar;
class QLabel;
class FindDialog;
QT_END_NAMESPACE

class Spreadsheet;

// 主窗口类：管理表格、菜单栏、工具栏和状态栏
class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);

    // 禁用拷贝和赋值
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    virtual ~Window() override;

private slots:
    void updateStatusBar();
    void find();

private:
    // 初始化UI界面
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();

    Spreadsheet *m_table;

    // 文件菜单动作
    QAction *m_actionNew;
    QAction *m_actionOpen;
    QAction *m_actionSave;
    QAction *m_actionExit;

    // 编辑菜单动作
    QAction *m_actionCut;
    QAction *m_actionCopy;
    QAction *m_actionPaste;
    QAction *m_actionDelete;

    // 其他动作
    QAction *m_actionAbout;
    QAction *m_actionFind;

    // 菜单对象
    QMenu *m_fileMenu;
    QMenu *m_editMenu;
    QMenu *m_helpMenu;

    // 工具栏对象
    QToolBar *m_fileToolbar;
    QToolBar *m_editToolbar;

    // 状态栏标签
    QLabel *m_cellLabel;
    QLabel *m_contentLabel;

    // 查找对话框，延迟加载
    FindDialog *m_findDialog;
};