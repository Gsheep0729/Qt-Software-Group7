#ifndef LABEL_H
#define LABEL_H

#include <QLabel>   // QLabel 定义

class Label : public QLabel
{
    Q_OBJECT
public:
    explicit Label(QWidget *parent = nullptr);

protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
};

#endif // LABEL_H