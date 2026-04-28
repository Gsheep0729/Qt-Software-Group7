#pragma once

#include <QObject>

class DocumentStorage : public QObject
{
    Q_OBJECT
public:
    explicit DocumentStorage(QObject *parent = nullptr);

signals:
};
