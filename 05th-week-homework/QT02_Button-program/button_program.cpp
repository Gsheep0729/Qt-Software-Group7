/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/05th-week-homework/QT02_Button-program/button_program.cpp
* @date    2026-04-05
* @author  GY
* @brief   Button_program类的实现文件
*
* 该文件实现了主窗口类的构造函数和析构函数。在构造函数中创建自定义按钮，
* 并使用信号槽机制处理按钮的双击事件。析构函数负责释放UI对象占用的内存。
*
* Change Log:
* [v1.0] GY   2026-04-05
* * Initial creation
*/
#include "button_program.h"
#include "./ui_button_program.h"
#include "button.h"
#include <QDebug>


Button_program::Button_program(QWidget *parent)
    : QMainWindow{parent}
    , _ui{new Ui::Button_program} // 使用统一初始化语法
{
    _ui->setupUi(this);

    // 创建自定义按钮，传入父窗口指针以确保内存安全
    Button *myBtn = new Button(_ui->centralwidget);
    myBtn->setGeometry(100, 100, 200, 50); // 设置按钮位置和大小

    // 使用现代信号槽语法，连接按钮的双击信号到lambda函数
    connect(myBtn, &Button::doubleClicked, this, [](bool checked) {
        qDebug() << "MainWindow caught doubleClicked signal. Checked state:" << checked;
    });
}


Button_program::~Button_program() {
    // 手动释放UI对象指针占用的内存
    delete _ui;
}