#include "textedit.h"

#include <QFileInfo>

TextEdit::TextEdit(QWidget *parent)
    : QTextEdit(parent)
{}

bool TextEdit::isTitled()
{
    return !m_filePath.isEmpty();
}

QString TextEdit::title()
{
    if (!isTitled())
        return "untitled [*]";
    else
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

void TextEdit::setModified(bool f) {
    document()->setModified(f);
    emit document()->modificationChanged(f);
}