#ifndef AGE_H
#define AGE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Age;
}
QT_END_NAMESPACE

class Age : public QMainWindow
{
    Q_OBJECT

public:
    explicit Age(QWidget *parent = nullptr);
    ~Age() override;

private:
    Ui::Age *ui;
};
#endif // AGE_H
