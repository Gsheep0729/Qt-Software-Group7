// Module
// File: window.cpp   Version: 0.1.0   License: AGPLv3
// Created: Chunlin Feng  1356962534@qq.com   2026-04-19 18:06:59
// Description:
//
// window.cpp
#include "window.h"
#include "spreadsheet.h"

#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>

Window::Window(QWidget *parent)
    : QMainWindow(parent)
{
    spreadsheet = new Spreadsheet(this);
    setCentralWidget(spreadsheet);

    createActions();
    createMenus();
    createToolBars();

    setWindowTitle(tr("Spreadsheet"));
    resize(800, 600);
    statusBar()->showMessage(tr("Ready"));
}

Window::~Window() = default;

void Window::createActions()
{
    // New
    newAction = new QAction(tr("&New"), this);
    newAction->setShortcut(QKeySequence::New);
    connect(newAction, &QAction::triggered, this, &Window::newFile);

    // Open
    openAction = new QAction(tr("&Open..."), this);
    openAction->setShortcut(QKeySequence::Open);
    connect(openAction, &QAction::triggered, this, &Window::openFile);

    // Save
    saveAction = new QAction(tr("&Save"), this);
    saveAction->setShortcut(QKeySequence::Save);
    connect(saveAction, qOverload<bool>(&QAction::triggered), this, &Window::saveFile);

    // Save As
    saveAsAction = new QAction(tr("Save &As..."), this);
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    connect(saveAsAction, qOverload<bool>(&QAction::triggered), this, &Window::saveAsFile);

    // Exit
    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    connect(exitAction, &QAction::triggered, this, &QWidget::close);
}

void Window::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    toolsMenu = menuBar()->addMenu(tr("&Tools"));
    optionsMenu = menuBar()->addMenu(tr("&Options"));
    helpMenu = menuBar()->addMenu(tr("&Help"));
}

void Window::createToolBars()
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    editToolBar = addToolBar(tr("&Edit"));
}

void Window::newFile()
{
    // 简单实现：清空表格，重置文件名
    spreadsheet->clear();
    setWindowTitle(tr("untitled.sp[*] - Spreadsheet"));
}

void Window::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Spreadsheet"), "",
                                                    tr("Spreadsheet files (*.sp)"));
    if (!fileName.isEmpty()) {
        if (spreadsheet->readFile(fileName)) {
            statusBar()->showMessage(tr("File loaded"), 2000);
            setWindowTitle(tr("%1[*] - Spreadsheet").arg(QFileInfo(fileName).fileName()));
        }
    }
}

bool Window::saveFile()
{
    // 暂未实现当前文件名的记录，后续完善
    return saveAsFile();
}

bool Window::saveAsFile()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Spreadsheet"), "",
                                                    tr("Spreadsheet files (*.sp)"));
    if (fileName.isEmpty())
        return false;
    if (spreadsheet->writeFile(fileName)) {
        statusBar()->showMessage(tr("File saved"), 2000);
        setWindowTitle(tr("%1[*] - Spreadsheet").arg(QFileInfo(fileName).fileName()));
        return true;
    }
    return false;
}