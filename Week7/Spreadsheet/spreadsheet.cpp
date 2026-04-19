/*
 * 文件名:   spreadsheet.cpp
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-04-17
 * 描述:     /run/media/root/Windows/study/code/Qt-Software-Group7/Week7/Spreadsheet/spreadsheet.cpp
 * 版权声明: https://github.com/duruoxian
 */
#include "spreadsheet.h"
#include <QtWidgets>

Spreadsheet::Spreadsheet(QWidget *parent) : QTableWidget(parent) { setupTable(); }
Spreadsheet::~Spreadsheet() = default;

void Spreadsheet::setupTable() {
    // 设置表格行列上限
    setRowCount(RowCount);
    setColumnCount(ColumnCount);

    // 初始化A-Z列标题
    for (int j = 0; j < ColumnCount; ++j) {
        setHorizontalHeaderItem(j, new QTableWidgetItem(QString(QChar('A' + j))));
    }
}

// 清空表格
void Spreadsheet::clear() { QTableWidget::clear(); setupTable(); }

// 从文件读取
void Spreadsheet::readFile(const QString &fileName) { qDebug() << "Reading:" << fileName; }

// 保存到文件
void Spreadsheet::writeFile(const QString &fileName) { qDebug() << "Writing:" << fileName; }

// 剪切操作
void Spreadsheet::cut() { qDebug() << "Cut action"; }

// 复制操作
void Spreadsheet::copy() { qDebug() << "Copy action"; }

// 粘贴操作
void Spreadsheet::paste() { qDebug() << "Paste action"; }

// 删除操作
void Spreadsheet::del() { qDebug() << "Delete action"; }

// 转换为用户熟悉的坐标格式(如A1)
QString Spreadsheet::currentLocation() const {
    return QChar('A' + currentColumn()) + QString::number(currentRow() + 1);
}

// 获取当前单元格的内容字符串
QString Spreadsheet::currentFormula() const {
    return currentItem() ? currentItem()->text() : "";
}

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
        column = 0;
        ++row;
    }
    QApplication::beep();
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
        column = ColumnCount - 1;
        --row;
    }
    QApplication::beep();
}