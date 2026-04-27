/**
* @file    EditorController.h
* @date    2026-04-22
* @author  GY
* @brief   代码编辑器全局控制器，负责装配 UI 与核心逻辑组件
*
* 引入 Controller 模式，接管 MainWindow 与 Editor 的组装。
* 负责隔离底层组件依赖，管理全局对象的生命周期。
*
* Change Log:
* [v1.0] GY   2026-04-22
* * Initial creation
*/

#pragma once

#include <QObject>
#include <memory>

class MainWindow;
class CodeEditorWidget;

// 中介者控制器：核心枢纽，负责隔离视图与具体业务逻辑，管理对象生命周期
class EditorController : public QObject
{
    Q_OBJECT

public:
    // 遵循单例模式，全局共享唯一的控制器实例
    static EditorController& instance();

    virtual ~EditorController() override;

    // 应用程序的启动入口，负责启动装配流程
    void launch();

    // UML 定义的核心业务流：处理"新建"逻辑
    void newDocument();

    // 处理"打开文件"流程，涉及视图弹窗与数据读取的协作
    void open();

    // 处理"保存文件"流程，包含路径判断与状态同步
    void save();

private:
    // 构造函数私有化，确保单例安全性
    explicit EditorController(QObject *parent = nullptr);

    // 聚合底层状态，供控制器决策逻辑使用
    void currentState(bool& titled, bool& modified);

    // 初始化并组装所有核心组件，执行依赖注入
    void assembleComponents();

    // 建立信号路由，实现模块间的弱关联通信
    void setupConnections();

private:
    // 使用智能指针自主管理主窗口生命周期
    std::unique_ptr<MainWindow> window;

    // 编辑器组件指针，实际生命周期受 Qt 对象树托管
    CodeEditorWidget* _textEditor{nullptr};
};