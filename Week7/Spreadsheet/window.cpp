/*
 * 文件名:   window.cpp
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-04-17
 * 描述:     /run/media/root/Windows/study/code/Qt-Software-Group7/Week7/Spreadsheet/window.cpp
 * 版权声明: https://github.com/duruoxian
 */
#include "window.h"
#include "spreadsheet.h"
#include "finddialog.h"
#include <QtWidgets>

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , m_table(new Spreadsheet(this))
{
    // 将表格设为窗口中心部件
    setCentralWidget(m_table);

    // 创建各界面元素
    createActions();
    createMenus();
    createToolBars();
    createStatusBar();

    // 单元格变动时，状态栏信息跟着更新
    connect(m_table, &QTableWidget::currentCellChanged, this, [this](){
        updateStatusBar();
    });

    setWindowTitle(tr("Manual Spreadsheet Architect V6.0"));
    resize(840, 600);
}

Window::~Window() = default;

void Window::updateStatusBar()
{
    // 同步刷新状态栏的文本
    m_cellLabel->setText(m_table->currentLocation());
    m_contentLabel->setText(m_table->currentFormula());
}

void Window::createActions()
{
    // 文件菜单项
    m_actionNew = new QAction(tr("&New"), this);
    m_actionNew->setShortcut(QKeySequence::New);
    connect(m_actionNew, &QAction::triggered, m_table, &Spreadsheet::clear);

    m_actionOpen = new QAction(tr("&Open..."), this);
    m_actionOpen->setShortcut(QKeySequence::Open);
    connect(m_actionOpen, &QAction::triggered, this, [this]() {
        // 弹出文件选择框
        QString path = QFileDialog::getOpenFileName(
            this, tr("Open Spreadsheet"), ".", tr("Spreadsheet files (*.sp)"));
        if (!path.isEmpty()) {
            m_table->readFile(path);
        }
    });

    m_actionSave = new QAction(tr("&Save"), this);
    m_actionSave->setShortcut(QKeySequence::Save);
    connect(m_actionSave, &QAction::triggered, this, [this]() {
        QString path = QFileDialog::getSaveFileName(
            this, tr("Save Spreadsheet"), ".", tr("Spreadsheet files (*.sp)"));
        if (!path.isEmpty()) {
            m_table->writeFile(path);
        }
    });

    m_actionExit = new QAction(tr("E&xit"), this);
    m_actionExit->setShortcut(QKeySequence::Quit);
    connect(m_actionExit, &QAction::triggered, this, &QWidget::close);

    // 编辑菜单项
    m_actionCut = new QAction(tr("Cu&t"), this);
    m_actionCut->setShortcut(QKeySequence::Cut);
    connect(m_actionCut, &QAction::triggered, m_table, &Spreadsheet::cut);

    m_actionCopy = new QAction(tr("&Copy"), this);
    m_actionCopy->setShortcut(QKeySequence::Copy);
    connect(m_actionCopy, &QAction::triggered, m_table, &Spreadsheet::copy);

    m_actionPaste = new QAction(tr("&Paste"), this);
    m_actionPaste->setShortcut(QKeySequence::Paste);
    connect(m_actionPaste, &QAction::triggered, m_table, &Spreadsheet::paste);

    m_actionDelete = new QAction(tr("&Delete"), this);
    m_actionDelete->setShortcut(QKeySequence::Delete);
    connect(m_actionDelete, &QAction::triggered, m_table, &Spreadsheet::del);

    // 其他功能
    m_actionFind = new QAction(tr("&Find..."), this);
    m_actionFind->setShortcut(QKeySequence::Find);
    connect(m_actionFind, &QAction::triggered, this, &Window::find);

    m_actionAbout = new QAction(tr("&About"), this);
    connect(m_actionAbout, &QAction::triggered, this, [this]() {
        QMessageBox::about(this, tr("About Spreadsheet"),
                           tr("<h2>Spreadsheet 1.0</h2><p>Manual UI Initialization Example.</p>"));
    });
}

void Window::createMenus()
{
    // 创建File菜单并添加动作
    m_fileMenu = menuBar()->addMenu(tr("&File"));
    m_fileMenu->addAction(m_actionNew);
    m_fileMenu->addAction(m_actionOpen);
    m_fileMenu->addAction(m_actionSave);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_actionExit);

    // 创建Edit菜单
    m_editMenu = menuBar()->addMenu(tr("&Edit"));
    m_editMenu->addAction(m_actionCut);
    m_editMenu->addAction(m_actionCopy);
    m_editMenu->addAction(m_actionPaste);
    m_editMenu->addAction(m_actionDelete);
    m_editMenu->addSeparator();
    m_editMenu->addAction(m_actionFind);

    menuBar()->addSeparator();

    // 创建Help菜单
    m_helpMenu = menuBar()->addMenu(tr("&Help"));
    m_helpMenu->addAction(m_actionAbout);
}

void Window::createToolBars()
{
    // 创建文件工具栏
    m_fileToolbar = addToolBar(tr("&File"));
    m_fileToolbar->addAction(m_actionNew);
    m_fileToolbar->addAction(m_actionOpen);
    m_fileToolbar->addAction(m_actionSave);

    // 创建编辑工具栏
    m_editToolbar = addToolBar(tr("&Edit"));
    m_editToolbar->addAction(m_actionCut);
    m_editToolbar->addAction(m_actionCopy);
    m_editToolbar->addAction(m_actionPaste);
    m_editToolbar->addAction(m_actionFind);
}

void Window::createStatusBar()
{
    // 状态栏左侧显示单元格坐标
    m_cellLabel = new QLabel(this);
    m_cellLabel->setAlignment(Qt::AlignHCenter);
    m_cellLabel->setMinimumSize(m_cellLabel->sizeHint());

    // 状态栏右侧显示内容
    m_contentLabel = new QLabel(this);
    m_contentLabel->setIndent(3);

    statusBar()->addWidget(m_cellLabel);
    statusBar()->addWidget(m_contentLabel, 1);

    updateStatusBar();
}

void Window::find()
{
    // 第一次点查找时才创建对话框(延迟加载)
    if (!m_findDialog) {
        m_findDialog = new FindDialog(this);
        // 连接对话框信号到表格的查找槽
        connect(m_findDialog, &FindDialog::findNext, m_table, &Spreadsheet::findNext);
        connect(m_findDialog, &FindDialog::findPrevious, m_table, &Spreadsheet::findPrevious);
    }

    m_findDialog->show();
    m_findDialog->raise();
    m_findDialog->activateWindow();
}