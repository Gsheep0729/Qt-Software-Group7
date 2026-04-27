#include "textedit.h"
#include <QFileInfo>

TextEdit::TextEdit(QWidget *parent) : QTextEdit(parent) {}

bool TextEdit::isTitled()
{
    return !m_filePath.isEmpty();
}

QString TextEdit::title()
{
    if (!isTitled())
        return "untitled [*]";
    return QFileInfo(m_filePath).fileName() + "[*]";
}

const QString &TextEdit::filePath() const
{
    return m_filePath;
}

void TextEdit::setFilePath(const QString &filePath)
{
    m_filePath = filePath;
}

void TextEdit::setModified(bool f)
{
    document()->setModified(f);          // 修改文档状态，自动发信号
}