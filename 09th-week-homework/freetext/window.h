#pragma once
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class AppController;
class TextEdit;

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void onSaveTriggered();

private:
    Ui::Window *ui;
    AppController *controller;
    TextEdit *textEdit;
};