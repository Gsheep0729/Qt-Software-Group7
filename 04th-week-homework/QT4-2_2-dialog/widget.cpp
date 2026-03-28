/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/04th-week-homework/QT4-2_2-dialog/widget.cpp
* @date    2026-03-28
* @author  GY
* @brief   查找对话框类的实现文件
*
* 本文件实现了Widget类的功能，包括对话框的初始化、
* 文本输入框的变化处理、以及查找按钮的点击事件处理。
*
* Change Log:
* [v1.0] GY   2026-03-28
* * Initial creation
*/

#include "widget.h"

/**
 * @brief Widget类的构造函数
 * @param parent 父窗口指针
 */
Widget::Widget(QWidget *parent)
    : QDialog(parent)
{
    // 自动加载UI界面，实例化所有控件
    setupUi(this);

    // 设置label和lineEdit的伙伴关系（快捷键关联）
    label->setBuddy(lineEdit);

    // 设置查找按钮为默认按钮（按Enter触发）
    findButton->setDefault(true);

    // 初始状态下禁用查找按钮（输入框为空）
    findButton->setEnabled(false);

    // 连接关闭按钮的点击信号到关闭槽
    connect(closeButton, &QPushButton::clicked, this, &Widget::close);
}

/**
 * @brief 文本输入框内容变化的槽函数
 * @param text 输入框中的当前文本
 *
 * 使用Qt自动关联机制：函数名格式为 on_控件名_信号名()
 */
void Widget::on_lineEdit_textChanged(const QString &text)
{
    // 根据输入内容是否为空来启用或禁用查找按钮
    findButton->setEnabled(!text.isEmpty());
}

/**
 * @brief 查找按钮点击事件的槽函数
 *
 * 使用Qt自动关联机制
 */
void Widget::on_findButton_clicked()
{
    QString text = lineEdit->text();

    // 根据复选框设置是否区分大小写
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;

    // 根据查找方向发射相应的信号
    if (backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);  // 向后查找
    } else {
        emit findNext(text, cs);      // 向前查找
    }
}