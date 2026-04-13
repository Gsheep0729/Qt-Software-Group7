# 项目: GoToCellDialog

## 项目特征总结





---

## 构建配置文件
---

### File: CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 4.2.3)

#https://github.com/Kitware/CMake/blob/v4.2.3/Help/dev/experimental.rst

project(GoToCellDialog LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 需要同时查找 Core 和 Widgets（QDialog 等类依赖 Core）
# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

add_library(GoToCellDialog SHARED
  GoToCellDialog_global.h
  gotocelldialog.cpp
  gotocelldialog.h
  gotocelldialog.ui
)

# target_link_libraries(GoToCellDialog PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
# 必须同时链接 Core 和 Widgets（这是 dialog-library 成功的关键）
target_link_libraries(GoToCellDialog PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
)

# 不动，导出宏定义
target_compile_definitions(GoToCellDialog PRIVATE GOTOCELLDIALOG_LIBRARY)


# C++ modules support
# set(GOTOCELLDIALOG_MODULE_FILES
#     # math.cppm                             # 模块文件
# )
# source_group("GoToCellDialog" FILES ${GOTOCELLDIALOG_MODULE_FILES})
#
# target_sources(GoToCellDialog
#     PRIVATE
#         FILE_SET module_files
#         TYPE CXX_MODULES
#         BASE_DIRS
#             ${CMAKE_CURRENT_SOURCE_DIR}
#         FILES
#             ${GOTOCELLDIALOG_MODULE_FILES}
# )


# 设置库属性（必须打开，否则 install 无法正确处理头文件）
set_target_properties(GoToCellDialog PROPERTIES
    PUBLIC_HEADER  "gotocelldialog.h;GoToCellDialog_global.h"  # 库的公共头文件路径
    VERSION  2.0.1                 # realname的完整版本
    SOVERSION  2                   # soname的主版本
)

# Deployment settings
include(GNUInstallDirs)
set(CMAKE_INSTALL_PREFIX "/opt/GoToCellDialog" CACHE PATH "Install path prefix" FORCE)
install(TARGETS GoToCellDialog
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

```

---

## 项目源文件
---

### File: gotocelldialog.ui
```xml
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>GoToCellDialog</class>
 <widget class="QDialog" name="GoToCellDialog">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>260</width>
    <height>80</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Go to Cell</string>
  </property>
  <layout class="QVBoxLayout" name="verticalLayout">
   <item>
    <layout class="QHBoxLayout" name="horizontalLayout">
     <item>
      <widget class="QLabel" name="label">
       <property name="text">
        <string>&amp;Cell Location:</string>
       </property>
       <property name="buddy">
        <cstring>lineEdit</cstring>
       </property>
      </widget>
     </item>
     <item>
      <widget class="QLineEdit" name="lineEdit"/>
     </item>
    </layout>
   </item>
   <item>
    <layout class="QHBoxLayout" name="horizontalLayout_2">
     <item>
      <spacer name="horizontalSpacer">
       <property name="orientation">
        <enum>Qt::Orientation::Horizontal</enum>
       </property>
       <property name="sizeHint" stdset="0">
        <size>
         <width>40</width>
         <height>20</height>
        </size>
       </property>
      </spacer>
     </item>
     <item>
      <widget class="QPushButton" name="okButton">
       <property name="enabled">
        <bool>false</bool>
       </property>
       <property name="text">
        <string>OK</string>
       </property>
       <property name="default">
        <bool>true</bool>
       </property>
      </widget>
     </item>
     <item>
      <widget class="QPushButton" name="cancelButton">
       <property name="text">
        <string>Cancel</string>
       </property>
      </widget>
     </item>
    </layout>
   </item>
  </layout>
 </widget>
 <resources/>
 <connections/>
</ui>

```

---

### File: gotocelldialog.h
```cpp
/**
* @file    gotocelldialog.h
* @date    2026-04-11
* @author  GY
* @brief   定位单元格对话框
*
* Change Log:
* [v1.0] GY   2026-04-11
* * Initial creation
* [v3.0] GY   2026-04-11
* * 使用多重继承方式
* [v4.0] GY   2026-04-11
* * 使用成员变量方式
* [v5.0] GY   2026-04-11
* * 使用 Pimpl（私有指针）实现完全解耦
*/
#pragma once

#include <QDialog>

// 前置声明 UI 类
QT_BEGIN_NAMESPACE
namespace Ui { class GoToCellDialog; }
QT_END_NAMESPACE

// 使用成员变量方式
class GoToCellDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GoToCellDialog(QWidget *parent = nullptr);
    ~GoToCellDialog() override;

    // 禁用拷贝和赋值
    GoToCellDialog(const GoToCellDialog&) = delete;
    GoToCellDialog& operator=(const GoToCellDialog&) = delete;

private slots:
    // 文本改变时更新按钮状态
    void onTextChanged();

private:
    // 使用 Pimpl 模式
    Ui::GoToCellDialog *ui;
};

```

---

### File: gotocelldialog.cpp
```cpp
/**
* @file    gotocelldialog.cpp
* @date    2026-04-11
* @author  GY
* @brief   定位单元格对话框实现
*
* Change Log:
* [v1.0] GY   2026-04-11
* * Initial creation
* [v3.0] GY   2026-04-11
* * 使用多重继承方式
* [v4.0] GY   2026-04-11
* * 使用成员变量方式
* [v5.0] GY   2026-04-11
* * 使用 Pimpl（私有指针）实现完全解耦
*/
#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"
#include <QRegularExpressionValidator>

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GoToCellDialog)
{
    // 加载UI
    ui->setupUi(this);

    // 限制输入格式：字母+数字 (如 A1, Z999)
    QRegularExpression regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegularExpressionValidator(regExp, this));

    // 连接信号槽
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &GoToCellDialog::onTextChanged);
    connect(ui->okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

GoToCellDialog::~GoToCellDialog()
{
    delete ui;
}

void GoToCellDialog::onTextChanged()
{
    // 根据输入有效性启用/禁用OK按钮
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}

```

---

