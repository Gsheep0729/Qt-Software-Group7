#include "documentstorage.h"

#include <QFile>
#include <QTextStream>

DocumentStorage::DocumentStorage(QObject *parent)
    : QObject{parent}
{}

bool DocumentStorage::writeFile(QString &filePath, QString &text)
{
    m_file.setFileName(filePath);
    m_file.open(QFile::WriteOnly | QFile::Text);

    if (!m_file.isOpen())
        return false;

    m_ofs.setDevice(&m_file);
    m_ofs << text;
    bool rv = (m_ofs.status() == QTextStream::Ok);

    m_file.close();

    return rv;
}
