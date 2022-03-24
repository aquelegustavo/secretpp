#include<QDebug>
#include "secretpp.h"
#include "./ui_secretpp.h"

#include "pages/home/home.h"
#include "./pages/home/ui_home.h"

Secretpp::Secretpp(QWidget *parent)
    : QMainWindow(parent)
    , app(new Ui::Secretpp)
{
    app->setupUi(this);

    // Definindo título da pagina
    setWindowTitle("Login | Secret++");
}

Secretpp::~Secretpp()
{
    delete app;
}


void Secretpp::on_loginButton_clicked()
{
     qInfo() << app->passwordInput->text();
     this->close();

     QWidget *homePage = new Home;
     homePage->show();
}
