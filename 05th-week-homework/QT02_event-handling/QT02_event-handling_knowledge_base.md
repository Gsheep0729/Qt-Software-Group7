# 项目: QT02_event-handling

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

project(QT02_event-handling VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

_qt_add_executable(QT02_event-handling)

target_compile_features(QT02_event-handling PRIVATE cxx_std_23)

target_sources(QT02_event-handling
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
        # birds.cppm           # 模块文件
    PRIVATE
        main.cpp
        event_handling.cpp
        event_handling.h
        event_handling.ui
)

# source_group("birds", FILES birds.cppm)

target_link_libraries(QT02_event-handling 
    PRIVATE 
        Qt6::Widgets
)

set_target_properties(QT02_event-handling PROPERTIES
    AUTORCC TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
set(CMAKE_INSTALL_PREFIX "/opt/QT02_event-handling" CACHE PATH "Install path prefix" FORCE)
install(TARGETS QT02_event-handling
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET QT02_event-handling
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
#include "event_handling.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    event_handling w;
    w.show();
    return QCoreApplication::exec();
}

```

---

### File: event_handling.h
```cpp
#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class event_handling;
}
QT_END_NAMESPACE

class event_handling : public QMainWindow
{
    Q_OBJECT

public:
    explicit event_handling(QWidget *parent = nullptr);
    ~event_handling() override;

private:
    Ui::event_handling *ui;
};

```

---

### File: event_handling.ui
```xml
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>event_handling</class>
 <widget class="QMainWindow" name="event_handling">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>800</width>
    <height>600</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>event_handling</string>
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

### File: event_handling.cpp
```cpp
#include "event_handling.h"
#include "./ui_event_handling.h"

event_handling::event_handling(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::event_handling)
{
    ui->setupUi(this);
}

event_handling::~event_handling()
{
    delete ui;
}

```

---

