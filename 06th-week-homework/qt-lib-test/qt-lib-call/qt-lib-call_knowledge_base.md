# 项目: qt-lib-call

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

project(qt-lib-call VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

_qt_add_executable(qt-lib-call)

target_compile_features(qt-lib-call PRIVATE cxx_std_23)

# 1. 定义库的安装根目录
set(LIB_INSTALL_DIR "/opt/QT4_2-3_dialog-library")

target_sources(qt-lib-call
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
        # birds.cppm           # 模块文件
    PRIVATE
        main.cpp
        # widget.cpp
        # widget.h
)

# source_group("birds", FILES birds.cppm)

# 2. 添加头文件搜索路径，这样 main.cpp 才能找到 "widget.h"
target_include_directories(dialog-call-demo PRIVATE ${LIB_SRC_DIR})
# 2. 添加头文件搜索路径 (现在指向 /opt/.../include)
target_include_directories(dialog-call-demo PRIVATE "${LIB_INSTALL_DIR}/include")

# 3. 修改链接逻辑
target_link_libraries(qt-lib-call 
    PRIVATE 
        Qt6::Widgets
        "${LIB_INSTALL_DIR}/lib/libQT4_2-3_dialog-library.so" # 3.链接具体的库文件
)

set_target_properties(qt-lib-call PROPERTIES
    #AUTORCC TRUE
    #WIN32_EXECUTABLE TRUE
    BUILD_RPATH "${LIB_INSTALL_DIR}/lib"
    INSTALL_RPATH "${LIB_INSTALL_DIR}/lib"
    AUTORCC TRUE
)

include(GNUInstallDirs)
set(CMAKE_INSTALL_PREFIX "/opt/qt-lib-call" CACHE PATH "Install path prefix" FORCE)
install(TARGETS qt-lib-call

    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET qt-lib-call
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

