# 项目: CodeEditorWidget

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

```

---

## 项目源文件
---

### File: widget.h
```cpp
#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    Ui::Widget *ui;
};

```

---

### File: EditorController.h
```cpp
/**
 * @file EditorController.h
 * @brief 代码编辑器全局控制器，负责装配 UI 与核心逻辑组件
 * @author GY
 * @date 2026-04-22
 *
 * Change Log:
 * - 2026-04-22: Initial creation. 引入 Controller 模式，接管 MainWindow 与 Editor 的组装。
 */

#pragma once

#include <QObject>
#include <memory>

// 前置声明，极小化头文件依赖
class tw_MainWindow;
class CodeEditorWidget;

class EditorController : public QObject
{
    Q_OBJECT

public:
    explicit EditorController(QObject *parent = nullptr);
    ~EditorController() override;

    /**
     * @brief 启动编辑器应用程序，执行装配并显示主窗口
     */
    void launch();

private:
    /**
     * @brief 初始化并组装所有核心组件
     */
    void assembleComponents();

    /**
     * @brief 建立控制器、视图与模型之间的信号槽映射
     */
    void setupConnections();

private:
    // 使用 std::unique_ptr 管理顶层窗口生命周期，防止内存泄漏
    std::unique_ptr<tw_MainWindow> _mainWindow;

    // 编辑器组件作为子对象挂载在 MainWindow 上，由 Qt 对象树管理生命周期
    CodeEditorWidget* _textEditor{nullptr};
};
```

---

### File: widget.cpp
```cpp
#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

```

---

### File: CodeEditorWidget.cpp
```cpp
/**
 * @file CodeEditorWidget.cpp
 * @brief CodeEditorWidget 实现文件
 * @author GY
 * @date 2026-04-22
 *
 * Change Log:
 * - 2026-04-22: Initial creation.
 */

#include "CodeEditorWidget.h"
#include <QFont>
#include <QDebug>

CodeEditorWidget::CodeEditorWidget(QWidget *parent)
    : QPlainTextEdit{parent}
{
    // 设置等宽字体，符合代码编辑器规范
    QFont monoFont("Consolas", 11);
    monoFont.setStyleHint(QFont::Monospace);
    this->setFont(monoFont);

    // 禁用软换行，优化水平代码阅读体验
    this->setLineWrapMode(QPlainTextEdit::NoWrap);
}

void CodeEditorWidget::saveDocument()
{
    // TODO: 实现纯净的保存逻辑
    qDebug() << "Executing save document logic...";
}

void CodeEditorWidget::loadDocument(const QString& filePath)
{
    // TODO: 实现防阻塞的文件读取逻辑
    qDebug() << "Loading file:" << filePath;
}
```

---

### File: CodeEditorWidget.h
```cpp
/**
 * @file CodeEditorWidget.h
 * @brief 核心纯文本代码编辑控件
 * @author GY
 * @date 2026-04-22
 *
 * Change Log:
 * - 2026-04-22: Initial creation. 继承 QPlainTextEdit 提供代码编辑支持。
 */

#pragma once

#include <QPlainTextEdit>

class CodeEditorWidget : public QPlainTextEdit
{
    Q_OBJECT

public:
    explicit CodeEditorWidget(QWidget *parent = nullptr);
    ~CodeEditorWidget() override = default;

public slots:
    /**
     * @brief 保存文档的核心逻辑
     */
    void saveDocument();

    /**
     * @brief 加载文档的核心逻辑
     */
    void loadDocument(const QString& filePath);
};
```

---

### File: main.cpp
```cpp
/**
 * @file main.cpp
 * @brief 应用程序主入口
 * @author GY
 * @date 2026-04-22
 *
 * Change Log:
 * - 2026-04-22: Initial creation. 将启动流程委托给 EditorController。
 */

#include <QApplication>
#include "EditorController.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 实例化主控制器并启动应用
    EditorController controller;
    controller.launch();

    return app.exec();
}
```

---

### File: CodeEditorWidget.ui
```xml
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>tw_MainWindow</class>
 <widget class="QMainWindow" name="tw_MainWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>1024</width>
    <height>768</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>现代 C++ 架构编辑器 (Qt 6.x)</string>
  </property>

  <widget class="QWidget" name="centralwidget">
   <layout class="QVBoxLayout" name="verticalLayout">
    <property name="spacing">
     <number>0</number>
    </property>
    <property name="leftMargin">
     <number>0</number>
    </property>
    <property name="topMargin">
     <number>0</number>
    </property>
    <property name="rightMargin">
     <number>0</number>
    </property>
    <property name="bottomMargin">
     <number>0</number>
    </property>
    <item>
     <widget class="QFrame" name="placeholderFrame">
      <property name="frameShape">
       <enum>QFrame::NoFrame</enum>
      </property>
     </widget>
    </item>
   </layout>
  </widget>

  <widget class="QMenuBar" name="menubar">
   <property name="geometry">
    <rect>
     <x>0</x>
     <y>0</y>
     <width>1024</width>
     <height>22</height>
    </rect>
   </property>
   <widget class="QMenu" name="menu_File">
    <property name="title">
     <string>文件(&amp;F)</string>
    </property>
    <addaction name="action_Open"/>
    <addaction name="action_Save"/>
    <addaction name="separator"/>
    <addaction name="action_Exit"/>
   </widget>
   <addaction name="menu_File"/>
  </widget>

  <widget class="QStatusBar" name="statusbar"/>

  <action name="action_Open">
   <property name="text">
    <string>打开(&amp;O)...</string>
   </property>
   <property name="shortcut">
    <string>Ctrl+O</string>
   </property>
  </action>
  <action name="action_Save">
   <property name="text">
    <string>保存(&amp;S)</string>
   </property>
   <property name="shortcut">
    <string>Ctrl+S</string>
   </property>
  </action>
  <action name="action_Exit">
   <property name="text">
    <string>退出(&amp;X)</string>
   </property>
  </action>
 </widget>
 <resources/>
 <connections/>
</ui>

```

---

### File: EditorController.cpp
```cpp
/**
 * @file EditorController.cpp
 * @brief EditorController 实现文件
 * @author GY
 * @date 2026-04-22
 *
 * Change Log:
 * - 2026-04-22: Initial creation.
 */

#include "EditorController.h"
#include "MainWindow.h"
#include "CodeEditorWidget.h"
#include <QDebug>

EditorController::EditorController(QObject *parent)
    : QObject{parent}
{
}

EditorController::~EditorController() = default; // std::unique_ptr 自动销毁 _mainWindow

void EditorController::launch()
{
    assembleComponents();
    setupConnections();

    if (_mainWindow) {
        _mainWindow->show();
    }
}

void EditorController::assembleComponents()
{
    // 1. 初始化顶层窗口
    _mainWindow = std::make_unique<tw_MainWindow>();

    // 2. 初始化核心编辑器组件，明确指定父对象托管给 MainWindow 的对象树
    _textEditor = new CodeEditorWidget(_mainWindow.get());

    // 3. 依赖注入：将编辑器组件装配到主窗口的中心区域
    _mainWindow->setCentralWidget(_textEditor);

    // 架构说明：此时 MainWindow 对 CodeEditorWidget 是“无感知”的，
    // 它只知道自己中心多了一个 QWidget。彻底实现了解耦。
}

void EditorController::setupConnections()
{
    // 在此处统筹处理 MainWindow 抛出的 UI 操作信号与 Editor 的逻辑槽函数
    // 强制使用 PMF (Pointer to Member Function) 编译期检查

    /* 示例：
    connect(_mainWindow.get(), &tw_MainWindow::actionSaveTriggered,
            _textEditor, &CodeEditorWidget::saveDocument);
    */
}
```

---

### File: MainWindow.h
```cpp
/**
 * @file MainWindow.h
 * @brief 代码编辑器主窗口顶层容器
 * @author GY
 * @date 2026-04-22
 *
 * Change Log:
 * - 2026-04-22: Initial creation. 剥离核心文本编辑逻辑。
 */

#pragma once

#include <QMainWindow>

// 禁止直接包含 ui 头文件，必须前置声明
QT_BEGIN_NAMESPACE
namespace Ui { class tw_MainWindow; }
QT_END_NAMESPACE

class tw_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit tw_MainWindow(QWidget *parent = nullptr);
    ~tw_MainWindow() override;

signals:
    // 暴露用户操作信号，供 Controller 捕获
    void actionOpenTriggered();
    void actionSaveTriggered();

private:
    // 强制 UI 指针前缀为 _ui，明确视觉边界
    Ui::tw_MainWindow *_ui;
};
```

---

### File: MainWindow.cpp
```cpp
/**
 * @file MainWindow.cpp
 * @brief MainWindow 实现文件
 * @author GY
 * @date 2026-04-22
 *
 * Change Log:
 * - 2026-04-22: Initial creation.
 */

#include "MainWindow.h"
#include "ui_CodeEditorWidget.h"

tw_MainWindow::tw_MainWindow(QWidget *parent)
    : QMainWindow{parent}
    , _ui{new Ui::tw_MainWindow} // 统一花括号初始化
{
    _ui->setupUi(this);

    // 设置窗口基础属性
    this->setWindowTitle(tr("现代 C++ 架构代码编辑器"));
    this->resize(1024, 768);

    // 内部信号中继：将 UI action 动作转发为业务信号
    // connect(_ui->action_Save, &QAction::triggered, this, &tw_MainWindow::actionSaveTriggered);
}

tw_MainWindow::~tw_MainWindow()
{
    // 架构红线：必须显式释放 UI 资源
    delete _ui;
}
```

---

