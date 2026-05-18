# 项目: QML

## 项目特征总结





---

## 构建配置文件
---

### File: CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 4.2.3)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)

project(QML VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Quick)
qt_standard_project_setup(REQUIRES 6.10)

# 1. 可执行文件
qt_add_executable(appQML
    WIN32
    main.cpp
)

# 2. QML 模块 → 名字绝对不能叫 QML！！！
qt_add_qml_module(appQMLplugin
    URI MyApp       # ✅ 修复在这里！
    VERSION 1.0
    QML_FILES Main.qml
)

target_compile_features(appQML PRIVATE cxx_std_23)

# 3. 链接
target_link_libraries(appQML
    PRIVATE Qt6::Quick appQMLplugin
)

set(CMAKE_INSTALL_PREFIX "/opt/${PROJECT_NAME}" CACHE PATH "Install path prefix" FORCE)
install(TARGETS appQML
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# C++ Modules
set(QML_MODULE_FILES
    # math.cppm
)
source_group("QML" FILES ${QML_MODULE_FILES})
target_sources(appQML
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES ${QML_MODULE_FILES}
)

```

---

## 项目源文件
---

### File: main.cpp
```cpp
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QML", "Main");

    return QCoreApplication::exec();
}

```

---

