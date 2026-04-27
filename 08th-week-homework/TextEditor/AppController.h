/**
* @file    AppController.h
* @date    2026-04-27
* @author  GY
* @brief   文本编辑器全局控制器
*
* 引入 Controller 模式，接管 MainWindow 与 Editor 的组装。
* 负责隔离底层组件依赖，管理全局对象的生命周期。
*
* Change Log:
* [v1.0] GY   2026-04-27
* * Initial creation
* [v2.0] GY   2026-04-27
* * 完成信号连接，使用 AppController 完成初始化
* [v3.0] GY   2026-04-27
* * 实现全局单例模式，完善 open 和 save 业务逻辑流
*/

#pragma once

#include <QObject>
#include <memory>

class MainWindow;
class TextEditorWidget;

// 中介者控制器：核心枢纽，负责隔离视图与具体业务逻辑，管理对象生命周期
class AppController : public QObject
{
    Q_OBJECT

public:
    // 遵循单例模式，全局共享唯一的控制器实例
    static AppController& instance();

    virtual ~AppController() override;

    // 应用程序的启动入口，负责启动装配流程
    void launch();

    // UML 定义的核心业务流：处理"新建"逻辑
    void newDocument();

    // 处理"打开文件"流程
    void open();

    // 处理"保存文件"流程 (第三次迭代中完成实际功能)
    void save();

private:
    // 构造函数私有化，确保单例安全性
    explicit AppController(QObject *parent = nullptr);

    // 聚合底层状态，供控制器决策逻辑使用
    void currentState(bool& titled, bool& modified);

    // 初始化并组装所有核心组件，执行依赖注入
    void assembleComponents();

    // 建立信号路由，实现模块间的弱关联通信
    void setupConnections();

private:
    std::unique_ptr<MainWindow> _window;
    TextEditorWidget* _textEditor{nullptr};
};
