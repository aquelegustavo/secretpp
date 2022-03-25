#include "signup.h"
#include "ui_signup.h"
#include "../../user.h"
#include "../home/home.h"

#include "../../lib/db/db.h"
#include "../../lib/json/json.hpp"

Signup::Signup(QWidget *parent) :
    QWidget(parent),
    signupPage(new Ui::Signup)
{
    signupPage->setupUi(this);
}

Signup::~Signup()
{
    delete signupPage;
}

void Signup::on_signupButton_clicked()
{
    DB db("database.json", "users");

    json userData = {};

    string name = signupPage->nameInput->text().toStdString();
    currentUsername = signupPage->usernameInput->text().toStdString();
    currentPassword = signupPage->passwordInput->text().toStdString();

    userData["name"] = name;
    userData["username"] = currentUsername;
    userData["hashed_password"] = currentPassword;

    // Adicionar documento
    string docId = db.setDocument(userData, currentUsername);

    QWidget *homePage = new Home;

    homePage->show();

    this-> close();

}
