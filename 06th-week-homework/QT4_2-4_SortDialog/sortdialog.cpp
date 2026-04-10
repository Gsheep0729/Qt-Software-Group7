/**
* @file    sortdialog.cpp
* @brief   Sort Dialog 界面类实现 - 处理 UI 交互与逻辑路由
* @author  GY
* @date    2026-04-10
*
* Change Log:
* [v1.0] GY 2026-04-10 Implemented PMF-based signal/slot connections.
*/

#include "sortdialog.h"
#include "ui_sortdialog.h"

SortDialog::SortDialog(QWidget *parent)
    : QDialog{parent}
    , _ui{new Ui::SortDialog} // 统一初始化列表分配堆内存
{
    _ui->setupUi(this);

    // 界面表现层初始化：默认隐藏扩展区域
    _ui->secondaryGroupBox->hide();
    _ui->tertiaryGroupBox->hide();

    // 强制布局自适应内容尺寸
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    // 初始化排序选项
    const QStringList orderItems{tr("Ascending"), tr("Descending")};
    _ui->primaryOrderCombo->addItems(orderItems);
    _ui->secondaryOrderCombo->addItems(orderItems);
    _ui->tertiaryOrderCombo->addItems(orderItems);

    /**
     * 信号与槽连接：采用 C++23 标准下的强类型成员函数指针 (PMF)
     * 这种方式在编译阶段即可捕获参数不匹配错误
     */

    // 标准对话框行为路由
    connect(_ui->okButton, &QPushButton::clicked, this, &SortDialog::accept);
    connect(_ui->cancelButton, &QPushButton::clicked, this, &SortDialog::reject);

    // 联动逻辑：More 按钮切换扩展面板可见性
    // 注意：此处直接连接两个槽，维持代码简洁且逻辑内聚
    connect(_ui->moreButton, &QPushButton::toggled, _ui->secondaryGroupBox, &QGroupBox::setVisible);
    connect(_ui->moreButton, &QPushButton::toggled, _ui->tertiaryGroupBox, &QGroupBox::setVisible);

    setColumnRange('A', 'Z');
}

SortDialog::~SortDialog()
{
    // Ui::SortDialog 类不由对象树管理，必须手动释放
    delete _ui;
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    _ui->primaryColumnCombo->clear();
    _ui->secondaryColumnCombo->clear();
    _ui->tertiaryColumnCombo->clear();

    _ui->secondaryColumnCombo->addItem(tr("None"));
    _ui->tertiaryColumnCombo->addItem(tr("None"));

    _ui->primaryColumnCombo->setMinimumSize(_ui->secondaryColumnCombo->sizeHint());

    // 迭代字符范围并填充
    for (char16_t u = first.unicode(); u <= last.unicode(); ++u) {
        const QString col{QChar{u}};
        _ui->primaryColumnCombo->addItem(col);
        _ui->secondaryColumnCombo->addItem(col);
        _ui->tertiaryColumnCombo->addItem(col);
    }
}