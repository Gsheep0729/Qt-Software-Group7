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
