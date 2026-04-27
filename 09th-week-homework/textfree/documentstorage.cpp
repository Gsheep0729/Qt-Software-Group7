#include "documentstorage.h"

DocumentStorage::DocumentStorage(QObject *parent)
    : QObject{parent}
{}

bool DocumentStorage::writeFile(QString &filePath, QString &text){}