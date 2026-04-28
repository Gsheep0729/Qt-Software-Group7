#pragma once
#include "documentstorage.h"

class AppController
{
public:
    AppController();
    void saveText(const QString &text);

private:
    DocumentStorage *m_storage;
};

