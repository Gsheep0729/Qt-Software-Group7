# 项目: QT02_Exit-program

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

project(QT02_Exit-program VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

_qt_add_executable(QT02_Exit-program)

target_compile_features(QT02_Exit-program PRIVATE cxx_std_23)

target_sources(QT02_Exit-program
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
        # birds.cppm           # 模块文件
    PRIVATE
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

# source_group("birds", FILES birds.cppm)

target_link_libraries(QT02_Exit-program 
    PRIVATE 
        Qt6::Widgets
)

set_target_properties(QT02_Exit-program PROPERTIES
    AUTORCC TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
set(CMAKE_INSTALL_PREFIX "/opt/QT02_Exit-program" CACHE PATH "Install path prefix" FORCE)
install(TARGETS QT02_Exit-program
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET QT02_Exit-program
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
/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/04th-week-homework/QT02_Exit-program/main.cpp
* @date    2026-03-29
* @author  GY
* @brief   应用程序主入口文件
*
* 本文件是程序的入口点，负责创建QApplication应用程序对象和MainWindow主窗口对象，
* 并启动应用程序的事件循环。这是所有Qt应用程序的标准入口文件。
*
* Change Log:
* [v1.0] GY   2026-03-29
* * Initial creation
*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // 规范：顶层窗口作为栈对象分配
    MainWindow w;
    w.show();

    return a.exec();
}

```

---

### File: mainwindow.cpp
```cpp
/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/04th-week-homework/QT02_Exit-program/mainwindow.cpp
* @date    2026-03-29
* @author  GY
* @brief   主窗口类的实现文件
*
* 本文件实现了MainWindow类的功能，包括主窗口的初始化和析构。
* MainWindow类继承自QMainWindow，使用了Pimpl(指针实现)模式来管理UI界面。
*
* Change Log:
* [v1.0] GY   2026-03-29
* * Initial creation
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCloseEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow{parent},
    _ui{new Ui::MainWindow} // 堆分配
{
    _ui->setupUi(this);

    // 1. 设置菜单栏动作：假设已经在 Designer 中创建了名为 actionExit 的 Action
    // 如果是纯代码创建，需在此处 new QAction 并传入 this

    // 2. 信号与槽：现代 Qt 6 强类型连接（如果 Designer 未自动关联）
    connect(_ui->actionExit, &QAction::triggered, this, &MainWindow::on_actionExit_triggered);
}

MainWindow::~MainWindow() {
    delete _ui; // 必须手动释放，Ui 类不在对象树中
}

/**
 * @brief 点击菜单“退出”或工具栏退出按钮时触发
 */
void MainWindow::on_actionExit_triggered() {
    // 调用 close() 会触发 closeEvent
    this->close();
}

/**
 * @brief 核心拦截逻辑：无论是点击 [X] 还是点击菜单“退出”，最终都会进入此函数
 */
void MainWindow::closeEvent(QCloseEvent* event) {
    if (confirmExit()) {
        event->accept(); // 允许关闭，程序进入析构流程
    } else {
        event->ignore(); // 忽略事件，程序继续运行
    }
}

/**
 * @brief 退出确认对话框
 */
bool MainWindow::confirmExit() {
    const QMessageBox::StandardButton btn = QMessageBox::question(
        this,
        tr("退出程序"),
        tr("您确定要退出吗？"),
        QMessageBox::Yes | QMessageBox::No,
        QMessageBox::No
        );

    return (btn == QMessageBox::Yes);
}
```

---

### File: mainwindow.h
```cpp
/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/04th-week-homework/QT02_Exit-program/mainwindow.h
* @date    2026-03-29
* @author  GY
* @brief   主窗口类的头文件声明
*
* 本文件定义了MainWindow类，这是应用程序的主窗口类，继承自QMainWindow。
* 该类使用了Pimpl(指针实现)模式来管理UI界面，通过Ui::MainWindow指针
* 来访问和操作UI界面中的控件，这种方式可以降低编译依赖，提高编译效率。
*
* Change Log:
* [v1.0] GY   2026-03-29
* * Initial creation
*/
#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

    // 现代 C++23：禁用拷贝与赋值
    MainWindow(const MainWindow&) = delete;
    MainWindow& operator=(const MainWindow&) = delete;

protected:
    // 重写关闭事件，用于拦截用户点击窗口 [X] 按钮的行为
    void closeEvent(QCloseEvent* event) override;

private slots:
    // 自动关联槽函数：严格遵循 on_<objectName>_<signalName> 命名
    void on_actionExit_triggered();

private:
    // 退出确认逻辑封装
    bool confirmExit();

private:
    // UI 指针管理，生命周期需手动隔离
    Ui::MainWindow* _ui;
};

```

---

