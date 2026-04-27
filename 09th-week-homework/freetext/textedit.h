#pragma once
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