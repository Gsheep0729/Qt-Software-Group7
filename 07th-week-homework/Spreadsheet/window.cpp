/**
* @file    window.cpp
* @date    2026-04-15
* @author  GY
* @brief   修正后的主窗口实现，集成手动构建的组件
*
* 使用现代 C++23 语法，完全剥离对 .ui 文件的依赖。
* 修正了 updateStatusBar 的重定义冲突，并使用 Lambda 桥接信号参数。
*
* Change Log:
* [v1.1] GY   2026-04-15
* * Removed _ui pointer (Manual UI context)
* * Fixed redefinition of updateStatusBar
* * Integrated custom Spreadsheet widget
*/
#include "window.h"
#include "spreadsheet.h"
#include "finddialog.h"
#include <QtWidgets>

Window::Window(QWidget *parent)
    : QMainWindow{parent}
    , _spreadsheet{new Spreadsheet{this}} // 创建表格组件并挂载到窗口
{
    // 把表格设为窗口中心部件
    setCentralWidget(_spreadsheet);

    // 依次创建各界面元素
    createActions();
    createMenus();
    createToolBars();
    createStatusBar();

    // 单元格变动时，状态栏信息跟着更新
    connect(_spreadsheet, &QTableWidget::currentCellChanged, this, [this](){
        updateStatusBar();
    });

    setWindowTitle(tr("Manual Spreadsheet Architect V6.0"));
    resize(840, 600);
}

Window::~Window() = default; // Qt 会自动回收子控件，这里不需要手动 delete

void Window::updateStatusBar()
{
    // 同步刷新状态栏的文本
    _locationLabel->setText(_spreadsheet->currentLocation());
    _formulaLabel->setText(_spreadsheet->currentFormula());
}

void Window::createActions()
{
    // --- 文件菜单项 ---
    _newAction = new QAction{tr("&New"), this};
    _newAction->setShortcut(QKeySequence::New); // 设置 Ctrl+N 快捷键
    connect(_newAction, &QAction::triggered, _spreadsheet, &Spreadsheet::clear);

    _openAction = new QAction{tr("&Open..."), this};
    _openAction->setShortcut(QKeySequence::Open);
    connect(_openAction, &QAction::triggered, this, [this]() {
        // 弹出文件选择框
        QString fileName = QFileDialog::getOpenFileName(
            this, tr("Open Spreadsheet"), ".", tr("Spreadsheet files (*.sp)"));
        if (!fileName.isEmpty()) {
            _spreadsheet->readFile(fileName);
        }
    });

    _saveAction = new QAction{tr("&Save"), this};
    _saveAction->setShortcut(QKeySequence::Save);
    connect(_saveAction, &QAction::triggered, this, [this]() {
        QString fileName = QFileDialog::getSaveFileName(
            this, tr("Save Spreadsheet"), ".", tr("Spreadsheet files (*.sp)"));
        if (!fileName.isEmpty()) {
            _spreadsheet->writeFile(fileName);
        }
    });

    _exitAction = new QAction{tr("E&xit"), this};
    _exitAction->setShortcut(QKeySequence::Quit);
    connect(_exitAction, &QAction::triggered, this, &QWidget::close);

    // --- 编辑菜单项 ---
    _cutAction = new QAction{tr("Cu&t"), this};
    _cutAction->setShortcut(QKeySequence::Cut);
    connect(_cutAction, &QAction::triggered, _spreadsheet, &Spreadsheet::cut);

    _copyAction = new QAction{tr("&Copy"), this};
    _copyAction->setShortcut(QKeySequence::Copy);
    connect(_copyAction, &QAction::triggered, _spreadsheet, &Spreadsheet::copy);

    _pasteAction = new QAction{tr("&Paste"), this};
    _pasteAction->setShortcut(QKeySequence::Paste);
    connect(_pasteAction, &QAction::triggered, _spreadsheet, &Spreadsheet::paste);

    _deleteAction = new QAction{tr("&Delete"), this};
    _deleteAction->setShortcut(QKeySequence::Delete);
    connect(_deleteAction, &QAction::triggered, _spreadsheet, &Spreadsheet::del);

    // --- 其他功能 ---
    _findAction = new QAction{tr("&Find..."), this};
    _findAction->setShortcut(QKeySequence::Find);
    connect(_findAction, &QAction::triggered, this, &Window::find);

    _aboutAction = new QAction{tr("&About"), this};
    connect(_aboutAction, &QAction::triggered, this, [this]() {
        QMessageBox::about(this, tr("About Spreadsheet"),
                           tr("<h2>Spreadsheet 1.0</h2><p>Manual UI Initialization Example.</p>"));
    });
}

void Window::createMenus()
{
    // 创建 File 菜单并添加动作
    _fileMenu = menuBar()->addMenu(tr("&File"));
    _fileMenu->addAction(_newAction);
    _fileMenu->addAction(_openAction);
    _fileMenu->addAction(_saveAction);
    _fileMenu->addSeparator(); // 加一条分割线
    _fileMenu->addAction(_exitAction);

    // 创建 Edit 菜单
    _editMenu = menuBar()->addMenu(tr("&Edit"));
    _editMenu->addAction(_cutAction);
    _editMenu->addAction(_copyAction);
    _editMenu->addAction(_pasteAction);
    _editMenu->addAction(_deleteAction);
    _editMenu->addSeparator();
    _editMenu->addAction(_findAction);

    menuBar()->addSeparator();

    // 创建 Help 菜单
    _helpMenu = menuBar()->addMenu(tr("&Help"));
    _helpMenu->addAction(_aboutAction);
}

void Window::createToolBars()
{
    // 创建文件工具栏
    _fileToolBar = addToolBar(tr("&File"));
    _fileToolBar->addAction(_newAction);
    _fileToolBar->addAction(_openAction);
    _fileToolBar->addAction(_saveAction);

    // 创建编辑工具栏
    _editToolBar = addToolBar(tr("&Edit"));
    _editToolBar->addAction(_cutAction);
    _editToolBar->addAction(_copyAction);
    _editToolBar->addAction(_pasteAction);
    _editToolBar->addAction(_findAction);
}

void Window::createStatusBar()
{
    // 状态栏左侧显示单元格坐标
    _locationLabel = new QLabel{this};
    _locationLabel->setAlignment(Qt::AlignHCenter);
    _locationLabel->setMinimumSize(_locationLabel->sizeHint());

    // 状态栏右侧显示内容
    _formulaLabel = new QLabel{this};
    _formulaLabel->setIndent(3); // 加点左边距

    statusBar()->addWidget(_locationLabel);
    statusBar()->addWidget(_formulaLabel, 1); // 1 表示让内容标签拉伸占据空间

    updateStatusBar();
}

void Window::find() {
    // 第一次点查找时才创建对话框 (延迟加载)
    if (!_findDialog) {
        _findDialog = new FindDialog{this};
        // 连接对话框信号到表格的查找槽
        connect(_findDialog, &FindDialog::findNext, _spreadsheet, &Spreadsheet::findNext);
        connect(_findDialog, &FindDialog::findPrevious, _spreadsheet, &Spreadsheet::findPrevious);
    }

    _findDialog->show();      // 非模态显示
    _findDialog->raise();     // 置顶
    _findDialog->activateWindow(); // 激活窗口
}