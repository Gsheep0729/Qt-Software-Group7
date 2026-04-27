#pragma once
#include <QObject>
#include <QFile>
#include <QTextStream>

class DocumentStorage : public QObject
{
    Q_OBJECT
public:
    explicit DocumentStorage(QObject *parent = nullptr);
    bool writeFile(const QString &filePath, const QString &text);

private:
    QFile m_file;
    QTextStream m_ofs;
};