/**
* @file    DocumentStorage.cpp
* @date    2026-04-27
* @author  GY
* @brief   DocumentStorage 实现文件
*
* 实现底层文件 I/O 操作。
*
* Change Log:
* [v3.0] GY   2026-04-27
* * Initial creation, 实现读写功能
*/

#include "DocumentStorage.h"
#include <QFile>
#include <QTextStream>

bool DocumentStorage::writeFile(const QString& filepath, const QString& text)
{
    QFile file(filepath);
    // 只写模式加上文本模式打开文件
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    // 用文本流写进去就行了
    QTextStream out(&file);
    out << text;
    return true;
}

bool DocumentStorage::readFile(const QString& filepath, QString& text)
{
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    // 把文件里所有字儿都读出来塞给引用参数
    QTextStream in(&file);
    text = in.readAll();
    return true;
}
