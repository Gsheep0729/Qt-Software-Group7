#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "button.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonDoubleClicked(bool checked);

private:
    Button *myButton;
};

#endif // MAINWINDOW_H