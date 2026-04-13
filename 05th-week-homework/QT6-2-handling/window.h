#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "label.h"   // ✅ 包含 Label 声明，否则编译器不知道 Label

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    Label *label;
};

#endif // WINDOW_H