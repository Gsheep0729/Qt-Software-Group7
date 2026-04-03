#include "label.h"      // ✅ 必须包含，否则编译器不知道 Label
#include <QMouseEvent>  // 鼠标事件结构体
#include <QDebug>       // 打印输出

Label::Label(QWidget *parent) : QLabel(parent)
{
    setAlignment(Qt::AlignCenter);
    setAutoFillBackground(true);
}

void Label::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        qDebug() << "Label 处理右键双击，事件停止";
    }
    else if (event->button() == Qt::LeftButton)
    {
        qDebug() << "Label 左键双击，事件传给父窗口";
        event->ignore();  // 事件向上传递
    }
}