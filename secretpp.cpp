#include "secretpp.h"
#include "./ui_secretpp.h"

Secretpp::Secretpp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Secretpp)
{
    ui->setupUi(this);
}

Secretpp::~Secretpp()
{
    delete ui;
}

