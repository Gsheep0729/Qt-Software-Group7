/**
* @file    CodeEditorWidget.h
* @date    2026-04-22
* @author  GY
* @brief   核心纯文本代码编辑控件
*
* 继承 QPlainTextEdit 提供代码编辑支持。
* 封装了相关的 UI 操作和文档管理接口。
*
* Change Log:
* [v1.0] GY   2026-04-22
* * Initial creation
*/

#pragma once

#include <QPlainTextEdit>
#include <QString>

// 核心代码编辑器组件，封装了文档状态管理与业务接口
class CodeEditorWidget : public QPlainTextEdit
{
    Q_OBJECT

public:
    explicit CodeEditorWidget(QWidget *parent = nullptr);
    virtual ~CodeEditorWidget() override = default;

    // 执行保存文档逻辑，若 filepath 为空则使用当前路径
    const QString& saveDocument(const QString& filepath = "");

    // 获取当前文件的纯文件名（不含路径）
    QString fileName() const;

    // 设置文档的修改状态标记
    void setModified(bool f = true);

    // 检查文档是否被修改过
    bool isModified() const;

    // 检查文档是否已经关联物理文件路径
    bool isTitled() const;

    // 重置文档标题状态，用于"新建"场景
    void clearTitle();

    // 打开并读取指定路径的文件内容
    bool openFile(const QString& filepath);

public slots:
    // 清空编辑器内容并重置内部状态
    void clear();

    // 覆盖设置文本内容，作为底层接口使用
    void setPlainText(const QString& text);

private:
    bool _titled{false};   // 是否已保存为真实文件
    bool _modified{false}; // 内容是否发生变更
    QString _filePath;     // 关联的物理路径
};