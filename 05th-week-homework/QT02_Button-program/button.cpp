/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/05th-week-homework/QT02_Button-program/button.cpp
* @date    2026-04-05
* @author  GY
* @brief   Button类的实现文件
*
* 该文件实现了自定义按钮类的构造函数和事件处理函数。
* 主要功能包括：
* 1. 构造函数初始化按钮文本
* 2. 鼠标释放事件实现按钮拖拽功能
* 3. 鼠标双击事件发射自定义信号
*
* Change Log:
* [v1.0] GY   2026-04-05
* * Initial creation
*/
#include "button.h"
#include <QMouseEvent>
#include <QDebug>

// 设置按钮的显示文本为"Double Click Me"
Button::Button(QWidget *parent)
    : QPushButton{parent} // 使用花括号初始化列表
{
    this->setText("Double Click Me");
}

/**
 * 鼠标释放事件处理，实现按钮拖拽功能
 * event 鼠标事件对象
 * 
 * 当用户释放鼠标时，将按钮移动到鼠标当前位置。
 * 使用Qt 6的scenePosition()获取场景坐标并转换为整数坐标点。
 */
void Button::mouseReleaseEvent(QMouseEvent *event) {
    // 将按钮移动到鼠标释放时的位置
    move(event->scenePosition().toPoint());
}

/**
 * 鼠标双击事件处理，发射双击信号
 * event 鼠标事件对象
 * 
 * 当用户左键双击按钮时，发射doubleClicked信号，
 * 传递按钮的当前选中状态，并调用父类的双击事件处理。
 */
void Button::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        // 发射自定义双击信号，传递按钮的选中状态
        emit doubleClicked(this->isChecked());
        qDebug() << "A signal doubleClicked() has been emitted.";
    }
    // 调用父类的双击事件处理，保持默认行为
    QPushButton::mouseDoubleClickEvent(event);
}