#include "documentstorage.h"

DocumentStorage::DocumentStorage(QObject *parent)
    : QObject{parent}
{}

bool DocumentStorage::writeFile(const QString &filePath, const QString &text)
{
    QFile file(filePath);
    if (!file.open(QFile::WriteOnly | QFile::Text))
        return false;

    QTextStream out(&file);
    out << text;
    file.close();
    return true;
}
