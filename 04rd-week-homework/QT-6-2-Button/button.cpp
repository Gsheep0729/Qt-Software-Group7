#include "button.h"
#include <QDebug>
#include <QMoveEvent>

Button::Button(QWidget *parent);
    QPushButton{parent}
{}

    void Button::mouseReleaseEvent(QMouseEvent *event){
        move(event -> scenePosition().toPoint());
    }

    void Button::mouseDoubleClickedEvent(QMouseEvent *event)
    {
        if(event->button() == Qt::LeftButton){
            emit doubleClicked(isChecked());
            qDebug << "A signal doubleClicked() has been emitted.";
        }
    }