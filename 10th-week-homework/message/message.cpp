#include "message.h"

Message::Message(QObject *parent)
    : QObject{parent}
{}

QDateTime Message::creationDate() const
{
    return m_creationDate;
}

QString Message::author() const
{
    return m_author;
}

void Message::setCreationDate(const QDateTime dt)
{
    m_creationDate = dt;
    emit creationDateChanged();
}

void Message::setAuthor(const QString &a)
{
    m_author = a;
    emit authorChanged();
}