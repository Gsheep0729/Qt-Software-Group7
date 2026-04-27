/**
* @file    MainWindow.h
* @date    2026-04-22
* @author  GY
* @brief   代码编辑器主窗口顶层容器
*
* 剥离核心文本编辑逻辑。
* 仅负责顶层窗口布局、用户事件暴露，保持 Dumb View 特性。
*
* Change Log:
* [v1.0] GY   2026-04-22
* * Initial creation
*/

#pragma once

#include <QMainWindow>
#include <QCloseEvent>
#include <QString>

class EditorController;

QT_BEGIN_NAMESPACE
namespace Ui { class tw_MainWindow; }
QT_END_NAMESPACE

// 顶层视图窗口：作为 UI 容器，仅负责界面交互展示与原始信号转发
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() override;

    // 设置反向链接，实现视图向控制器的意图转发
    void setAppCtrl(EditorController* ctrl);

    // 封装标准保存对话框，返回选定的路径字符串
    QString getSaveFilepath();

    // 执行退出前的预检查逻辑，处理保存/放弃意图
    bool askExitEditing();

    // 弹出确认保存对话框，返回用户的选择意图编码
    int askSaveChanges();

    // 封装标准打开对话框，返回选定的文件物理路径
    QString askOpenFilepath();

public slots:
    // 响应菜单/工具栏的保存动作，转发给控制器执行
    void on_action_Save_triggered();

protected:
    // 拦截窗口关闭事件，执行业务层面的退出检查逻辑
    virtual void closeEvent(QCloseEvent *event) override;

private:
    Ui::tw_MainWindow *_ui;        // Pimpl 指针，彻底隔离 UI 自动生成的代码依赖
    EditorController* _appCtrl{nullptr}; // 弱关联控制器引用
};