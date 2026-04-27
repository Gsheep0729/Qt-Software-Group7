#pragma once
#include <QMainWindow>

class AppController;

namespace Ui { class tw_window; }   // 必须与 UI 的类名一致

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(AppController *appCtrl, QWidget *parent = nullptr);
    ~Window() override;

    QString getSaveFilepath();

protected:
    virtual void closeEvent(QCloseEvent *event) override;

private slots:
    void on_action_Save_triggered();   // 必须匹配 UI 中 action_Save 的对象名

private:
    Ui::tw_window *m_ui;               // 对应 Ui::tw_window
    AppController *_appCtrl;
};