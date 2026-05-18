#pragma once

#include <QMainWindow>

class AppController;

QT_BEGIN_NAMESPACE
namespace Ui {
    class Window;
}
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(AppController *appCtrl,QWidget *parent = nullptr);
    ~Window() override;

    QString getSaveFilepath();

protected:
    virtual void closeEvent(QCloseEvent *event) override;

private slots:
    void on_action_Save_triggered();

private:
    Ui::Window *m_ui;
    AppController *_appCtrl;
};
