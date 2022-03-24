#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent) :
    QWidget(parent),
    homePage(new Ui::Home)
{
    homePage->setupUi(this);

    // Definindo título da pagina
    setWindowTitle("Início | Secret++");
}

Home::~Home()
{
    delete homePage;
}
