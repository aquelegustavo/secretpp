#include "secretpp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Secretpp w;

    w.show();
    return a.exec();
}
