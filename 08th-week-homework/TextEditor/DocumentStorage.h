/**
* @file    DocumentStorage.h
* @date    2026-04-27
* @author  GY
* @brief   文件存储读取与写入底层服务
*
* 负责具体的底层文件 I/O。
* 为 TextEditorWidget 提供文件操作支撑。
*
* Change Log:
* [v3.0] GY   2026-04-27
* * Initial creation, 实现读写功能
*/

#pragma once

#include <QString>

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
