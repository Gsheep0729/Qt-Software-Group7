#pragma once
#include <QString>

class DocumentStorage
{
public:
    DocumentStorage();
    bool saveFile(const QString& filePath,const QString& content);
};
