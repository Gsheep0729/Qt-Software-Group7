#pragma once

#include <QMainWindow>

class AppController;

namespace Ui {
    class tw_window;
}

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
    void on_action_Save_triggered();


private:
    Ui::tw_window *m_ui;

    AppController *_appCtrl;
};
