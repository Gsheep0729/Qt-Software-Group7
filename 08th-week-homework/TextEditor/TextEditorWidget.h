/**
* @file    TextEditorWidget.h
* @date    2026-04-27
* @author  GY
* @brief   核心纯文本代码编辑控件
*
* 继承 QPlainTextEdit 提供代码编辑支持。
* 封装了相关的 UI 操作和文档管理接口。
*
* Change Log:
* [v1.0] GY   2026-04-27
* * Initial creation
* [v2.0] GY   2026-04-27
* * 完成信号连接，使用 AppController 完成初始化
* [v3.0] GY   2026-04-27
* * 接入 DocumentStorage 实现 saveDocument 与 openFile
*/

#pragma once

#include <QPlainTextEdit>
#include <QString>

class TextEditorWidget : public QPlainTextEdit
{
    Q_OBJECT

public:
    explicit TextEditorWidget(QWidget *parent = nullptr);
    virtual ~TextEditorWidget() override = default;

    // 执行保存文档逻辑，若 filepath 为空则使用当前路径
    const QString& saveDocument(const QString& filepath = "");

    // 打开并读取指定路径的文件内容
    bool openFile(const QString& filepath);

    // 设置文档的修改状态标记
    void setModified(bool f = true);

    // 检查文档是否被修改过
    bool isModified() const;

    // 检查文档是否已经关联物理文件路径
    bool isTitled() const;

    // 重置文档标题状态，用于"新建"场景
    void clearTitle();

    // 获取当前文件的纯文件名
    QString fileName() const;

public slots:
    // 清空编辑器内容并重置内部状态
    void clear();

    // 覆盖设置文本内容，作为底层接口使用
    void setPlainText(const QString& text);

private:
    bool _titled{false};
    bool _modified{false};
    QString _filePath;
};
