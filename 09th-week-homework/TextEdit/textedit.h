#pragma once

#include <QTextEdit>
#include <QObject>
#include <QWidget>

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
