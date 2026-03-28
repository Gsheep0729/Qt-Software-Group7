cmake_minimum_required(VERSION 4.2.3)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)
function(_qt_add_executable target)
    qt_add_executable(${target})
endfunction()

project(dialog-call-demo VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()


_qt_add_executable(dialog-call-demo)

target_compile_features(dialog-call-demo PRIVATE cxx_std_23)

# # 1. 在 project 之后定义库的路径变量（方便维护）
# set(LIB_SRC_DIR "/root/Qt-Software-Group7/04th-week-homework/dialog-libary/QT4_2-3_dialog-library")
# set(LIB_BIN_DIR "${LIB_SRC_DIR}/build/C_C_2026_03_29-Debug") # 需要修改实际路径

# 1. 库的源码路径,这里需要修改为真实路径
set(LIB_SRC_DIR "/root/Qt-Software-Group7/04th-week-homework/dialog-libary/QT4_2-3_dialog-library")
# 现在的二进制路径直接指向我们刚才固定的 lib 文件夹
set(LIB_BIN_DIR "${LIB_SRC_DIR}/lib")

target_sources(dialog-call-demo
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
        # birds.cppm           # 模块文件
    PRIVATE
        main.cpp
)

# source_group("birds", FILES birds.cppm)

# 2. 添加头文件搜索路径，这样 main.cpp 才能找到 "widget.h"
target_include_directories(dialog-call-demo PRIVATE ${LIB_SRC_DIR})

# 3. 修改链接逻辑
target_link_libraries(dialog-call-demo
    PRIVATE
        Qt6::Widgets
        "${LIB_BIN_DIR}/libQT4_2-3_dialog-library.so" # 链接具体的库文件
)

# 5. 设置 RPATH，确保程序启动时能自动找到 .so 所在位置
set_target_properties(dialog-call-demo PROPERTIES
    BUILD_RPATH "${LIB_BIN_DIR}"
    AUTORCC TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
set(CMAKE_INSTALL_PREFIX "/opt/dialog-call-demo" CACHE PATH "Install path prefix" FORCE)
install(TARGETS dialog-call-demo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET dialog-call-demo
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
