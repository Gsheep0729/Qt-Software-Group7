//Created By Chunlin Feng 1356962534@qq.com
//closeevnt关闭事件的完成
#ifndef CLOSEEVENT_H
#define CLOSEEVENT_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class CloseEvent; }
QT_END_NAMESPACE

class CloseEvent : public QMainWindow
{
    Q_OBJECT

public:
    explicit CloseEvent(QWidget *parent = nullptr);
    ~CloseEvent() override;

protected:
    // 重写虚函数，保持小写开头
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::CloseEvent *ui;
    // 函数名统一：建议全小写，避免大小写坑
    bool userWantsToQuit();
};

#endif // CLOSEEVENT_H