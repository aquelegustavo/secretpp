#ifndef HOME_H
#define HOME_H

#include <QWidget>

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

private:
    Ui::Home *homePage;
    void onTableClicked(const QString & currentText);
    void updateSP(int row, int col);
};

#endif // HOME_H
