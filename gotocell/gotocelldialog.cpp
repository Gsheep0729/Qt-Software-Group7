#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QPushButton>

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QMainWindow(parent)  // 改成 QMainWindow
    , ui(new Ui::GoToCellDialog)
{
    ui->setupUi(this);

    QRegularExpression regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegularExpressionValidator(regExp, this));

    connect(ui->okButton, &QPushButton::clicked, this, &QMainWindow::close);  // 改成 close
    connect(ui->cancelButton, &QPushButton::clicked, this, &QMainWindow::close);
}

GoToCellDialog::~GoToCellDialog()
{
    delete ui;
}

void GoToCellDialog::on_lineEdit_textChanged()
{
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}
