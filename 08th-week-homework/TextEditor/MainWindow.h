/**
* @file    MainWindow.h
* @date    2026-04-27
* @author  GY
* @brief   文本编辑器主窗口顶层容器
*
* 剥离核心文本编辑逻辑。
* 仅负责顶层窗口布局、用户事件暴露，保持 Dumb View 特性。
*
* Change Log:
* [v1.0] GY   2026-04-27
* * Initial creation
* [v2.0] GY   2026-04-27
* * 完成信号连接，使用 AppController 完成初始化
*/

#pragma once

#include <QMainWindow>
#include <QString>
#include <QCloseEvent>

class AppController;

QT_BEGIN_NAMESPACE
namespace Ui { class tw_MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() override;

    // 设置反向链接，实现视图向控制器的意图转发
    void setAppCtrl(AppController* ctrl);

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
    Ui::tw_MainWindow *_ui;
    AppController* _appCtrl{nullptr}; // 弱关联控制器引用
};
