//Created By Chunlin Feng 1356962534@qq.com
//closeevnt关闭事件的完成
#include "closeevent.h"
#include "ui_closeevent.h"

CloseEvent::CloseEvent(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CloseEvent)
{
    ui->setupUi(this);
}

CloseEvent::~CloseEvent()
{
    delete ui;
}
void CloseEvent::closeEvent(QCloseEvent *event)
{
    if (userWantsToQuit()) {
        event->accept(); // 同意关闭
    } else {
        event->ignore(); // 拒绝关闭
    }
}
//辅助函数完成closeevent的具体实现：增加弹窗显示
bool CloseEvent::userWantsToQuit()
{
    QMessageBox::StandardButton res = QMessageBox::question(
        this,
        tr("确认退出"),
        tr("确定要关闭程序吗？\n未保存的内容将会被丢弃"),
        QMessageBox::Yes | QMessageBox::No,
        QMessageBox::No
        );

    return res == QMessageBox::Yes;
}