#pragma once

#include <QTextStream>
#include <QFile>

class DocumentStorage : public QObject
{
    Q_OBJECT
public:
    explicit DocumentStorage(QObject *parent = nullptr);
    bool writeFile(QString &filePath, QString &text);

private:
    QTextStream m_ofs;
    QFile m_file;
};
