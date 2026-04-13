//Created By Chunlin Feng 1356962534@qq.com
//2026-3-19
//this is the headers files for null ptr use
//无指针用成员函数
#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
    , label(tr("Find &what:"))
    , findButton(tr("&Find"))
    , closeButton(tr("C&lose"))
    , caseCheckBox(tr("Match &case"))
    , backwardCheckBox(tr("Search &backward"))
{
    // 设置伙伴关系
    label.setBuddy(&lineEdit);

    // 按钮默认设置
    findButton.setDefault(true);
    findButton.setEnabled(false);

    // 布局
    topLayout.addWidget(&label);
    topLayout.addWidget(&lineEdit);

    checkLayout.addWidget(&caseCheckBox);
    checkLayout.addWidget(&backwardCheckBox);

    btnLayout.addWidget(&findButton);
    btnLayout.addWidget(&closeButton);

    mainLayout.addLayout(&topLayout);
    mainLayout.addLayout(&checkLayout);
    mainLayout.addLayout(&btnLayout);

    setLayout(&mainLayout);

    // 信号槽
    connect(&lineEdit,    &QLineEdit::textChanged,  this, &FindDialog::enableFindButton);
    connect(&findButton,  &QPushButton::clicked,    this, &FindDialog::findClicked);
    connect(&closeButton, &QPushButton::clicked,    this, &FindDialog::close);

    setWindowTitle(tr("Find"));
}

void FindDialog::findClicked()
{
    QString text = lineEdit.text();
    Qt::CaseSensitivity cs = caseCheckBox.isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;

    if (backwardCheckBox.isChecked())
        emit findPrevious(text, cs);
    else
        emit findNext(text, cs);
}

void FindDialog::enableFindButton(const QString &text)
{
    findButton.setEnabled(!text.isEmpty());
}