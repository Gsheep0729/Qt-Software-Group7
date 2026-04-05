cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)
function(_qt_add_executable target)
    qt_add_executable(${target})
endfunction()

project(QT6-2-Qthread VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

_qt_add_executable(QT6-2-Qthread)

target_compile_features(QT6-2-Qthread PRIVATE cxx_std_23)

target_sources(QT6-2-Qthread
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
        # math.cppm           # 模块文件
    PRIVATE
        main.cpp
        widget.cpp
        widget.h
        widget.ui
)

# source_group("QT6-2-Qthread", FILES  # 模块文件的分组
#    math.cppm
#)  

target_link_libraries(QT6-2-Qthread 
    PRIVATE 
        Qt6::Widgets
)

set_target_properties(QT6-2-Qthread PROPERTIES
    AUTORCC TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
set(CMAKE_INSTALL_PREFIX "/opt/QT6-2-Qthread" CACHE PATH "Install path prefix" FORCE)
install(TARGETS QT6-2-Qthread
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET QT6-2-Qthread
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
