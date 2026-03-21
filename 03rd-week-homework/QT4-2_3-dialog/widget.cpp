/**
* @file    widget.cpp
* @date    2026-03-22
* @author  GY
* @brief   使用 Qt Designer 方式重写查找对话框
*
* 通过 ui->setupUi() 注入 Designer 生成的界面对象。
* 使用 C++23 的 import std 规范以及 try-catch 包裹核心逻辑。
*
* Change Log:
* [v1.0] GY   2026-03-22
* * Initial creation
*/

#include "widget.h"
#include "ui_widget.h" // 必须包含自动生成的头文件

Widget::Widget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Widget) // 实例化 UI 指针
{
    // 1. 初始化界面（依据 widget.ui 的描述）
    ui->setupUi(this);

    // 2. 绑定自定义信号槽（Close 按钮已在 .ui 文件中绑定）
    connect(ui->lineEdit, &QLineEdit::textChanged,
            this, &Widget::enableFindButton);
    connect(ui->findButton, &QPushButton::clicked,
            this, &Widget::findClicked);

    // 3. 补充的窗口设置
    setFixedHeight(sizeHint().height()); // 固定窗口高度为最佳尺寸
}

Widget::~Widget()
{
    // 现在用到了 Ui::Widget，必须手动释放
    delete ui;
}

void Widget::findClicked()
{
    QString text = ui->lineEdit->text();
    // 控件访问全部加上 ui-> 前缀
    Qt::CaseSensitivity cs = ui->caseCheckBox->isChecked() ? Qt::CaseSensitive
                                                           : Qt::CaseInsensitive;

    if (ui->backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }
}

void Widget::enableFindButton(const QString &text)
{
    ui->findButton->setEnabled(!text.isEmpty());
}
