/**
* @file    DocumentStorage.cpp
* @date    2026-04-23
* @author  GY
* @brief   DocumentStorage 实现文件
*
* 实现底层的文件读写逻辑。
* 遵循 UML 提供 writeFile 与 readFile 接口。
*
* Change Log:
* [v1.0] GY   2026-04-23
* * Initial creation
*/

#include "DocumentStorage.h"
#include <QFile>
#include <QTextStream>

bool DocumentStorage::writeFile(const QString& filepath, const QString& text)
{
    QFile file(filepath);
    // 以纯文本模式打开文件，若打开失败则直接返回
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    
    // 使用文本流进行写入，确保跨平台编码处理
    QTextStream out(&file);
    out << text;
    return true;
}

bool DocumentStorage::readFile(const QString& filepath, QString& text)
{
    QFile file(filepath);
    // 尝试以只读文本模式打开
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    
    // 读取全文并赋值给输出参数
    QTextStream in(&file);
    text = in.readAll();
    return true;
}
