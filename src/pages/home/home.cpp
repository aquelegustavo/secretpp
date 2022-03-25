#include "home.h"
#include "ui_home.h"
#include "../../user.h"
#include "../../lib/db/db.h"
#include "../../lib/json/json.hpp"
#include <QString>
#include <QDebug>

Home::Home(QWidget *parent) : QWidget(parent),
                              homePage(new Ui::Home)
{

    homePage->setupUi(this);

    // Definindo título da pagina
    setWindowTitle("Início | Secret++");

    qInfo() << "User: " << QString::fromStdString(currentUsername);

    homePage->credentialsTable->setColumnCount(3);

    DB db("database.json", "users");

   try{
         json docs = db.findDocument("username", "");
         qInfo() << "User: " << QString::fromStdString(docs.dump(4));

    }catch(string error){
        qInfo() << QString::fromStdString(error);
    }



    //QTableWidgetItem* qtwi = new QTableWidgetItem(QString("Título"),QTableWidgetItem::Type);
    //homePage->credentialsTable->setHorizontalHeaderItem(0,qtwi);

    homePage->credentialsTable->verticalHeader()->setVisible(false);
    homePage->credentialsTable->horizontalHeader()->setVisible(false);

    homePage->credentialsTable->setColumnWidth(0, 640);


    connect(homePage->credentialsTable, &QTableWidget::cellClicked, this, &Home::updateSP);

    for (int i = 0; i < 200; i++)
    {

        homePage->credentialsTable->insertRow(i);
        homePage->credentialsTable->setItem(i, 0, new QTableWidgetItem("string"));


    }


}

Home::~Home()
{
    delete homePage;
}

void Home::updateSP(int row, int col){

    qInfo()<< QString::number(row)<< ":"<< QString::number(col);
}

void Home::onTableClicked(const QString & currentText)
{
  qInfo()<< currentText;

}
