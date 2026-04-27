/**
* @file    DocumentStorage.h
* @date    2026-04-23
* @author  GY
* @brief   文件存储读取与写入底层服务
*
* 负责具体的底层文件 I/O。
* 为 CodeEditorWidget 提供文件操作支撑。
*
* Change Log:
* [v1.0] GY   2026-04-23
* * Initial creation
*/

#pragma once

#include <QString>

// 负责物理层面的文件读写，与业务逻辑完全隔离
class DocumentStorage
{
public:
    DocumentStorage() = default;
    virtual ~DocumentStorage() = default;

    // 执行物理写入操作，成功返回 true
    bool writeFile(const QString& filepath, const QString& text);

    // 执行物理读取操作，内容通过引用参数 text 返回
    bool readFile(const QString& filepath, QString& text);
};
