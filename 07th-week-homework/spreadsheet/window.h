// window.h
#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class Spreadsheet;
class QMenu;
class QToolBar;
class QAction;
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window() override;

private slots:
    void newFile();
    void openFile();
    bool saveFile();
    bool saveAsFile();

private:
    void createActions();
    void createMenus();
    void createToolBars();

    Spreadsheet *spreadsheet;

    // 菜单
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *toolsMenu;
    QMenu *optionsMenu;
    QMenu *helpMenu;

    // 工具栏
    QToolBar *fileToolBar;
    QToolBar *editToolBar;

    // 动作
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exitAction;
};