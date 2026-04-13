//Created By Chunlin Feng 1356962534@qq.com
//age重写并且改用手动布局的形式
#include <QApplication>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 1. 创建主窗口
    QWidget *window = new QWidget;
    window->setWindowTitle("Enter Your Age");
    window->setFixedSize(400, 80);

    // 2. 创建控件
    QSpinBox *spinBox = new QSpinBox(window);
    QSlider *slider = new QSlider(Qt::Horizontal, window);

    // 3. 设置年纪显示范围
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                     slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)),
                     spinBox, SLOT(setValue(int)));
    //手动设置原点和大小
    spinBox->setGeometry(10, 20, 150, 40);
    slider->setGeometry(170, 20, 220, 40);
    spinBox->setValue(35);

    window->show();
    return app.exec();
}