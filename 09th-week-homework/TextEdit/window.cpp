#include "window.h"
#include "./ui_window.h"
#include "appcontroller.h"

#include <QFileDialog>
#include <QCloseEvent>

Window::Window(AppController *appCtrl, QWidget *parent)
    : QMainWindow(parent)
    ,m_ui(new Ui::tw_window)
    ,_appCtrl(appCtrl)
{
    m_ui->setupUi(this);
}

Window::~Window()
{
    delete m_ui;
}

QString Window::getSaveFilePath()
{
    return QFileDialog::getSaveFileName(this, tr("TextEdit Save"), "/root", tr("Text files (*)"));
}

void Window::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void Window::on_action_Save_triggered()
{
    _appCtrl->save();
}

