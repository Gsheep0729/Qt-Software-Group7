/**
* @file    window.h
* @date    2026-04-15
* @author  GY
* @brief   手工构建的主窗口容器头文件
*
* 摒弃 .ui 自动生成，纯 C++ 声明了基于 QMainWindow 的核心交互框架。
* 统筹托管 Spreadsheet 中心部件，并对其周围的菜单、工具栏及状态栏进行对象组合。
*
* Change Log:
* [v1.0] GY   2026-04-15
* * Initial creation
* [v1.2] GY   2026-04-15
* * Added FindDialog pointer and find() slot for non-modal integration.
*/
#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QToolBar;
class QLabel;
class FindDialog; // 添加前置声明
QT_END_NAMESPACE

class Spreadsheet;

// 主窗口类：管理表格组件、菜单栏、工具栏和状态栏
class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);

    // 禁用拷贝和赋值，保证窗口对象唯一
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    virtual ~Window() override;

private slots:
    void updateStatusBar();  // 更新状态栏上的坐标和内容
    void find();             // 打开查找对话框

private:
    // 初始化 UI 界面
    void createActions();    // 创建菜单和工具栏里的动作
    void createMenus();      // 创建菜单栏
    void createToolBars();   // 创建工具栏
    void createStatusBar();  // 创建状态栏

    Spreadsheet *_spreadsheet;  // 表格组件指针

    // 各个菜单项/按钮对应的动作
    QAction *_newAction;
    QAction *_openAction;
    QAction *_saveAction;
    QAction *_exitAction;

    QAction *_cutAction;
    QAction *_copyAction;
    QAction *_pasteAction;
    QAction *_deleteAction;

    QAction *_aboutAction;
    QAction *_findAction;       // 查找动作

    // 菜单对象
    QMenu *_fileMenu;
    QMenu *_editMenu;
    QMenu *_helpMenu;

    // 工具栏对象
    QToolBar *_fileToolBar;
    QToolBar *_editToolBar;

    // 状态栏标签
    QLabel *_locationLabel;     // 显示坐标 (如 B5)
    QLabel *_formulaLabel;      // 显示内容

    FindDialog *_findDialog{nullptr};  // 查找窗口，初始为空，点查找时再创建
};