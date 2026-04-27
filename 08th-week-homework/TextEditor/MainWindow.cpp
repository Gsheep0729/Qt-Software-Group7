/**
* @file    MainWindow.cpp
* @date    2026-04-27
* @author  GY
* @brief   MainWindow 实现文件
*
* 实现文本编辑器的主窗口。
* 初始化窗口基础属性并代理界面用户操作。
*
* Change Log:
* [v1.0] GY   2026-04-27
* * Initial creation
* [v2.0] GY   2026-04-27
* * 完成信号连接，使用 AppController 完成初始化
*/

#include "MainWindow.h"
#include "ui_TextEditor.h"
#include "AppController.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
    , _ui{new Ui::tw_MainWindow}
{
    _ui->setupUi(this);
    this->setWindowTitle(tr("现代 C++ 架构文本编辑器"));
    this->resize(1024, 768);

    // 把菜单里的“保存”动作连到我们自己写的槽函数上
    connect(_ui->action_Save, &QAction::triggered, this, &MainWindow::on_action_Save_triggered);
    
    // “打开”动作就直接写个 Lambda，反正就一句话，直接让控制器去处理
    connect(_ui->action_Open, &QAction::triggered, this, [this](){
        if (_appCtrl) {
            _appCtrl->open();
        }
    });
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::setAppCtrl(AppController* ctrl)
{
    _appCtrl = ctrl;
}

QString MainWindow::getSaveFilepath()
{
    return QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));
}

bool MainWindow::askExitEditing()
{
    // 问问要不要存盘
    int res = askSaveChanges();
    if (res == 1) { // 选了保存
        if (_appCtrl) _appCtrl->save();
        return true;
    } else if (res == 0) { // 选了不保存，直接丢掉
        return true;
    }
    // 点了取消，就别退出了
    return false;
}

int MainWindow::askSaveChanges()
{
    QMessageBox::StandardButton res = QMessageBox::question(this, tr("Save Changes"),
        tr("The document has been modified. Do you want to save your changes?"),
        QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        
    if (res == QMessageBox::Save) return 1;
    if (res == QMessageBox::Discard) return 0;
    return -1;
}

QString MainWindow::askOpenFilepath()
{
    return QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;All Files (*)"));
}

void MainWindow::on_action_Save_triggered()
{
    if (_appCtrl) {
        _appCtrl->save();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // 窗口关之前得拦一下，看看文件是不是还没存
    if (_appCtrl) {
        if (!askExitEditing()) {
            event->ignore(); // 不给关
            return;
        }
    }
    event->accept(); // 可以关了
}
