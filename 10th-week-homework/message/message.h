#pragma once

#include<QDateTime>
#include <QtQml/qqmlregistration.h>

#include <QObject>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged FINAL)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate NOTIFY creationDateChanged)

    QML_ELEMENT
public:
    explicit Message(QObject *parent = nullptr);

    QDateTime creationDate() const;
    void setCreationDate(const QDateTime dt);

    QString author() const;
    void setAuthor(const QString &a);

signals:
    void authorChanged();
    void creationDateChanged();

private:
    QString m_author;
    QDateTime m_creationDate;
};
