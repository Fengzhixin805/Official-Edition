#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include<QPropertyAnimation>
#include<QPoint>
#include<QPixmap>
#include<QPainter>
#include<QVector>

class MyObject : public QObject
{
    Q_OBJECT
public:
    ~MyObject(){delete this;}
   MyObject(int type,QPoint now);
   void draw(QPainter* painter);
   void move(int direction, int steps);//控制怪兽move
   QPoint getNow(){return this->_nowpos;}
   void setNow(QPoint x){this->_nowpos=x;}
   QPoint getNext(int direction);
   void setpixmap(QString x){pixmap=x;}

   int GetWidth(){return pixmap.width();}
   int GetHeight(){return pixmap.height();}
   int GetX(){return _nowpos.x();}
   int GetY(){return _nowpos.y();}
   int Getmny(){return _my;}
   void SetAgu(int id,int hp,int my){_id=id;_hp=hp;_my=my;}
   int GetHealth(){return _hp;}
   void SetHealth(int x){_hp=x;}
   int GetPower(){return _power;}

   void Getattacked(int x){_hp=_hp-x;}
   int F=-1;//控制monster行走的计步器

   QPoint _nowpos;
   QPixmap pixmap;

   int _maxhp;//初始血量
   int _id;
   int _hp;//现在血量
   int _my;//一个怪值的钱money
   int _power;
};

#endif // MYOBJECT_H
