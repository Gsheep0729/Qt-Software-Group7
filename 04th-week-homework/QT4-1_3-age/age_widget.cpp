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
    spinBox->setValue(20);

    // 3. 信号槽双向连接，实现数据同步
    connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

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