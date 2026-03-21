/**
* @file    widget.cpp
* @date    2026-03-22
* @author  GY
* @brief   实现《C++ GUI Qt4编程》2.1节 查找对话框
*
* 实现查找对话框的布局、信号槽连接以及具体查找逻辑。
* 支持快捷键伙伴设置、按钮使能控制以及根据复选框状态发出不同的查找信号。
*
* Change Log:
* [v1.0] GY   2026-03-22
* * Initial creation
*/
#include "widget.h"
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QDialog(parent)
{
    // 1. 实例化子窗口部件
    label = new QLabel(tr("Find &what:"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit); // 设置快捷键伙伴(Alt+W定位到输入框)

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);   // 回车键默认触发此按钮
    findButton->setEnabled(false);  // 初始状态下禁用

    closeButton = new QPushButton(tr("Close"));

    // 2. 连接信号与槽 (使用Qt5/6的函数指针语法，替代书中的SIGNAL/SLOT宏)
    connect(lineEdit, &QLineEdit::textChanged,
            this, &Widget::enableFindButton);
    connect(findButton, &QPushButton::clicked,
            this, &Widget::findClicked);
    connect(closeButton, &QPushButton::clicked,
            this, &Widget::close);

    // 3. 布局管理
    // 左上角的水平布局 (标签 + 输入框)
    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    // 左侧的垂直布局 (包含左上水平布局 + 两个复选框)
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    // 右侧的垂直布局 (包含两个按钮和弹簧)
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch(); // 添加弹簧，将按钮顶在上方

    // 主布局：水平排列左侧布局和右侧布局
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    // 应用主布局
    setLayout(mainLayout);

    // 设置窗口属性
    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height()); // 固定窗口高度为最佳尺寸
}

Widget::~Widget()
{
    // Qt的对象树机制会自动释放作为子对象的控件内存，
    // 因为没有用到 Ui::Widget，所以不需要 delete ui;
}

// 槽函数：点击查找按钮时的逻辑
void Widget::findClicked()
{
    QString text = lineEdit->text();
    // 判断是否区分大小写
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive
                                                       : Qt::CaseInsensitive;
    // 根据向后查找复选框的状态发出不同的信号
    if (backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }
}

// 槽函数：根据输入框是否有文本来启用或禁用“Find”按钮
void Widget::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}
