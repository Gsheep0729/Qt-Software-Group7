# 项目: QT4-1_3-age

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

project(QT4-1_3-age VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

_qt_add_executable(QT4-1_3-age)

target_compile_features(QT4-1_3-age PRIVATE cxx_std_23)

target_sources(QT4-1_3-age
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
        # birds.cppm           # 模块文件
    PRIVATE
        main.cpp
        age_widget.cpp
        age_widget.h
)

# source_group("birds", FILES birds.cppm)

target_link_libraries(QT4-1_3-age 
    PRIVATE 
        Qt6::Widgets
)

set_target_properties(QT4-1_3-age PROPERTIES
    AUTORCC TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
set(CMAKE_INSTALL_PREFIX "/opt/QT4-1_3-age" CACHE PATH "Install path prefix" FORCE)
install(TARGETS QT4-1_3-age
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET QT4-1_3-age
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
#include "age_widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AgeWidget w;
    w.show();
    return QCoreApplication::exec();
}

```

---

### File: age_widget.h
```cpp
/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/04th-week-homework/QT4-1_3-age/age_widget.h
* @date    2026-03-29
* @author  GY
* @brief   Age 程序 (手工布局版本)
*
* <这里填写详细描述>
*
* Change Log:
* [v1.0] GY   2026-03-29
* * Initial creation
*/
#pragma once

#include <QWidget>

// 前向声明
class QSpinBox;
class QSlider;

class AgeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AgeWidget(QWidget *parent = nullptr);

protected:
    // 重写调整大小事件，在此处进行手工布局计算
    void resizeEvent(QResizeEvent *event) override;

private:
    // 在手工布局中，保留控件指针是必要的，以便在 resizeEvent 中随时访问它们
    QSpinBox *spinBox;
    QSlider *slider;
};
```

---

### File: age_widget.cpp
```cpp
/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/04th-week-homework/QT4-1_3-age/age_widget.cpp
* @date    2026-03-29
* @author  GY
* @brief   Age 程序实现 (手工布局版本)
*
* <这里填写详细描述>
*
* Change Log:
* [v1.0] GY   2026-03-29
* * Initial creation
*/
#include "age_widget.h"
#include <QSpinBox>
#include <QSlider>
#include <QResizeEvent>

AgeWidget::AgeWidget(QWidget *parent)
    : QWidget(parent)
{
    // 1. 实例化控件并显式指定父窗口为 this (因为没有布局管理器来自动接管它们)
    spinBox = new QSpinBox(this);
    slider = new QSlider(Qt::Horizontal, this);

    // 2. 设置年龄的合理范围和初始值
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);
    spinBox->setValue(35);

    // 3. 信号槽双向连接，实现数据同步
    connect(spinBox, &QSpinBox::valueChanged, slider, &QSlider::setValue);
    connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);

    // 设置窗口基础属性
    setWindowTitle(tr("Enter Your Age (Manual)"));
    // 设置一个合理的初始大小，触发第一次 resizeEvent
    resize(300, 80);
}

void AgeWidget::resizeEvent(QResizeEvent *event)
{
    // 每次窗口大小改变时，都会进入这个函数
    // 我们需要动态获取当前窗口的总宽度和高度
    int currentWidth = width();
    int currentHeight = height();

    // 设定布局参数
    int margin = 15;        // 距离窗口边缘的空白
    int spacing = 10;       // 两个控件之间的间距
    int widgetHeight = 30;  // 控件的固定高度

    // 计算单个控件的可用宽度：(总宽 - 左右边距 - 中间间距) / 2
    int componentWidth = (currentWidth - (2 * margin) - spacing) / 2;

    // 计算 Y 坐标，使其在窗口中垂直居中
    int centerY = (currentHeight - widgetHeight) / 2;

    // 4. 手工定位控件 (核心步骤)
    // setGeometry 参数顺序：x, y, 宽度, 高度

    // 放置左侧的微调框
    spinBox->setGeometry(margin, centerY, componentWidth, widgetHeight);

    // 放置右侧的滑块，其 X 坐标起步于：左边距 + 左侧控件宽度 + 控件间距
    slider->setGeometry(margin + componentWidth + spacing, centerY, componentWidth, widgetHeight);

    // 必须调用基类的 resizeEvent 以确保其他默认事件正常处理
    QWidget::resizeEvent(event);
}
```

---

