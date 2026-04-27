#include "window.h"

#include <QFileDialog>
#include <QCloseEvent>

#include "ui_window.h"
#include "appcontroller.h"

Window::Window(AppController *appCtrl, QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::tw_window)
    , _appCtrl(appCtrl)
{
    m_ui->setupUi(this);
}

Window::~Window()
{
    delete m_ui;
}

QString Window::getSaveFilepath()
{
    return QFileDialog::getSaveFileName(this, tr("freetext Save"), "/root", tr("Text files (*)"));
}

void Window::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void Window::on_action_Save_triggered()
{
    _appCtrl->save();
}
