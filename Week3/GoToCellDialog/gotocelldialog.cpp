/*
 * 文件名:   gotocelldialog.cpp
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-03-22
 * 描述:     /run/media/root/Windows/study/code/group_7_store/Qt-Software-Group7/GoToCellDialog/gotocelldialog.cpp
 * 版权声明: https://github.com/duruoxian
 */
#include "gotocelldialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Go to Cell");
    setModal(true);
    setGeometry(100, 100, 300, 120);

    // 创建标签
    label = new QLabel("&Cell Location:");

    // 创建行编辑
    lineEdit = new QLineEdit();
    // 设置正则表达式验证器，允许格式如 A1, B2 等（列字母 + 行数字）
    QRegularExpression regExp("[A-Z][1-9]\\d{0,2}");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regExp, this);
    lineEdit->setValidator(validator);
    label->setBuddy(lineEdit);

    // 创建按钮
    okButton = new QPushButton("&OK");
    cancelButton = new QPushButton("&Cancel");
    okButton->setDefault(true);
    okButton->setEnabled(false);

    // 连接信号和槽
    connect(lineEdit, &QLineEdit::textChanged, this, &GoToCellDialog::onLineEditTextChanged);
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    // 创建布局
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(label);
    topLayout->addWidget(lineEdit);

    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addStretch();
    bottomLayout->addWidget(okButton);
    bottomLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);
}

QString GoToCellDialog::getCell() const
{
    return lineEdit->text();
}

void GoToCellDialog::onLineEditTextChanged()
{
    okButton->setEnabled(!lineEdit->text().isEmpty());
}
