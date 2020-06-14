#ifndef TOWER_H
#define TOWER_H
#include"rpgobj.h"
#include"myobject.h"
#include"bullet.h"
#include<QPushButton>
#include<QObject>
#include<QPainter>
#include<QString>
#include<QTimer>


class Tower:public QPushButton
{
    Q_OBJECT

public:
    Tower(int type,QPoint x);

    QPoint getPos(){return _pos;}
    int getRange(){return _range;}    
    int getMoney(){return _money;}

    void setRange(int x){_range=x;}   
    void setMoney(int x){_money=x;}
    void setPixmap(QString x){this->pixmap=x;}
    void setArgu(int rg,int mny);
    void setBullet();

    void upup(){this->_range=this->_range+20;
               this->_money=this->_money+6;
              }   //升级
    void draw(QPainter* painter){
        painter->drawPixmap(_pos,pixmap);
    }

    MyObject* GetAimsMonster() const;//返回当前目标怪物
    void SetAimsMonster(MyObject* mon);  //设置当前防御塔的目标怪物

    QPixmap pixmap;
    int type;
    MyObject* aimsmon;


signals:

   void choose_up();
private:
    QPoint _pos;   
    int _range;
    int _money;

 //   MyObject* aimsmon;//目标怪兽
    //子弹
    double _rotationSprite;
    QTimer* _fireRateTimer;
};


#endif // TOWER_H
