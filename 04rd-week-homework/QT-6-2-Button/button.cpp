#include "button.h"
#include <QMouseEvent>
#include <QDebug>

Button::Button(QWidget *parent)
    : QPushButton(parent)
{
}

void Button::mouseReleaseEvent(QMouseEvent *event)
{
    move(event->scenePosition().toPoint());
    QPushButton::mouseReleaseEvent(event);
}

void Button::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit doubleClicked(isChecked());
        qDebug() << "A signal doubleClicked() has been emitted.";
    }

}