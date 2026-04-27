/**
* @file    AppController.cpp
* @date    2026-04-27
* @author  GY
* @brief   AppController 实现文件
*
* 实现文本编辑器的全局控制。
*
* Change Log:
* [v1.0] GY   2026-04-27
* * Initial creation
* [v2.0] GY   2026-04-27
* * 完成信号连接，使用 AppController 完成初始化
* [v3.0] GY   2026-04-27
* * 实现全局单例模式，完善 open 和 save 业务逻辑流
*/

#include "AppController.h"
#include "MainWindow.h"
#include "TextEditorWidget.h"
#include <QDebug>

AppController& AppController::instance()
{
    static AppController inst;
    return inst;
}

AppController::AppController(QObject *parent)
    : QObject{parent}
{
}

AppController::~AppController() = default;

void AppController::launch()
{
    assembleComponents();
    setupConnections();

    if (_window) {
        _window->show();
    }
}

void AppController::assembleComponents()
{
    // 创建主窗口
    _window = std::make_unique<MainWindow>();

    // 创建文本编辑器组件，把 _window 作为它的 parent，避免内存泄漏
    _textEditor = new TextEditorWidget(_window.get());

    // 把编辑器放在主窗口的正中间显示
    _window->setCentralWidget(_textEditor);
    
    // 把控制器的指针传给主窗口，这样窗口里面点了按钮就能调到控制器的函数了
    _window->setAppCtrl(this);
}

void AppController::setupConnections()
{
    // 事件路由交由内部处理或依赖注入解决
}

void AppController::newDocument()
{
    if (_textEditor) {
        _textEditor->clear();
    }
}

void AppController::open()
{
    if (!_window || !_textEditor) return;
    QString path = _window->askOpenFilepath();
    if (!path.isEmpty()) {
        _textEditor->openFile(path);
    }
}

void AppController::save()
{
    if (!_window || !_textEditor) return;
    
    // 先看看现在的文档有没有名字、有没有被改过
    bool titled, modified;
    currentState(titled, modified);
    
    // 如果是新建的还没存过的文件，就得弹个框让选存哪儿
    if (!titled) {
        QString path = _window->getSaveFilepath();
        if (!path.isEmpty()) {
            _textEditor->saveDocument(path);
        }
    } else if (modified) {
        // 如果文件之前存过而且现在被改了，就直接悄悄保存就行了
        _textEditor->saveDocument();
    }
}

void AppController::currentState(bool& titled, bool& modified)
{
    // 从编辑器那边把状态拿过来
    if (_textEditor) {
        titled = _textEditor->isTitled();
        modified = _textEditor->isModified();
    } else {
        titled = false;
        modified = false;
    }
}
