#include "window.h"
#include "./ui_window.h"
#include "appcontroller.h"
#include "textedit.h"
#include "documentstorage.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);


    textEdit = new TextEdit(this);
    setCentralWidget(textEdit);

    controller = new AppController(this);
    DocumentStorage *storage = new DocumentStorage; // 没有 parent，由 controller 管理
    controller->setTextEdit(textEdit);
    controller->setStorage(storage);
    connect(ui->actionSave, &QAction::triggered,
            this, &Window::onSaveTriggered);
}

Window::~Window()
{
    delete ui;
}

void Window::onSaveTriggered()
{
    controller->saveDocument();
}