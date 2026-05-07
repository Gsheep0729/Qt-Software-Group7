cmake_minimum_required(VERSION 4.2.3)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)

project(qmltest VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Quick)
qt_standard_project_setup(REQUIRES 6.10)

qt_add_executable(appqmltest  WIN32)
qt_add_qml_module(appqmltest
    URI qmltest
    VERSION 1.0
    SOURCES     main.cpp
    QML_FILES   Main.qml
)
target_compile_features(appqmltest PRIVATE cxx_std_23)
target_link_libraries(appqmltest
    PRIVATE Qt6::Quick
)

set(CMAKE_INSTALL_PREFIX "/opt/${PROJECT_NAME}" CACHE PATH "Install path prefix" FORCE)
install(TARGETS appqmltest
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# C++ Modules support
set(QMLTEST_MODULE_FILES
    # math.cppm                             # 模块文件
)
source_group("qmltest" FILES ${QMLTEST_MODULE_FILES})
target_sources(appqmltest
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES
        BASE_DIRS   ${CMAKE_CURRENT_SOURCE_DIR}
        FILES  ${QMLTEST_MODULE_FILES}
)
