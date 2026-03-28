# 项目: QT4-2_2-dialog

## 项目特征总结





---

## 构建配置文件
---

### File: CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 4.2.3)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)
function(_qt_add_executable target)
    qt_add_executable(${target})
endfunction()

project(QT4-2_2-dialog VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

_qt_add_executable(QT4-2_2-dialog)

target_compile_features(QT4-2_2-dialog PRIVATE cxx_std_23)

target_sources(QT4-2_2-dialog
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
        # birds.cppm           # 模块文件
    PRIVATE
        main.cpp
        widget.cpp
        widget.h
        widget.ui
)

# source_group("birds", FILES birds.cppm)

target_link_libraries(QT4-2_2-dialog 
    PRIVATE 
        Qt6::Widgets
)

set_target_properties(QT4-2_2-dialog PROPERTIES
    AUTORCC TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
set(CMAKE_INSTALL_PREFIX "/opt/QT4-2_2-dialog" CACHE PATH "Install path prefix" FORCE)
install(TARGETS QT4-2_2-dialog
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET QT4-2_2-dialog
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

```

---

## 项目源文件
---

### File: main.cpp
```cpp
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return QCoreApplication::exec();
}

```

---

### File: widget.h
```cpp
/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/04th-week-homework/QT4-2_2-dialog/widget.h
* @date    2026-03-28
* @author  GY
* @brief   查找对话框类的头文件声明
*
* 本文件定义了Widget类，这是一个查找对话框，提供了查找文本的功能。
* 该类使用了多重继承的方式，同时继承自QDialog和Ui::Widget，
* 这样可以直接访问UI界面中的控件，而不需要通过ui指针。
*
* Change Log:
* [v1.0] GY   2026-03-28
* * Initial creation
*/
#pragma once

#include <QDialog>
#include "ui_widget.h"

// 多重继承：同时继承 QDialog 和 Ui::Widget
class Widget : public QDialog, public Ui::Widget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);      // 向前查找信号
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);   // 向后查找信号

private slots:
    // 使用Qt自动关联机制：函数名格式为 on_控件名_信号名()
    void on_lineEdit_textChanged(const QString &text);  // 文本变化槽
    void on_findButton_clicked();                        // 查找按钮点击槽
};
```

---

### File: widget.cpp
```cpp
/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/04th-week-homework/QT4-2_2-dialog/widget.cpp
* @date    2026-03-28
* @author  GY
* @brief   查找对话框类的实现文件
*
* 本文件实现了Widget类的功能，包括对话框的初始化、
* 文本输入框的变化处理、以及查找按钮的点击事件处理。
*
* Change Log:
* [v1.0] GY   2026-03-28
* * Initial creation
*/

#include "widget.h"

/**
 * @brief Widget类的构造函数
 * @param parent 父窗口指针
 */
Widget::Widget(QWidget *parent)
    : QDialog(parent)
{
    // 自动加载UI界面，实例化所有控件
    setupUi(this);

    // 设置label和lineEdit的伙伴关系（快捷键关联）
    label->setBuddy(lineEdit);

    // 设置查找按钮为默认按钮（按Enter触发）
    findButton->setDefault(true);

    // 初始状态下禁用查找按钮（输入框为空）
    findButton->setEnabled(false);

    // 连接关闭按钮的点击信号到关闭槽
    connect(closeButton, &QPushButton::clicked, this, &Widget::close);
}

/**
 * @brief 文本输入框内容变化的槽函数
 * @param text 输入框中的当前文本
 *
 * 使用Qt自动关联机制：函数名格式为 on_控件名_信号名()
 */
void Widget::on_lineEdit_textChanged(const QString &text)
{
    // 根据输入内容是否为空来启用或禁用查找按钮
    findButton->setEnabled(!text.isEmpty());
}

/**
 * @brief 查找按钮点击事件的槽函数
 *
 * 使用Qt自动关联机制
 */
void Widget::on_findButton_clicked()
{
    QString text = lineEdit->text();

    // 根据复选框设置是否区分大小写
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;

    // 根据查找方向发射相应的信号
    if (backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);  // 向后查找
    } else {
        emit findNext(text, cs);      // 向前查找
    }
}
```

---

