# 项目: QT02_Button-program

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

project(QT02_Button-program VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

_qt_add_executable(QT02_Button-program)

target_compile_features(QT02_Button-program PRIVATE cxx_std_23)

target_sources(QT02_Button-program
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
        # birds.cppm           # 模块文件
    PRIVATE
        main.cpp
        button_program.cpp
        button_program.h
        button_program.ui
)

# source_group("birds", FILES birds.cppm)

target_link_libraries(QT02_Button-program 
    PRIVATE 
        Qt6::Widgets
)

set_target_properties(QT02_Button-program PROPERTIES
    AUTORCC TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
set(CMAKE_INSTALL_PREFIX "/opt/QT02_Button-program" CACHE PATH "Install path prefix" FORCE)
install(TARGETS QT02_Button-program
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET QT02_Button-program
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
#include "button_program.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Button_program w;
    w.show();
    return QCoreApplication::exec();
}

```

---

### File: button_program.h
```cpp
#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class Button_program;
}
QT_END_NAMESPACE

class Button_program : public QMainWindow
{
    Q_OBJECT

public:
    explicit Button_program(QWidget *parent = nullptr);
    ~Button_program() override;

private:
    Ui::Button_program *ui;
};

```

---

### File: button_program.ui
```xml
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>Button_program</class>
 <widget class="QMainWindow" name="Button_program">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>800</width>
    <height>600</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Button_program</string>
  </property>
  <widget class="QWidget" name="centralwidget"/>
  <widget class="QMenuBar" name="menubar">
   <property name="geometry">
    <rect>
     <x>0</x>
     <y>0</y>
     <width>800</width>
     <height>21</height>
    </rect>
   </property>
  </widget>
  <widget class="QStatusBar" name="statusbar"/>
 </widget>
 <resources/>
 <connections/>
</ui>

```

---

### File: button_program.cpp
```cpp
#include "button_program.h"
#include "./ui_button_program.h"

Button_program::Button_program(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Button_program)
{
    ui->setupUi(this);
}

Button_program::~Button_program()
{
    delete ui;
}

```

---

