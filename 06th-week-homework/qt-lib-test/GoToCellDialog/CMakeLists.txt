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
  # GoToCellDialog_global.h
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
