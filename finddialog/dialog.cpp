/*
 * 文件名:   dialog.cpp
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-03-29
 * 描述:     /run/media/root/Windows/study/code/group_7_store/Qt-Software-Group7/Week4/finddialog/dialog.cpp
 * 版权声明: https://github.com/duruoxian
 */
#include "dialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

SearchDialog::SearchDialog(QWidget *parent)
    : QDialog(parent),
    label(nullptr),
    lineEdit(nullptr),
    findButton(nullptr),
    closeButton(nullptr),
    caseCheckBox(nullptr),
    backwardCheckBox(nullptr)
{
    // 设置对话框标题和大小
    setWindowTitle(tr("查找"));
    resize(400, 200);

    // 创建所有界面元素
    createWidgets();

    // 连接信号与槽
    connect(lineEdit, &QLineEdit::textChanged, this, &SearchDialog::onLineEditTextChanged);
    connect(findButton, &QPushButton::clicked, this, &SearchDialog::onFindButtonClicked);
    connect(closeButton, &QPushButton::clicked, this, &SearchDialog::close);
}

SearchDialog::~SearchDialog()
{
}

void SearchDialog::createWidgets()
{
    // 创建标签
    label = new QLabel(tr("查找内容(&N):"), this);

    // 创建输入框
    lineEdit = new QLineEdit(this);
    label->setBuddy(lineEdit);

    // 创建查找按钮
    findButton = new QPushButton(tr("查找(&F)"), this);
    findButton->setDefault(true);
    findButton->setEnabled(false);

    // 创建关闭按钮
    closeButton = new QPushButton(tr("关闭(&C)"), this);

    // 创建复选框
    caseCheckBox = new QCheckBox(tr("区分大小写(&C)"), this);
    backwardCheckBox = new QCheckBox(tr("向后查找(&B)"), this);

    // 创建布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 第一行：标签和输入框
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(label);
    topLayout->addWidget(lineEdit);
    mainLayout->addLayout(topLayout);

    // 第二行：查找和关闭按钮
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(findButton);
    buttonLayout->addWidget(closeButton);
    buttonLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    // 第三行：复选框
    QHBoxLayout *checkLayout = new QHBoxLayout;
    checkLayout->addWidget(caseCheckBox);
    checkLayout->addWidget(backwardCheckBox);
    checkLayout->addStretch();
    mainLayout->addLayout(checkLayout);

    mainLayout->addStretch();
}

void SearchDialog::onLineEditTextChanged(const QString &text)
{
    // 根据文本框是否为空来启用或禁用查找按钮
    findButton->setEnabled(!text.isEmpty());
}

void SearchDialog::onFindButtonClicked()
{
    // 获取输入框中的文本
    QString text = lineEdit->text();

    // 根据大小写复选框的状态设置大小写敏感性
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;

    // 根据查找方向发射相应的信号
    if (backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }
}