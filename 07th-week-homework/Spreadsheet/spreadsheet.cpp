/**
* @file    spreadsheet.cpp
* @date    2026-04-15
* @author  GY
* @brief   手工构建的电子表格核心逻辑实现
*
* 剥离了 UI 文件的依赖，在纯 C++ 层构建网格视图，管理表格的动态扩展与内容存取。
*
* Change Log:
* [v1.1] GY   2026-04-15
* * Initial creation
* * Enforced C++ uniform initialization (braced-init-list)
* [v1.2] GY   2026-04-15
* * Implemented grid traversal logic for findNext/findPrevious.
*/
#include "spreadsheet.h"
#include <QtWidgets>

Spreadsheet::Spreadsheet(QWidget *parent) : QTableWidget{parent} { setupTable(); }
Spreadsheet::~Spreadsheet() = default;

void Spreadsheet::setupTable() {
    // 设置表格行列上限
    setRowCount(RowCount);
    setColumnCount(ColumnCount);

    // 初始化 A-Z 列标题
    for (int j = 0; j < ColumnCount; ++j) {
        // 使用 static_cast 转成 char，生成 A, B, C... 的标题
        setHorizontalHeaderItem(j, new QTableWidgetItem{QString{QChar{static_cast<char>('A' + j)}}});
    }
}

// -------------------------------------------------------------------
// 槽函数实现：目前仅打印调试信息，之后再对接文件系统
void Spreadsheet::clear() { QTableWidget::clear(); setupTable(); }
void Spreadsheet::readFile(const QString &fileName) { qDebug() << "Reading:" << fileName; }
void Spreadsheet::writeFile(const QString &fileName) { qDebug() << "Writing:" << fileName; }
void Spreadsheet::cut() { qDebug() << "Cut action"; }
void Spreadsheet::copy() { qDebug() << "Copy action"; }
void Spreadsheet::paste() { qDebug() << "Paste action"; }
void Spreadsheet::del() { qDebug() << "Delete action"; }

// 转换为用户熟悉的坐标格式 (如 A1)
QString Spreadsheet::currentLocation() const {
    return QChar('A' + currentColumn()) + QString::number(currentRow() + 1);
}

// 获取当前单元格的内容字符串
QString Spreadsheet::currentFormula() const {
    return currentItem() ? currentItem()->text() : "";
}

// -------------------------------------------------------------------
// 查找算法实现：在网格里按顺序循环查找

// 向后找：从当前焦点的后一个单元格开始匹配
void Spreadsheet::findNext(const QString &str, Qt::CaseSensitivity cs) {
    int row{currentRow()};
    int column{currentColumn() + 1};

    while (row < RowCount) {
        while (column < ColumnCount) {
            // 获取单元格项，如果文本包含搜索词就选中它
            if (auto it = item(row, column); it && it->text().contains(str, cs)) {
                clearSelection();
                setCurrentCell(row, column); 
                activateWindow();
                return;
            }
            ++column;
        }
        column = 0; // 下一行从开头开始
        ++row;
    }
    QApplication::beep(); // 找完还没找到就响个铃
}

// 向前找：逻辑和上面相反，往回遍历
void Spreadsheet::findPrevious(const QString &str, Qt::CaseSensitivity cs) {
    int row{currentRow()};
    int column{currentColumn() - 1};

    while (row >= 0) {
        while (column >= 0) {
            if (auto it = item(row, column); it && it->text().contains(str, cs)) {
                clearSelection();
                setCurrentCell(row, column);
                activateWindow();
                return;
            }
            --column;
        }
        column = ColumnCount - 1; // 上一行从末尾开始
        --row;
    }
    QApplication::beep();
}