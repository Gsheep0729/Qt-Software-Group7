#include "age.h"
#include "ui_age.h"

Age::Age(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Age)
{
    ui->setupUi(this);
}

Age::~Age()
{
    delete ui;
}
