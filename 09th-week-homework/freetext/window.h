#pragma once

#include <QMainWindow>

class AppController;

QT_BEGIN_NAMESPACE
namespace Ui {
    class Window;
}
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window() override;

private slots:
    void onSaveClicked();

private:
    Ui::Window *ui;
    AppController *m_controller;
};
