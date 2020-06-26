#ifndef MW2_H
#define MW2_H

#include <QMainWindow>
#include<QPainter>

namespace Ui {
class MW2;
}

class MW2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MW2(QWidget *parent = 0);
    ~MW2();
    void paintEvent(QPaintEvent *);

private:
    Ui::MW2 *ui;
};

#endif // MW2_H
