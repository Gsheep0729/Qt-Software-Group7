/*
 * 文件名:   widget.cpp
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-03-22
 * 描述:     /run/media/root/Windows/study/code/group_7_store/Qt-Software-Group7/GoToCellDialog/widget.cpp
 * 版权声明: https://github.com/duruoxian
 */
#include "widget.h"
#include "gotocelldialog.h"
#include <QVBoxLayout>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Go to Cell Dialog Example");
    setGeometry(100, 100, 400, 300);

    goToCellButton = new QPushButton("&Go to Cell");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(goToCellButton);
    layout->addStretch();
    setLayout(layout);

    connect(goToCellButton, &QPushButton::clicked, this, &Widget::onGoToCellClicked);
}

Widget::~Widget()
{
}

void Widget::onGoToCellClicked()
{
    GoToCellDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString cell = dialog.getCell();
        QMessageBox::information(this, "Go to Cell", QString("You selected cell: %1").arg(cell));
    }
}
