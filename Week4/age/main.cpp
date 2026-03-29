/*
 * 文件名:   main.cpp
 * 创建者:   duruoxian (mail:drx00112233@qq.com)
 * 创建时间: 2026-03-29
 * 描述:     /run/media/root/Windows/study/code/group_7_store/Qt-Software-Group7/Week4/age/main.cpp
 * 版权声明: https://github.com/duruoxian
 */
#include <QApplication>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 创建主窗口
    QWidget *window = new QWidget;
    window->setWindowTitle("Enter Your Age");
    window->resize(400, 150);

    // 创建标签
    QLabel *label = new QLabel("Age:", window);
    label->move(20, 20);
    label->resize(40, 30);

    // 创建 QSpinBox
    QSpinBox *spinBox = new QSpinBox(window);
    spinBox->move(60, 20);
    spinBox->resize(80, 30);
    spinBox->setRange(0, 130);
    spinBox->setValue(35);

    // 创建 QSlider
    QSlider *slider = new QSlider(Qt::Horizontal, window);
    slider->move(150, 20);
    slider->resize(230, 30);
    slider->setRange(0, 130);
    slider->setValue(35);

    // 连接信号和槽
    QObject::connect(spinBox, QOverload<int>::of(&QSpinBox::valueChanged),
                     slider, &QSlider::setValue);
    QObject::connect(slider, &QSlider::valueChanged,
                     spinBox, &QSpinBox::setValue);

    window->show();

    return app.exec();
}