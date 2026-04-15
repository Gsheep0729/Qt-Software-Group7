/**
* @file    spreadsheet.h
* @date    2026-04-15
* @author  GY
* @brief   补全业务接口后的电子表格类
*
* Change Log:
* [v1.1] GY   2026-04-15
* * Added slots for File IO and Clipboard operations to match Window requirements.
*/
#pragma once
#include <QTableWidget>

// 电子表格类，继承 QTableWidget 处理核心数据展示
class Spreadsheet : public QTableWidget {
    Q_OBJECT
public:
    explicit Spreadsheet(QWidget *parent = nullptr);
    Spreadsheet(const Spreadsheet&) = delete;      // 禁用拷贝，避免数据冲突
    Spreadsheet& operator=(const Spreadsheet&) = delete;
    virtual ~Spreadsheet() override;

    [[nodiscard]] QString currentLocation() const;   // 返回当前单元格坐标 (如 "A1")
    [[nodiscard]] QString currentFormula() const;    // 返回单元格里的文本或公式

public slots:
    void clear();                                   // 清空表格并重置
    void readFile(const QString &fileName);         // 从文件加载数据
    void writeFile(const QString &fileName);        // 保存数据到文件
    void cut();                                     // 剪切
    void copy();                                    // 复制
    void paste();                                   // 粘贴
    void del();                                     // 删除选中内容
    
    // 查找功能接口
    void findNext(const QString &str, Qt::CaseSensitivity cs);      // 向后查找
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);  // 向前查找

private:
    static constexpr int RowCount = 999;    // 最大行数
    static constexpr int ColumnCount = 26;  // 最大列数 (A-Z)
    void setupTable();                      // 初始化表格的行列和标题
};