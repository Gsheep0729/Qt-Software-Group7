#include "window.h"
#include <QDebug>
#include <QMouseEvent>

Window::Window(QWidget *parent) : QWidget(parent)
{
    label = new Label(this);
    label->setText("右键：事件停止\n左键：传给父窗口");
    label->setGeometry(20, 20, 200, 100);
}

void Window::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug() << "父窗口 Window 收到双击事件";
}