#pragma once
#include <QString>

class DocumentStorage
{
public:
    bool saveToFile(const QString &content, const QString &filePath);
};