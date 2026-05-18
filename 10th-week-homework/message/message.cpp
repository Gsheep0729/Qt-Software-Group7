#include "message.h"

// 构造函数实现
Message::Message(QObject *parent)
    : QObject{parent}
{
    // 可以在这里初始化成员变量，或者保留为空
}

// 获取创建时间的函数
QDateTime Message::creationDate() const
{
    return m_creationDate;
}

// 获取作者名字的函数
QString Message::author() const
{
    return m_author;
}

// 设置创建时间的函数
void Message::setCreationDate(const QDateTime dt)
{
    // 如果新旧值相同，通常不进行操作以优化性能
    if (m_creationDate == dt)
        return;

    m_creationDate = dt;
    // 重要：当属性值改变时，必须发出对应的信号
    // 这样 QML 中绑定到该属性的 UI 组件才会自动更新
    emit creationDateChanged();
}

// 设置作者名字的函数
void Message::setAuthor(const QString &a)
{
    if (m_author == a)
        return;

    m_author = a;
    // 发出属性改变信号
    emit authorChanged();
}