#include "window.h"
#include "./ui_window.h"
#include "appcontroller.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    m_controller = new AppController;
}

Window::~Window()
{
    delete ui;
}

void Window::onSaveClicked() {}

