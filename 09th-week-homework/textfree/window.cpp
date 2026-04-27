#include "window.h"

#include<QFileDialog>
#include <QCloseEvent>

#include "ui_window.h"


Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::tw_window)
{
    m_ui->setupUi(this);
}

Window::~Window()
{
    delete m_ui;
}

QString Window::getSaveFilePath() {}

void Window::closeEvent(QCloseEvent *event)
{
    event->accept;
}

void Window::on_action_Save_triggered()
{

}