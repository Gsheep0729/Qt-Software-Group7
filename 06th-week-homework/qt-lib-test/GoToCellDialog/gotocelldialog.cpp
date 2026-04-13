/**
* @file    gotocelldialog.cpp
* @date    2026-04-11
* @author  GY
* @brief   定位单元格对话框实现
*
* Change Log:
* [v1.0] GY   2026-04-11
* * Initial creation
* [v3.0] GY   2026-04-11
* * 使用多重继承方式
* [v4.0] GY   2026-04-11
* * 使用成员变量方式
* [v5.0] GY   2026-04-11
* * 使用 Pimpl（私有指针）实现完全解耦
*/
#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"
#include <QRegularExpressionValidator>

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GoToCellDialog)
{
    // 加载UI
    ui->setupUi(this);

    // 限制输入格式：字母+数字 (如 A1, Z999)
    QRegularExpression regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegularExpressionValidator(regExp, this));

    // 连接信号槽
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &GoToCellDialog::onTextChanged);
    connect(ui->okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

GoToCellDialog::~GoToCellDialog()
{
    delete ui;
}

void GoToCellDialog::onTextChanged()
{
    // 根据输入有效性启用/禁用OK按钮
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}
