#ifndef SECRETPP_H
#define SECRETPP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Secretpp; }
QT_END_NAMESPACE

class Secretpp : public QMainWindow
{
    Q_OBJECT

public:
    Secretpp(QWidget *parent = nullptr);
    ~Secretpp();

private:
    Ui::Secretpp *ui;
};
#endif // SECRETPP_H
