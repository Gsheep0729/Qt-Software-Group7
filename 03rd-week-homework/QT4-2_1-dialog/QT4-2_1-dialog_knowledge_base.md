# 项目: QT4-2_1-dialog

## 项目特征总结





---

## 构建配置文件
---

### File: CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 4.1.1)

#https://github.com/Kitware/CMake/blob/v4.1.1/Help/dev/experimental.rst

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)

project(QT4-2_1-dialog VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(QT4-2_1-dialog
    widget.h widget.cpp
    main.cpp
)

target_sources(QT4-2_1-dialog
    PRIVATE
        #math.cpp                   # 实现单元
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES  FILES
        #math.cppm                  # 接口单元
)

target_compile_features(QT4-2_1-dialog PRIVATE cxx_std_23)

target_link_libraries(QT4-2_1-dialog
    PRIVATE
        Qt6::Widgets
)

set_target_properties(QT4-2_1-dialog PROPERTIES
    AUTORCC TRUE
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QT4-2_1-dialog
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

































# set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
# @if false
# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)
#
# set(TS_FILES )
# @else
# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
# @endif
#
# qt_standard_project_setup()
#
# set(PROJECT_SOURCES
#         main.cpp
#         widget.cpp
#         widget.h
#     @if false
#         mainwindow.ui
#     @endif
#     @if false
#         ${TS_FILES}
#     @endif
# )
#
# if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#     qt_add_executable(QT4-2_1-dialog
#         MANUAL_FINALIZATION
#         ${PROJECT_SOURCES}
#     )
# # Define target properties for Android with Qt 6 as:
# #    set_property(TARGET QT4-2_1-dialog APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
# #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
# @if false
#     qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
# @endif
# else()
#     if(ANDROID)
#         add_library(QT4-2_1-dialog SHARED
#             ${PROJECT_SOURCES}
#         )
# # Define properties for Android with Qt 5 after find_package() calls as:
# #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#     else()
#         add_executable(QT4-2_1-dialog
#             ${PROJECT_SOURCES}
#         )
#     endif()
# @if false
#
#     qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
# @endif
# endif()
#
# target_link_libraries(QT4-2_1-dialog
#     PRIVATE
#         Qt${QT_VERSION_MAJOR}::Widgets
# )
#
# # Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# # If you are developing for iOS or macOS you should consider setting an
# # explicit, fixed bundle identifier manually though.
# if(${QT_VERSION} VERSION_LESS 6.1.0)
#   set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QT4-2_1-dialog)
# endif()
#
# set_target_properties(QT4-2_1-dialog PROPERTIES
#     AUTORCC TRUE
#     ${BUNDLE_ID_OPTION}
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )
#
# include(GNUInstallDirs)
# install(TARGETS QT4-2_1-dialog
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )
#
# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(QT4-2_1-dialog) #该命令在CMake3.19以后已经不需要使用了
# endif()



#qt_add_executable(QT4-2_1-dialog)  //Creates and finalizes an application target of a platform-specific type.
#This command performs the following tasks:

#    1. Create a CMake target of the appropriate type for the target platform.
#    2. Link the target to the Qt::Core library.
#    3. Handle finalization of the CMake target.

```

---

## 项目源文件
---

### File: widget.cpp
```cpp
/**
* @file    widget.cpp
* @date    2026-03-22
* @author  GY
* @brief   实现《C++ GUI Qt4编程》2.1节 查找对话框
*
* 实现查找对话框的布局、信号槽连接以及具体查找逻辑。
* 支持快捷键伙伴设置、按钮使能控制以及根据复选框状态发出不同的查找信号。
*
* Change Log:
* [v1.0] GY   2026-03-22
* * Initial creation
*/
#include "widget.h"
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QDialog(parent)
{
    // 1. 实例化子窗口部件
    label = new QLabel(tr("Find &what:"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit); // 设置快捷键伙伴(Alt+W定位到输入框)

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);   // 回车键默认触发此按钮
    findButton->setEnabled(false);  // 初始状态下禁用

    closeButton = new QPushButton(tr("Close"));

    // 2. 连接信号与槽 (使用Qt5/6的函数指针语法，替代书中的SIGNAL/SLOT宏)
    connect(lineEdit, &QLineEdit::textChanged,
            this, &Widget::enableFindButton);
    connect(findButton, &QPushButton::clicked,
            this, &Widget::findClicked);
    connect(closeButton, &QPushButton::clicked,
            this, &Widget::close);

    // 3. 布局管理
    // 左上角的水平布局 (标签 + 输入框)
    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    // 左侧的垂直布局 (包含左上水平布局 + 两个复选框)
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    // 右侧的垂直布局 (包含两个按钮和弹簧)
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch(); // 添加弹簧，将按钮顶在上方

    // 主布局：水平排列左侧布局和右侧布局
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    // 应用主布局
    setLayout(mainLayout);

    // 设置窗口属性
    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height()); // 固定窗口高度为最佳尺寸
}

Widget::~Widget()
{
    // Qt的对象树机制会自动释放作为子对象的控件内存，
    // 因为没有用到 Ui::Widget，所以不需要 delete ui;
}

// 槽函数：点击查找按钮时的逻辑
void Widget::findClicked()
{
    QString text = lineEdit->text();
    // 判断是否区分大小写
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive
                                                       : Qt::CaseInsensitive;
    // 根据向后查找复选框的状态发出不同的信号
    if (backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }
}

// 槽函数：根据输入框是否有文本来启用或禁用“Find”按钮
void Widget::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}

```

---

### File: main.cpp
```cpp
/**
* @file    main.cpp
* @date    2026-03-19
* @author  GY
* @brief   项目入口文件，启动查找对话框
*
* 创建 QApplication 实例并显示查找对话框主窗口。
*
* Change Log:
* [v1.0] GY   2026-03-19
* * Initial creation
*/
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

```

---

### File: widget.h
```cpp
/**
* @file    widget.h
* @date    2026-03-22
* @author  GY
* @brief   实现《C++ GUI Qt4编程》2.1节 查找对话框
*
* 定义了一个查找对话框类 Widget，支持输入查找内容、区分大小写以及向后查找。
* 包含 UI 部件的指针声明、信号和私有槽函数。
*
* Change Log:
* [v1.0] GY   2026-03-22
* * Initial creation
*/
#pragma once

#include <QDialog>

// 前向声明，减少头文件依赖
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class Widget : public QDialog
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

// 声明自定义信号
signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

// 声明私有槽函数
private slots:
    void findClicked();
    void enableFindButton(const QString &text);

private:
    // 界面控件指针
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};

```

---

