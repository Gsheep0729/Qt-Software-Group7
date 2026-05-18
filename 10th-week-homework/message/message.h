#pragma once

#include <QDateTime>
#include <QtQml/qqmlregistration.h> // 包含 QML 注册相关的头文件
#include <QObject>

// Message 类继承自 QObject，这是在 QML 中使用该类的前提
class Message : public QObject
{
    // Q_OBJECT 宏是必须的，它启用了 Qt 的元对象系统（信号、槽、属性等）
    Q_OBJECT

    // Q_PROPERTY 宏定义了可以从 QML 访问的属性
    // author 属性：类型为 QString，通过 author() 读取，通过 setAuthor() 写入，
    // 当值改变时发送 authorChanged 信号。FINAL 表示该属性不打算在派生类中被重写。
    Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged FINAL)

    // creationDate 属性：类型为 QDateTime，用于存储消息创建的时间
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate NOTIFY creationDateChanged)

    // QML_ELEMENT 宏自动将该类注册到 QML 中。
    // 在 QML 中，可以直接通过类名 Message 来实例化它。
    // 注意：需要在 CMakeLists.txt 中正确配置 qt_add_qml_module。
    QML_ELEMENT

public:
    // 构造函数，parent 参数用于 Qt 的对象树管理
    explicit Message(QObject *parent = nullptr);

    // creationDate 的读取函数（Getter）
    QDateTime creationDate() const;
    // creationDate 的写入函数（Setter）
    void setCreationDate(const QDateTime dt);

    // author 的读取函数（Getter）
    QString author() const;
    // author 的写入函数（Setter）
    void setAuthor(const QString &a);

signals:
    // 当属性值改变时发出的信号，QML 会自动监听这些信号以实现属性绑定
    void authorChanged();
    void creationDateChanged();

private:
    // 私有成员变量，实际存储属性值
    QString m_author;
    QDateTime m_creationDate;
};
