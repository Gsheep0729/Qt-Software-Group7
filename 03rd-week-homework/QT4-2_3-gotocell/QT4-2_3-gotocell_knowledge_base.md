# 项目: QT4-2_3-gotocell

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

project(QT4-2_3-gotocell VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(QT4-2_3-gotocell
    gotocelldialog.h gotocelldialog.cpp
    gotocelldialog.ui
    main.cpp
)

target_sources(QT4-2_3-gotocell
    PRIVATE
        #math.cpp                   # 实现单元
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES  FILES
        #math.cppm                  # 接口单元
)

target_compile_features(QT4-2_3-gotocell PRIVATE cxx_std_23)

target_link_libraries(QT4-2_3-gotocell
    PRIVATE
        Qt6::Widgets
)

set_target_properties(QT4-2_3-gotocell PROPERTIES
    AUTORCC TRUE
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QT4-2_3-gotocell
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
#         gotocelldialog.cpp
#         gotocelldialog.h
#     @if true
#         gotocelldialog.ui
#     @endif
#     @if false
#         ${TS_FILES}
#     @endif
# )
#
# if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#     qt_add_executable(QT4-2_3-gotocell
#         MANUAL_FINALIZATION
#         ${PROJECT_SOURCES}
#     )
# # Define target properties for Android with Qt 6 as:
# #    set_property(TARGET QT4-2_3-gotocell APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
# #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
# @if false
#     qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
# @endif
# else()
#     if(ANDROID)
#         add_library(QT4-2_3-gotocell SHARED
#             ${PROJECT_SOURCES}
#         )
# # Define properties for Android with Qt 5 after find_package() calls as:
# #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#     else()
#         add_executable(QT4-2_3-gotocell
#             ${PROJECT_SOURCES}
#         )
#     endif()
# @if false
#
#     qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
# @endif
# endif()
#
# target_link_libraries(QT4-2_3-gotocell
#     PRIVATE
#         Qt${QT_VERSION_MAJOR}::Widgets
# )
#
# # Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# # If you are developing for iOS or macOS you should consider setting an
# # explicit, fixed bundle identifier manually though.
# if(${QT_VERSION} VERSION_LESS 6.1.0)
#   set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QT4-2_3-gotocell)
# endif()
#
# set_target_properties(QT4-2_3-gotocell PROPERTIES
#     AUTORCC TRUE
#     ${BUNDLE_ID_OPTION}
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )
#
# include(GNUInstallDirs)
# install(TARGETS QT4-2_3-gotocell
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )
#
# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(QT4-2_3-gotocell) #该命令在CMake3.19以后已经不需要使用了
# endif()



#qt_add_executable(QT4-2_3-gotocell)  //Creates and finalizes an application target of a platform-specific type.
#This command performs the following tasks:

#    1. Create a CMake target of the appropriate type for the target platform.
#    2. Link the target to the Qt::Core library.
#    3. Handle finalization of the CMake target.

```

---

## 项目源文件
---

### File: gotocelldialog.h
```cpp
#pragma once

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class GoToCellDialog; }
QT_END_NAMESPACE

class GoToCellDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GoToCellDialog(QWidget *parent = nullptr);
    ~GoToCellDialog();

private slots:
    // 自动连接槽函数：命名格式必须严格为 on_<objectName>_<signalName>
    void on_lineEdit_textChanged();

private:
    Ui::GoToCellDialog *ui;
};

```

---

### File: gotocelldialog.cpp
```cpp
#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GoToCellDialog)
{
    ui->setupUi(this);

    // 设置正则表达式验证器：允许1个大小写字母，后跟1到3个数字 (例如 A1, Z999)
    QRegularExpression regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegularExpressionValidator(regExp, this));

    // OK 和 Cancel 按钮直接连接到 QDialog 内置的 accept() 和 reject() 槽
    connect(ui->okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

GoToCellDialog::~GoToCellDialog()
{
    delete ui;
}

// 槽函数实现：当输入合法时，才启用 OK 按钮
void GoToCellDialog::on_lineEdit_textChanged()
{
    // hasAcceptableInput() 会根据上面设置的正则表达式验证器来判断输入是否合法
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}

```

---

### File: main.cpp
```cpp
#include "gotocelldialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GoToCellDialog w;
    w.show();
    return a.exec();
}

```

---

