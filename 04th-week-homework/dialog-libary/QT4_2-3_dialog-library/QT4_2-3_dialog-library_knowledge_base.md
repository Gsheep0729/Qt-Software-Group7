# 项目: QT4_2-3_dialog-library

## 项目特征总结





---

## 构建配置文件
---

### File: CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 4.2.3)

#https://github.com/Kitware/CMake/blob/v4.2.3/Help/dev/experimental.rst

project(QT4_2-3_dialog-library LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 需要告诉 CMake 去查找 Widgets 组件，而不仅仅是 Core
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

# 将库文件统一生成到项目根目录下的 lib 文件夹中
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_library(QT4_2-3_dialog-library SHARED
  QT4_2-3_dialog-library_global.h
  widget.ui
  widget.cpp
  widget.h
)

#target_link_libraries(QT4_2-3_dialog-library PRIVATE Qt${QT_VERSION_MAJOR}::Core)
# 链接 Widgets 模块
target_link_libraries(QT4_2-3_dialog-library PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
)

# 添加这一行来关闭由于 C++23 引起的 #include 扫描报错
set_target_properties(QT4_2-3_dialog-library PROPERTIES CXX_SCAN_FOR_MODULES OFF)

# 导出宏定义 (模板自带)
target_compile_definitions(QT4_2-3_dialog-library PRIVATE QT4_2_3_DIALOG_LIBRARY_LIBRARY)



# # C++ modules support
# set(QT4_2-3_DIALOG-LIBRARY_MODULE_FILES
#     # math.cppm                             # 模块文件
# )
# source_group("QT4_2-3_dialog-library" FILES ${QT4_2-3_DIALOG-LIBRARY_MODULE_FILES})
#
# target_sources(QT4_2-3_dialog-library
#     PRIVATE
#         FILE_SET module_files
#         TYPE CXX_MODULES
#         BASE_DIRS
#             ${CMAKE_CURRENT_SOURCE_DIR}
#         FILES
#             ${QT4_2-3_DIALOG-LIBRARY_MODULE_FILES}
# )




# 设置库属性，设置对外暴露的公共头文件为 widget.h
set_target_properties(QT4_2-3_dialog-library PROPERTIES
    PUBLIC_HEADER "widget.h;QT4_2-3_dialog-library_global.h"  # 库的公共头文件路径
    VERSION  2.0.1                 # realname的完整版本
    SOVERSION  2                   # soname的主版本
)

# Deployment settings
include(GNUInstallDirs)
set(CMAKE_INSTALL_PREFIX "/opt/QT4_2-3_dialog-library" CACHE PATH "Install path prefix" FORCE)
install(TARGETS QT4_2-3_dialog-library
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

```

---

## 项目源文件
---

### File: widget.ui
```xml
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>Widget</class>
 <widget class="QDialog" name="Widget">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>320</width>
    <height>120</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Find</string>
  </property>
  <layout class="QHBoxLayout" name="mainLayout">
   <item>
    <layout class="QVBoxLayout" name="leftLayout">
     <item>
      <layout class="QHBoxLayout" name="topLeftLayout">
       <item>
        <widget class="QLabel" name="label">
         <property name="text">
          <string>Find &amp;what:</string>
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
      <widget class="QCheckBox" name="caseCheckBox">
       <property name="text">
        <string>Match &amp;case</string>
       </property>
      </widget>
     </item>
     <item>
      <widget class="QCheckBox" name="backwardCheckBox">
       <property name="text">
        <string>Search &amp;backward</string>
       </property>
      </widget>
     </item>
    </layout>
   </item>
   <item>
    <layout class="QVBoxLayout" name="rightLayout">
     <item>
      <widget class="QPushButton" name="findButton">
       <property name="enabled">
        <bool>false</bool>
       </property>
       <property name="text">
        <string>&amp;Find</string>
       </property>
       <property name="default">
        <bool>true</bool>
       </property>
      </widget>
     </item>
     <item>
      <widget class="QPushButton" name="closeButton">
       <property name="text">
        <string>Close</string>
       </property>
      </widget>
     </item>
     <item>
      <spacer name="verticalSpacer">
       <property name="orientation">
        <enum>Qt::Vertical</enum>
       </property>
       <property name="sizeHint" stdset="0">
        <size>
         <width>20</width>
         <height>40</height>
        </size>
       </property>
      </spacer>
     </item>
    </layout>
   </item>
  </layout>
 </widget>
 <resources/>
 <connections>
  <connection>
   <sender>closeButton</sender>
   <signal>clicked()</signal>
   <receiver>Widget</receiver>
   <slot>close()</slot>
  </connection>
 </connections>
</ui>
```

---

### File: QT4_2-3_dialog-library_global.h
```cpp
#pragma once

#include <QtCore/qglobal.h>

#if defined(QT4_2_3_DIALOG_LIBRARY_LIBRARY)
#define QT4_2_3_DIALOG_LIBRARY_EXPORT Q_DECL_EXPORT
#else
#define QT4_2_3_DIALOG_LIBRARY_EXPORT Q_DECL_IMPORT
#endif

```

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

```

---

