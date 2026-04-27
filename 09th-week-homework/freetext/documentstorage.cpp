#include "documentstorage.h"

DocumentStorage::DocumentStorage(QObject *parent)
    : QObject{parent}
{}

bool DocumentStorage::writeFile(const QString &filePath, const QString &text)
{
    m_file.setFileName(filePath);
    if (!m_file.open(QFile::WriteOnly | QFile::Text))
        return false;

    m_ofs.setDevice(&m_file);
    m_ofs << text;
    bool ok = (m_ofs.status() == QTextStream::Ok);
    m_file.close();
    return ok;
}