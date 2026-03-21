#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GoToCellDialog)
{
    ui->setupUi(this);

    // 设置正则表达式验证器：允许1个大小写字母，后跟1到3个数字 (例如 A1, Z999)
    QRegularExpression regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegularExpressionValidator(regExp, this));

    // OK 和 Cancel 按钮直接连接到 QDialog 内置的 accept() 和 reject() 槽
    connect(ui->okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

GoToCellDialog::~GoToCellDialog()
{
    delete ui;
}

// 槽函数实现：当输入合法时，才启用 OK 按钮
void GoToCellDialog::on_lineEdit_textChanged()
{
    // hasAcceptableInput() 会根据上面设置的正则表达式验证器来判断输入是否合法
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}
