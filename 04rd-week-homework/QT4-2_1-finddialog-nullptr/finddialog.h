//Created By Chunlin Feng 2026-3-26 00:48
//this file is just for my headers files studying

#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;


class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = nullptr);

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);
private slots:
    void findClicked();
    void enableFindButton(const QString &text);
private:
    QLabel label;
    QLineEdit lineEdit;
    QCheckBox caseCheckBox;
    QCheckBox backCheckBox;
    QPushButton findButton;
    QPushButton closeButton;
};
#endif // FINDDIALOG_H
