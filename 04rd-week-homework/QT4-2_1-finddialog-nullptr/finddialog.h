#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class FindDialog;
}
QT_END_NAMESPACE

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = nullptr);
    ~FindDialog() override;

private:
    Ui::FindDialog *ui;
};
#endif // FINDDIALOG_H
