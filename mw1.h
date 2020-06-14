#ifndef MW1_H
#define MW1_H

#include <QMainWindow>
#include<QSound>
#include <QVector>
#include <QLabel>
#include<QRectF>
#include<QMediaPlayer>
#include<QSignalMapper>
#include"button.h"
#include"myobject.h"
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
    void updateScreen();

//测试按钮的函数
    void setTower();
    void setTower_();

    void innitBtns();
    void innitBtn();
    void drawlabel();
    void DrawTower(QPainter* painter);
    inline bool DeductionMoney(int money);  //减去花费的钱
    inline bool DeductionLife(int life);  //减去生命

    void setmonster(int type,QPoint x);

    //关于子弹

    void addBullet(QPoint start,QPoint end,double distance);
    void removeBullet(Bullet* x){_bulletlist.removeOne(x);
                                delete x;}

    int _counter=0;
    int _money = 1000;   //记录金钱
    int _life=100;

    bool m_gameWin;
    bool m_gameEnd;

    QLabel *moneylable = new QLabel(this);   //显示金钱标签控件
    QLabel *lifelable = new QLabel(this);   //显示金钱标签控

    QVector <Tower*> _towerlist;
    QVector <Button*> _buttonlist;
    QVector <Bullet*> _bulletlist;
    QVector <MyObject*> _monsterlist;

    QTimer *timer1;
    QTimer *timer2;

private slots:
void Move();
void addmonster();
void setTower1(QPoint pos);
void setTower2(QPoint pos);
void bulletadd();
void deletBullet();
private:
    Ui::MW1 *ui;

};

#endif // MW1_H
