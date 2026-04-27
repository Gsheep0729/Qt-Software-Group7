/**
* @file    EditorController.cpp
* @date    2026-04-22
* @author  GY
* @brief   EditorController 实现文件
*
* 实现应用程序的控制器逻辑。
* 负责统筹组装 MainWindow 和 CodeEditorWidget 等组件。
*
* Change Log:
* [v1.0] GY   2026-04-22
* * Initial creation
*/

#include "EditorController.h"
#include "MainWindow.h"
#include "CodeEditorWidget.h"
#include <QDebug>

EditorController& EditorController::instance()
{
    static EditorController inst;
    return inst;
}

EditorController::EditorController(QObject *parent)
    : QObject{parent}
{
}

EditorController::~EditorController() = default;

void EditorController::launch()
{
    assembleComponents();
    setupConnections();

    if (window) {
        window->show();
    }
}

void EditorController::assembleComponents()
{
    // 实例化主容器窗口
    window = std::make_unique<MainWindow>();

    // 实例化代码编辑器，并将其生命周期挂载到窗口对象树上（内存防泄漏红线）
    _textEditor = new CodeEditorWidget(window.get());

    // 依赖注入：将编辑器组件装配到主窗口的中心区域，MainWindow 对此过程无感知
    window->setCentralWidget(_textEditor);
    
    // 建立双向弱关联（Transient Link），允许视图反向通知控制器
    window->setAppCtrl(this);
}

void EditorController::setupConnections()
{
    // 事件路由交由内部处理或依赖注入解决
}

void EditorController::newDocument()
{
    if (_textEditor) {
        _textEditor->clear();
    }
}

void EditorController::open()
{
    if (!window || !_textEditor) return;
    QString path = window->askOpenFilepath();
    if (!path.isEmpty()) {
        _textEditor->openFile(path);
    }
}

void EditorController::save()
{
    if (!window || !_textEditor) return;
    
    // 获取文档当前的属性状态
    bool titled, modified;
    currentState(titled, modified);
    
    // 逻辑：若文档尚未关联路径（新文件），则必须弹出另存为对话框
    if (!titled) {
        QString path = window->getSaveFilepath();
        if (!path.isEmpty()) {
            _textEditor->saveDocument(path);
        }
    } else if (modified) {
        // 若已有关联路径且内容有变，则直接执行静默保存
        _textEditor->saveDocument();
    }
}

void EditorController::currentState(bool& titled, bool& modified)
{
    if (_textEditor) {
        titled = _textEditor->isTitled();
        modified = _textEditor->isModified();
    } else {
        titled = false;
        modified = false;
    }
}