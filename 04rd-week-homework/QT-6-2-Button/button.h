#ifndef BUTTON_H
#define BUTTON_H
#include <QPushButton>

class button : public QPushButton
{
        Q_OBJECT;
public:
        explicit Button(QWidget *parent = nullptr);

signals:
        void doubleClicked(bool checked = false);
protected:
        virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseDoubleClickedEvent(QMouseEvent *event) override;
};

#endif