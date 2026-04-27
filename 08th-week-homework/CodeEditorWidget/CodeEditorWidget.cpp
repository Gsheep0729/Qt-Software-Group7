/**
* @file    CodeEditorWidget.cpp
* @date    2026-04-22
* @author  GY
* @brief   CodeEditorWidget 实现文件
*
* 实现 CodeEditorWidget 类的核心功能。
* 提供代码编辑相关的特性配置和文档读写接口逻辑。
*
* Change Log:
* [v1.0] GY   2026-04-22
* * Initial creation
*/

#include "CodeEditorWidget.h"
#include "DocumentStorage.h"
#include <QFont>
#include <QFileInfo>

CodeEditorWidget::CodeEditorWidget(QWidget *parent)
    : QPlainTextEdit{parent}
{
    // 初始化外观：使用等宽字体，禁用自动换行以优化代码阅读体验
    QFont monoFont("Consolas", 11);
    monoFont.setStyleHint(QFont::Monospace);
    this->setFont(monoFont);
    this->setLineWrapMode(QPlainTextEdit::NoWrap);
    
    // 监听文档修改信号，确保 UI 层的变更能实时反映到我们的业务状态变量中
    connect(this->document(), &QTextDocument::modificationChanged, this, [this](bool changed){
        this->setModified(changed);
    });
}

const QString& CodeEditorWidget::saveDocument(const QString& filepath)
{
    // 决定存储路径：优先使用传入参数，否则使用内部记录的路径
    QString targetPath = filepath.isEmpty() ? _filePath : filepath;
    if (targetPath.isEmpty()) {
        return _filePath;
    }
    
    // 调用存储层组件执行实际写入，成功后更新内部状态标识
    DocumentStorage storage;
    if (storage.writeFile(targetPath, this->toPlainText())) {
        _filePath = targetPath;
        _titled = true;
        setModified(false);
    }
    return _filePath;
}

QString CodeEditorWidget::fileName() const
{
    if (_filePath.isEmpty()) return "Untitled";
    return QFileInfo(_filePath).fileName();
}

void CodeEditorWidget::setModified(bool f)
{
    _modified = f;
    this->document()->setModified(f);
}

bool CodeEditorWidget::isModified() const
{
    return _modified;
}

bool CodeEditorWidget::isTitled() const
{
    return _titled;
}

void CodeEditorWidget::clearTitle()
{
    _titled = false;
    _filePath.clear();
}

bool CodeEditorWidget::openFile(const QString& filepath)
{
    DocumentStorage storage;
    QString text;
    if (storage.readFile(filepath, text)) {
        setPlainText(text);
        _filePath = filepath;
        _titled = true;
        setModified(false);
        return true;
    }
    return false;
}

void CodeEditorWidget::clear()
{
    QPlainTextEdit::clear();
    clearTitle();
    setModified(false);
}

void CodeEditorWidget::setPlainText(const QString& text)
{
    QPlainTextEdit::setPlainText(text);
}