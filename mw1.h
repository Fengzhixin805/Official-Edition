#ifndef MW1_H
#define MW1_H

#include <QMainWindow>
#include <QList>

#include"button.h"
#include"tower.h"

namespace Ui {
class MW1;
}

class MW1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MW1(QWidget *parent = 0);
    ~MW1();
    void paintEvent(QPaintEvent *);
    void paintSetBtn();
    void setTower1(QPoint x);

private:
    Ui::MW1 *ui;
    QList<Tower*> _towerlist;
    QList<Button*> _buttonlist;
};

#endif // MW1_H
