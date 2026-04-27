#pragma once
// TextEdit提供了文本文档的编辑，其内部包含了一个QTextDocument对象，该对象提供了文档的内容与结构
//
//      用户输入 / 鼠标键盘操作
//              │
//              ▼
//        ┌───────────────┐
//        │   QTextEdit   │
//        │  编辑器控件     │
//        └───────────────┘
//              │
//              │ 持有 / 使用
//              ▼
//        ┌────────────────┐
//        │ QTextDocument  │
//        │   文档模型       │
//        └────────────────┘
//                   │
//    ┌──────────────┼──────┬─────────┐
//    ▼              ▼      ▼         ▼
//     QTextCursor 格式结构  文本内容   撤销/重做
//      光标编辑   块/表格/帧  plain/html  undo/redo

//
//              ┌─────────────────────┐
//              │      QTextEdit      │
//              │     负责显示与交互     │
//              └─────────┬───────────┘
//                        │ document()
//                        ▼
//              ┌─────────────────────┐
//              │    QTextDocument    │
//              │    负责内容与结构     │
//              └───────┬───────┬─────┘
//                      │       │
//     cursor操作文档    │       │ highlighter作用于文档
//                      │       │
//                      ▼       ▼
//              ┌───────────┐ ┌───────────────────┐
//              │QTextCursor│ │QSyntaxHighlighter │
//              │  编辑工具  │ │    语法高亮器       │
//              └───────────┘ └───────────────────┘



#include <QTextEdit>


class TextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit TextEdit(QWidget *parent = nullptr);

    bool isTitled();
    QString title();
    const QString &filePath() const;
    void setFilePath(const QString &filePath);
    void setModified(bool f = true);
private:
    QString m_filePath;
};
