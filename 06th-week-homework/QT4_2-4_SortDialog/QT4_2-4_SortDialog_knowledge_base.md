# 项目: QT4_2-4_SortDialog

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

project(QT4_2-4_SortDialog VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

_qt_add_executable(QT4_2-4_SortDialog)

target_compile_features(QT4_2-4_SortDialog PRIVATE cxx_std_23)

target_sources(QT4_2-4_SortDialog
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
        # birds.cppm           # 模块文件
    PRIVATE
        main.cpp
        sortdialog.cpp
        sortdialog.h
        sortdialog.ui
)

# source_group("birds", FILES birds.cppm)

target_link_libraries(QT4_2-4_SortDialog 
    PRIVATE 
        Qt6::Widgets
)

set_target_properties(QT4_2-4_SortDialog PROPERTIES
    AUTORCC TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
set(CMAKE_INSTALL_PREFIX "/opt/QT4_2-4_SortDialog" CACHE PATH "Install path prefix" FORCE)
install(TARGETS QT4_2-4_SortDialog
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET QT4_2-4_SortDialog
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
#include "sortdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SortDialog dialog;
    dialog.show();
    return QCoreApplication::exec();
}

```

---

### File: sortdialog.h
```cpp
/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/06th-week-homework/QT4_2-4_SortDialog/sortdialog.h
* @date    2026-04-10
* @author  GY
* @brief   Sort Dialog 界面类声明
*
* <这里填写详细描述>
*
* Change Log:
* [v1.0] GY   2026-04-10
* * Initial creation
*/

#pragma once

#include <QDialog>

// 规范：禁止 #include "ui_sortdialog.h"，强制使用前置声明极大缩短编译时间
QT_BEGIN_NAMESPACE
namespace Ui {
    class SortDialog;
}
QT_END_NAMESPACE

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    // 规范：顶层窗口/独立对话框，允许缺省为 nullptr 并在栈上分配
    explicit SortDialog(QWidget *parent = nullptr);

    // 规范：重写虚函数必须添加 override 关键字
    ~SortDialog() override;

    // 规范：继承自 QObject 的类必须禁用拷贝和赋值操作，防止身份（Identity）混淆
    SortDialog(const SortDialog&) = delete;
    SortDialog& operator=(const SortDialog&) = delete;

    // 初始化下拉列表中的列范围 (例如 'A' 到 'Z')
    void setColumnRange(QChar first, QChar last);

private:
    // 规范：使用指针成员组合 UI 生成类，避免多重继承破坏封装性
    Ui::SortDialog *_ui;
};
```

---

### File: sortdialog.ui
```xml
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>SortDialog</class>
 <widget class="QWidget" name="SortDialog">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>379</width>
    <height>348</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>SortDialog</string>
  </property>
  <layout class="QHBoxLayout" name="horizontalLayout">
   <item>
    <layout class="QVBoxLayout" name="verticalLayout">
     <item>
      <widget class="QGroupBox" name="primaryGroupBox">
       <property name="title">
        <string>Primary Key</string>
       </property>
       <layout class="QGridLayout" name="gridLayout_6">
        <item row="0" column="0">
         <widget class="QLabel" name="label">
          <property name="text">
           <string>Column:</string>
          </property>
         </widget>
        </item>
        <item row="0" column="1">
         <widget class="QComboBox" name="primaryColumnCombo"/>
        </item>
        <item row="0" column="2">
         <spacer name="horizontalSpacer">
          <property name="orientation">
           <enum>Qt::Orientation::Horizontal</enum>
          </property>
          <property name="sizeHint" stdset="0">
           <size>
            <width>38</width>
            <height>20</height>
           </size>
          </property>
         </spacer>
        </item>
        <item row="1" column="0">
         <widget class="QLabel" name="label_2">
          <property name="text">
           <string>Order:</string>
          </property>
         </widget>
        </item>
        <item row="1" column="1" colspan="2">
         <widget class="QComboBox" name="primaryOrderCombo"/>
        </item>
       </layout>
      </widget>
     </item>
     <item>
      <spacer name="verticalSpacer">
       <property name="orientation">
        <enum>Qt::Orientation::Vertical</enum>
       </property>
       <property name="sizeHint" stdset="0">
        <size>
         <width>20</width>
         <height>40</height>
        </size>
       </property>
      </spacer>
     </item>
     <item>
      <widget class="QGroupBox" name="secondaryGroupBox">
       <property name="title">
        <string>Secondary Key</string>
       </property>
       <layout class="QGridLayout" name="gridLayout_7">
        <item row="0" column="0">
         <widget class="QLabel" name="label_3">
          <property name="text">
           <string>Column:</string>
          </property>
         </widget>
        </item>
        <item row="0" column="1">
         <widget class="QComboBox" name="secondaryColumnCombo"/>
        </item>
        <item row="0" column="2">
         <spacer name="horizontalSpacer_2">
          <property name="orientation">
           <enum>Qt::Orientation::Horizontal</enum>
          </property>
          <property name="sizeHint" stdset="0">
           <size>
            <width>38</width>
            <height>20</height>
           </size>
          </property>
         </spacer>
        </item>
        <item row="1" column="0">
         <widget class="QLabel" name="label_4">
          <property name="text">
           <string>Order:</string>
          </property>
         </widget>
        </item>
        <item row="1" column="1" colspan="2">
         <widget class="QComboBox" name="secondaryOrderCombo"/>
        </item>
       </layout>
      </widget>
     </item>
     <item>
      <widget class="QGroupBox" name="tertiaryGroupBox">
       <property name="title">
        <string>Tertiary Key</string>
       </property>
       <layout class="QGridLayout" name="gridLayout_8">
        <item row="0" column="0">
         <widget class="QLabel" name="label_5">
          <property name="text">
           <string>Column:</string>
          </property>
         </widget>
        </item>
        <item row="0" column="1">
         <widget class="QComboBox" name="tertiaryColumnCombo"/>
        </item>
        <item row="0" column="2">
         <spacer name="horizontalSpacer_3">
          <property name="orientation">
           <enum>Qt::Orientation::Horizontal</enum>
          </property>
          <property name="sizeHint" stdset="0">
           <size>
            <width>38</width>
            <height>20</height>
           </size>
          </property>
         </spacer>
        </item>
        <item row="1" column="0">
         <widget class="QLabel" name="label_6">
          <property name="text">
           <string>Order:</string>
          </property>
         </widget>
        </item>
        <item row="1" column="1" colspan="2">
         <widget class="QComboBox" name="tertiaryOrderCombo"/>
        </item>
       </layout>
      </widget>
     </item>
    </layout>
   </item>
   <item>
    <layout class="QVBoxLayout" name="verticalLayout_2">
     <item>
      <widget class="QPushButton" name="okButton">
       <property name="text">
        <string>OK</string>
       </property>
      </widget>
     </item>
     <item>
      <spacer name="verticalSpacer_2">
       <property name="orientation">
        <enum>Qt::Orientation::Vertical</enum>
       </property>
       <property name="sizeHint" stdset="0">
        <size>
         <width>20</width>
         <height>40</height>
        </size>
       </property>
      </spacer>
     </item>
     <item>
      <widget class="QLabel" name="label_7">
       <property name="text">
        <string>Qt-Software-Group7</string>
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
     <item>
      <widget class="QPushButton" name="moreButton">
       <property name="text">
        <string>&amp;More</string>
       </property>
       <property name="checkable">
        <bool>true</bool>
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

### File: sortdialog.cpp
```cpp
/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/06th-week-homework/QT4_2-4_SortDialog/sortdialog.cpp
* @date    2026-04-10
* @author  GY
* @brief   Sort Dialog 界面类实现
*
* <这里填写详细描述>
*
* Change Log:
* [v1.0] GY   2026-04-10
* * Initial creation
*/

#include "sortdialog.h"
#include "ui_sortdialog.h" // 仅在 cpp 文件中包含 UI 生成头文件

SortDialog::SortDialog(QWidget *parent)
    : QDialog(parent),
    _ui{new Ui::SortDialog} // 规范：使用现代 C++ 花括号统一初始化，并在堆上分配
{
    _ui->setupUi(this);

    // --- 新增：初始化 Order 下拉框 ---
    // 为三个排序下拉框统一添加选项
    QStringList orderItems;
    orderItems << tr("Ascending") << tr("Descending");

    _ui->primaryOrderCombo->addItems(orderItems);
    _ui->secondaryOrderCombo->addItems(orderItems);
    _ui->tertiaryOrderCombo->addItems(orderItems);
    // ------------------------------

    // 业务逻辑初始化：默认隐藏第二、第三关键字分组
    _ui->secondaryGroupBox->hide();
    _ui->tertiaryGroupBox->hide();

    // 布局约束：当隐藏元素时，让对话框自动收缩到最小需要尺寸
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    // 规范：现代 Qt 6 信号与槽，强制使用函数指针语法 (PMF)，编译期严格类型检查
    // 1. OK 与 Cancel 按钮的路由
    connect(_ui->okButton, &QPushButton::clicked, this, &SortDialog::accept);
    connect(_ui->cancelButton, &QPushButton::clicked, this, &SortDialog::reject);

    // 2. More 按钮的 Toggle 状态控制副关键字组件的可见性
    connect(_ui->moreButton, &QPushButton::toggled, _ui->secondaryGroupBox, &QGroupBox::setVisible);
    connect(_ui->moreButton, &QPushButton::toggled, _ui->tertiaryGroupBox, &QGroupBox::setVisible);

    // 初始化下拉框的默认内容
    setColumnRange('A', 'Z');
}

SortDialog::~SortDialog()
{
    // 规范：Ui 类不在 Qt 对象树范围内，必须在此显式释放以防内存泄漏
    delete _ui;
}

void SortDialog::setColumnRange(QChar first, QChar last)
{

    // 清空现有项
    _ui->primaryColumnCombo->clear();
    _ui->secondaryColumnCombo->clear();
    _ui->tertiaryColumnCombo->clear();

    // 次要关键字允许选择 "None"
    _ui->secondaryColumnCombo->addItem(tr("None"));
    _ui->tertiaryColumnCombo->addItem(tr("None"));

    _ui->primaryColumnCombo->setMinimumSize(_ui->secondaryColumnCombo->sizeHint());

    // 填充字符范围
    QChar ch = first;
    while (ch <= last) {
        _ui->primaryColumnCombo->addItem(QString(ch));
        _ui->secondaryColumnCombo->addItem(QString(ch));
        _ui->tertiaryColumnCombo->addItem(QString(ch));

        // 修正行：显式使用构造函数将 int 转换回 QChar
        ch = QChar(ch.unicode() + 1);
    }
}
```

---

