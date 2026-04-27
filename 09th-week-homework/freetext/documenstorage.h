#pragma once

#include <QObject>

class DocumenStorage : public QObject
{
    Q_OBJECT
public:
    explicit DocumenStorage(QObject *parent = nullptr);

signals:
};
