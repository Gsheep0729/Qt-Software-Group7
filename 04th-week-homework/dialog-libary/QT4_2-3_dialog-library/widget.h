/**
* @file    widget.h
* @date    2026-03-22
* @author  GY
* @brief   实现《C++ GUI Qt4编程》2.3节 查找对话框 (基于 Qt Designer)
*
* 使用 ui 界面文件分离视图与逻辑，摒弃了纯代码布局。
* 包含 UI 命名空间前向声明、UI 指针以及重构后的槽函数。
*
* Change Log:
* [v1.0] GY   2026-03-22
* * Initial creation
*/
#pragma once

#include <QDialog>
#include "QT4_2-3_dialog-library_global.h"  // 包含全局导出宏的头文件

// 声明 Ui 命名空间中的 Widget 类（由 uic 工具根据 widget.ui 自动生成）
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QT4_2_3_DIALOG_LIBRARY_EXPORT Widget : public QDialog
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void findClicked();
    void enableFindButton(const QString &text);

private:
    Ui::Widget *ui; // 指向自动生成的 UI 类的指针
};
