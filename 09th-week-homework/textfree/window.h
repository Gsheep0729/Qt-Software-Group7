#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class tw_window;
}
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window() override;
    QString getSaveFilePath();
protected:
    virtual void closeEvent(QCloseEvent *event) override;

private slots:
    void on_action_Save_triggered();
private:
    Ui::tw_window *m_ui;
};
