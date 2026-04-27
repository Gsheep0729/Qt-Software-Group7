cmake_minimum_required(VERSION 4.2.3)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)
function(_qt_add_executable target)
    qt_add_executable(${target})
endfunction()

project(CodeEditorWidget VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

_qt_add_executable(CodeEditorWidget)

target_compile_features(CodeEditorWidget PRIVATE cxx_std_23)

target_sources(CodeEditorWidget
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
        # birds.cppm           # 模块文件
    PRIVATE
        main.cpp
        EditorController.h
        EditorController.cpp
        CodeEditorWidget.h
        CodeEditorWidget.cpp
        MainWindow.h
        MainWindow.cpp
        DocumentStorage.h
        DocumentStorage.cpp
        CodeEditorWidget.ui
)

# source_group("birds", FILES birds.cppm)

target_link_libraries(CodeEditorWidget 
    PRIVATE 
        Qt6::Widgets
)

set_target_properties(CodeEditorWidget PROPERTIES
    AUTORCC TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
set(CMAKE_INSTALL_PREFIX "/opt/CodeEditorWidget" CACHE PATH "Install path prefix" FORCE)
install(TARGETS CodeEditorWidget
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET CodeEditorWidget
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
