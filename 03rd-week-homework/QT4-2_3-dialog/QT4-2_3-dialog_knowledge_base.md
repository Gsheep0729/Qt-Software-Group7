# 项目: QT4-2_3-dialog

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

project(QT4-2_3-dialog VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(QT4-2_3-dialog
    widget.h widget.cpp
    widget.ui
    main.cpp
)

target_sources(QT4-2_3-dialog
    PRIVATE
        #math.cpp                   # 实现单元
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES  FILES
        #math.cppm                  # 接口单元
)

target_compile_features(QT4-2_3-dialog PRIVATE cxx_std_23)

target_link_libraries(QT4-2_3-dialog
    PRIVATE
        Qt6::Widgets
)

set_target_properties(QT4-2_3-dialog PROPERTIES
    AUTORCC TRUE
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QT4-2_3-dialog
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
#     @if true
#         widget.ui
#     @endif
#     @if false
#         ${TS_FILES}
#     @endif
# )
#
# if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#     qt_add_executable(QT4-2_3-dialog
#         MANUAL_FINALIZATION
#         ${PROJECT_SOURCES}
#     )
# # Define target properties for Android with Qt 6 as:
# #    set_property(TARGET QT4-2_3-dialog APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
# #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
# @if false
#     qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
# @endif
# else()
#     if(ANDROID)
#         add_library(QT4-2_3-dialog SHARED
#             ${PROJECT_SOURCES}
#         )
# # Define properties for Android with Qt 5 after find_package() calls as:
# #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#     else()
#         add_executable(QT4-2_3-dialog
#             ${PROJECT_SOURCES}
#         )
#     endif()
# @if false
#
#     qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
# @endif
# endif()
#
# target_link_libraries(QT4-2_3-dialog
#     PRIVATE
#         Qt${QT_VERSION_MAJOR}::Widgets
# )
#
# # Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# # If you are developing for iOS or macOS you should consider setting an
# # explicit, fixed bundle identifier manually though.
# if(${QT_VERSION} VERSION_LESS 6.1.0)
#   set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QT4-2_3-dialog)
# endif()
#
# set_target_properties(QT4-2_3-dialog PROPERTIES
#     AUTORCC TRUE
#     ${BUNDLE_ID_OPTION}
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )
#
# include(GNUInstallDirs)
# install(TARGETS QT4-2_3-dialog
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )
#
# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(QT4-2_3-dialog) #该命令在CMake3.19以后已经不需要使用了
# endif()



#qt_add_executable(QT4-2_3-dialog)  //Creates and finalizes an application target of a platform-specific type.
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
* @brief   使用 Qt Designer 方式重写查找对话框
*
* 通过 ui->setupUi() 注入 Designer 生成的界面对象。
* 使用 C++23 的 import std 规范以及 try-catch 包裹核心逻辑。
*
* Change Log:
* [v1.0] GY   2026-03-22
* * Initial creation
*/

#include "widget.h"
#include "ui_widget.h" // 必须包含自动生成的头文件

Widget::Widget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Widget) // 实例化 UI 指针
{
    // 1. 初始化界面（依据 widget.ui 的描述）
    ui->setupUi(this);

    // 2. 绑定自定义信号槽（Close 按钮已在 .ui 文件中绑定）
    connect(ui->lineEdit, &QLineEdit::textChanged,
            this, &Widget::enableFindButton);
    connect(ui->findButton, &QPushButton::clicked,
            this, &Widget::findClicked);

    // 3. 补充的窗口设置
    setFixedHeight(sizeHint().height()); // 固定窗口高度为最佳尺寸
}

Widget::~Widget()
{
    // 现在用到了 Ui::Widget，必须手动释放
    delete ui;
}

void Widget::findClicked()
{
    QString text = ui->lineEdit->text();
    // 控件访问全部加上 ui-> 前缀
    Qt::CaseSensitivity cs = ui->caseCheckBox->isChecked() ? Qt::CaseSensitive
                                                           : Qt::CaseInsensitive;

    if (ui->backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }
}

void Widget::enableFindButton(const QString &text)
{
    ui->findButton->setEnabled(!text.isEmpty());
}

```

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

// 声明 Ui 命名空间中的 Widget 类（由 uic 工具根据 widget.ui 自动生成）
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QDialog
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

```

---

