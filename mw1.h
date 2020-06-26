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
#include"explosion.h"

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
    void delettower();
    void innitBtn();
    void drawlabel();
    void DrawTower(QPainter* painter);
    inline bool DeductionMoney(int money);  //减去花费的钱
    inline bool DeductionLife(int life);  //减去生命

    void setmonster(int type,QPoint x);

    //关于子弹
    void addBullet(QPoint start,QPoint end);
    void removeBullet(Bullet* x){_bulletlist.removeOne(x);
                                delete x;}
    void addplosion(QPoint position);

    //关于怪兽
    void attacked();
    int _money = 50;   //记录金钱
    int _life=100;

    QLabel *moneylable = new QLabel(this);   //显示金钱标签
    QLabel *lifelable = new QLabel(this);   //显示生命标签    

    QVector <Tower*> _towerlist;
    QVector <Button*> _buttonlist;
    QVector <Bullet*> _bulletlist;
    QVector <MyObject*> _monsterlist;
    QVector <Explosion*> _plosionlist;


    QTimer *timer1;
    QTimer *timer2;

private slots:
void Move();
void addmonster();
void setTower();
void setTower_();
void setTower__();
void setTower3();
void setTower4();
void setTower5();
void setTower6();
void setTower7();
void setTower8();
void setTower9();
void setTower10();
void bulletadd();
void deletBullet();
private:
    Ui::MW1 *ui;

};

#endif // MW1_H
