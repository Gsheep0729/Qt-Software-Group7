/**
* @file    TextEditorWidget.cpp
* @date    2026-04-27
* @author  GY
* @brief   TextEditorWidget 实现文件
*
* 实现 TextEditorWidget 类的核心功能。
* 提供代码编辑相关的特性配置和文档读写接口逻辑。
*
* Change Log:
* [v1.0] GY   2026-04-27
* * Initial creation
* [v2.0] GY   2026-04-27
* * 完成信号连接，使用 AppController 完成初始化
* [v3.0] GY   2026-04-27
* * 接入 DocumentStorage 实现 saveDocument 与 openFile
*/

#include "TextEditorWidget.h"
#include "DocumentStorage.h"
#include <QFont>
#include <QFileInfo>

TextEditorWidget::TextEditorWidget(QWidget *parent)
    : QPlainTextEdit{parent}
{
    QFont monoFont("Consolas", 11);
    monoFont.setStyleHint(QFont::Monospace);
    this->setFont(monoFont);
    this->setLineWrapMode(QPlainTextEdit::NoWrap);

    // 文档一有改动，就会发信号，我们捕获它更新一下修改标志
    connect(this->document(), &QTextDocument::modificationChanged, this, [this](bool changed){
        this->setModified(changed);
    });
}

void TextEditorWidget::setModified(bool f)
{
    _modified = f;
    this->document()->setModified(f);
}

const QString& TextEditorWidget::saveDocument(const QString& filepath)
{
    // 确定存储路径：优先采用参数路径，否则使用内部保存的路径
    QString targetPath = filepath.isEmpty() ? _filePath : filepath;
    if (targetPath.isEmpty()) {
        return _filePath; // 路径仍为空则无法执行保存操作
    }
    
    // 调用存储组件将当前文本写入物理文件
    DocumentStorage storage;
    if (storage.writeFile(targetPath, this->toPlainText())) {
        _filePath = targetPath;
        _titled = true; // 标记已有关联路径
        setModified(false); // 保存后重置修改标志
    }
    return _filePath;
}

bool TextEditorWidget::openFile(const QString& filepath)
{
    // 实例化存储组件进行文件读取
    DocumentStorage storage;
    QString text;
    if (storage.readFile(filepath, text)) {
        setPlainText(text);
        _filePath = filepath;
        _titled = true;   // 成功加载后标记为有标题状态
        setModified(false); // 初始化修改标志位
        return true;
    }
    return false;
}

bool TextEditorWidget::isModified() const
{
    // 返回内容是否发生变更的状态
    return _modified;
}

bool TextEditorWidget::isTitled() const
{
    // 判断文档是否已经具有物理文件关联
    return _titled;
}

void TextEditorWidget::clearTitle()
{
    // 重置路径关联信息，常用于"新建"操作
    _titled = false;
    _filePath.clear();
}

QString TextEditorWidget::fileName() const
{
    // 若路径为空则返回默认标题
    if (_filePath.isEmpty()) return "Untitled";
    // 使用 QFileInfo 提取出纯文件名
    return QFileInfo(_filePath).fileName();
}

void TextEditorWidget::clear()
{
    // 执行全量清理：包括内容清空、状态重置
    QPlainTextEdit::clear();
    clearTitle();
    setModified(false);
}

void TextEditorWidget::setPlainText(const QString& text)
{
    // 包装底层的文本设置接口
    QPlainTextEdit::setPlainText(text);
}
