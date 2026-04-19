/*
 * 文件名:   finddialog.cpp
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-04-17
 * 描述:     /run/media/root/Windows/study/code/Qt-Software-Group7/Week7/Spreadsheet/finddialog.cpp
 * 版权声明: https://github.com/duruoxian
 */
#include "finddialog.h"
#include <QtWidgets>

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
{
    // 创建控件并设置对象名，便于后续通过findChild动态查找
    auto l = new QLabel(tr("Find &what"));
    l->setObjectName("label");

    auto le = new QLineEdit();
    le->setObjectName("lineEdit");

    auto fb = new QPushButton(tr("Find"));
    fb->setObjectName("findButton");

    auto cb = new QPushButton(tr("Close"));
    cb->setObjectName("closeButton");

    auto caseCheckBox = new QCheckBox(tr("Match &case"));
    caseCheckBox->setObjectName("caseCheckBox");

    auto backwardCheckBox = new QCheckBox(tr("Search &backward"));
    backwardCheckBox->setObjectName("backwardCheckBox");

    // 设置控件属性
    l->setBuddy(le);
    fb->setEnabled(false);
    fb->setDefault(true);

    // 左侧区域：输入框 + 选项
    auto topleftLayout = new QHBoxLayout();
    topleftLayout->addWidget(l);
    topleftLayout->addWidget(le);

    auto leftLayout = new QVBoxLayout();
    leftLayout->addLayout(topleftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    // 右侧区域：按钮
    auto rightLayout = new QVBoxLayout();
    rightLayout->addWidget(fb);
    rightLayout->addWidget(cb);
    rightLayout->addStretch();

    auto mainLayout = new QHBoxLayout();
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    setLayout(mainLayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());

    // 连接信号槽
    connect(le, &QLineEdit::textChanged, this, &FindDialog::enableFindButton);
    connect(fb, &QPushButton::clicked, this, &FindDialog::findClicked);
    connect(cb, &QPushButton::clicked, this, &FindDialog::close);
}

void FindDialog::enableFindButton(const QString &text)
{
    // 通过对象名查找按钮并更新使能状态
    QPushButton *findButton = findChild<QPushButton *>("findButton");
    findButton->setEnabled(!(text.isEmpty()));
}

void FindDialog::findClicked()
{
    // 获取大小写敏感选项
    QCheckBox *caseCheckBox = findChild<QCheckBox *>("caseCheckBox");
    Qt::CaseSensitivity cs =
        caseCheckBox->isChecked() ? Qt::CaseSensitive
                                  : Qt::CaseInsensitive;

    // 获取查找文本
    QLineEdit *lineEdit = findChild<QLineEdit *>("lineEdit");
    QString text = lineEdit->text();

    // 根据方向选项发射对应信号
    QCheckBox *backwardCheckBox = findChild<QCheckBox *>("backwardCheckBox");
    if(backwardCheckBox->isChecked()){
        emit findPrevious(text, cs);
        qDebug() << "信号findPrevious已发射";
    }
    else{
        emit findNext(text, cs);
        qDebug() << "信号findNext已发射";
    }
}