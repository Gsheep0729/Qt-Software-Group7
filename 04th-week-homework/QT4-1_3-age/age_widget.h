/**
* @file    /run/media/root/铠侠D/桌面文件/Qt6软件开发资料/作业/04th-week-homework/QT4-1_3-age/age_widget.h
* @date    2026-03-29
* @author  GY
* @brief   Age 程序 (手工布局版本)
*
* <这里填写详细描述>
*
* Change Log:
* [v1.0] GY   2026-03-29
* * Initial creation
*/
#pragma once

#include <QWidget>

// 前向声明
class QSpinBox;
class QSlider;

class AgeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AgeWidget(QWidget *parent = nullptr);

protected:
    // 重写调整大小事件，在此处进行手工布局计算
    void resizeEvent(QResizeEvent *event) override;

private:
    // 在手工布局中，保留控件指针是必要的，以便在 resizeEvent 中随时访问它们
    QSpinBox *spinBox;
    QSlider *slider;
};