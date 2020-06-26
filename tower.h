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
    void upup(){this->_range=_range+20;}
    void draw(QPainter* painter){
        painter->drawPixmap(_pos,pixmap);
    }

    QPixmap pixmap;
    int type;
signals:

private:
    QPoint _pos;   
    int _range;
    int _money;
};


#endif // TOWER_H
