#define SUCESS 200
#define USER_NOT_FOUND 404
#define UNDEFINED 500

#include <QDebug>
#include <QDir>
#include <string>

#include "secretpp.h"
#include "./ui_secretpp.h"

#include "pages/home/home.h"

#include "pages/signup/signup.h"

#include "./lib/db/db.h"

#include "./lib/json/json.hpp"

#include "./user.h"

using namespace std;
using json = nlohmann::json;

Secretpp::Secretpp(QWidget *parent)
    : QMainWindow(parent), app(new Ui::Secretpp)
{
    app->setupUi(this);

    // Definindo título da pagina
    setWindowTitle("Login | Secret++");
}

Secretpp::~Secretpp()
{
    delete app;
}

int Secretpp::loginUser(string username, string password)

{

    string dbFileName = (QDir::currentPath() + "/database.json").toStdString();

    DB db(dbFileName, "users");

    try
    {
        json doc = db.getDocument(username);

        qInfo() << QString::fromStdString(doc.dump(4));

        return SUCESS;
    }
    catch (string error)
    {
        qInfo() << QString::fromStdString(error);

        if (error == "document-not-found")
        {
            return USER_NOT_FOUND;
        }
        else
        {
            return UNDEFINED;
        }
    }
}

void Secretpp::on_loginButton_clicked()

{

    currentUsername = app->usernameInput->text().toStdString();
    currentPassword = app->passwordInput->text().toStdString();


    QWidget *homePage = new Home;

    switch (loginUser(currentUsername, currentPassword))
    {
    case SUCESS:
        qInfo() << "Usuário logado";
        this->close();

        homePage->show();

        break;

    case USER_NOT_FOUND:
        qInfo() << "Usuário não encontrado";
        app->status->setText("Usuário não encontrado.");
        break;
    default:
        qInfo() << "Erro indefinido";
        app->status->setText("Erro indefinido");
        break;
    }
}

void Secretpp::on_signUpButton_clicked()
{

    QWidget *signupPage = new Signup;
    this->close();

    signupPage->show();
}
