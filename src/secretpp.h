#ifndef SECRETPP_H
#define SECRETPP_H

#include <QMainWindow>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Secretpp;
}
using namespace std;
QT_END_NAMESPACE

class Secretpp : public QMainWindow
{
    Q_OBJECT

public:
    Secretpp(QWidget *parent = nullptr);
    ~Secretpp();

private slots:

    void on_loginButton_clicked();

private:
    Ui::Secretpp *app;

    int loginUser(string username, string password);
};
#endif // SECRETPP_H
