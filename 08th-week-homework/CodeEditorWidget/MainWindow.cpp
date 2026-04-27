/**
* @file    MainWindow.cpp
* @date    2026-04-22
* @author  GY
* @brief   MainWindow 实现文件
*
* 实现代码编辑器的主窗口。
* 初始化窗口基础属性并代理界面用户操作。
*
* Change Log:
* [v1.0] GY   2026-04-22
* * Initial creation
*/

#include "MainWindow.h"
#include "ui_CodeEditorWidget.h"
#include "EditorController.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
    , _ui{new Ui::tw_MainWindow}
{
    _ui->setupUi(this);
    this->setWindowTitle(tr("现代 C++ 架构代码编辑器"));
    this->resize(1024, 768);
    
    // UI 动作信号直接绑定到 UML 的响应函数
    connect(_ui->action_Save, &QAction::triggered, this, &MainWindow::on_action_Save_triggered);
    
    // 打开按钮信号，直接让 Controller 接管
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

void MainWindow::setAppCtrl(EditorController* ctrl)
{
    _appCtrl = ctrl;
}

QString MainWindow::getSaveFilepath()
{
    return QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));
}

bool MainWindow::askExitEditing()
{
    // 弹出询问框，根据用户反馈执行保存、丢弃或取消操作
    int res = askSaveChanges();
    if (res == 1) { // 用户选择保存
        if (_appCtrl) _appCtrl->save();
        return true;
    } else if (res == 0) { // 用户选择不保存，直接放弃变更
        return true;
    }
    // 用户取消操作，阻止后续流程（如关闭窗口）
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
    // 拦截窗口关闭事件，确保未保存的改动能被正确处理
    if (_appCtrl) {
        // 若退出检查未通过（用户点击取消），则忽略关闭事件
        if (!askExitEditing()) {
            event->ignore();
            return;
        }
    }
    // 接受事件，允许窗口正常销毁
    event->accept();
}