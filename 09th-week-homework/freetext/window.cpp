#include "window.h"
#include "ui_window.h"
#include "appcontroller.h"
#include <QFileDialog>
#include <QCloseEvent>

// ✅ 修复：两个参数都写上
Window::Window(AppController *appCtrl, QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::Window)
    , _appCtrl(appCtrl) // ✅ 正确赋值
{
    m_ui->setupUi(this);
}

Window::~Window()
{
    delete m_ui;
}

QString Window::getSaveFilepath()
{
    return QFileDialog::getSaveFileName(this, "freetext Save", "", "Text files (*.txt)");
}

void Window::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void Window::on_action_Save_triggered()
{
    _appCtrl->save();
}
