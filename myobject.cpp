#include "myobject.h"
#include<QParallelAnimationGroup>
#include<QSound>

MyObject::MyObject(int type,QPoint now) : QObject(0)
{
    this->_nowpos=now;
    this->_id=type;
    switch (_id)
    {
    case 1: //刀叉怪
        _hp = 100;   //生命值
        _maxhp=100;
        _my= 30;
        _power=10;
        setpixmap("://pics/monster1");
        break;
    case 2: //绿龙
        _hp=50;
        _maxhp=50;
        _my=20;
        _power=20;
        setpixmap(("://pics/monster2"));
        break;
}
}

void MyObject::draw(QPainter *painter){
    painter->drawPixmap(_nowpos,pixmap);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    static const int Health_Bar_Width = 40;
        painter->save();
        QPoint healthBarPoint = _nowpos ;
        // 绘制血条
        painter->setPen(Qt::NoPen);
        painter->setBrush(Qt::red);
        QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 2));
        painter->drawRect(healthBarBackRect);
        painter->setBrush(Qt::green);
        QRect healthBarRect(healthBarPoint, QSize((double)this->_hp / this->_maxhp * Health_Bar_Width, 2));
        painter->drawRect(healthBarRect);

}
void MyObject::move(int direction, int steps){
    switch (direction){
            case 1:
                this->_nowpos.setY(_nowpos.y()-steps*75);
                break;
            case 2:
                 this->_nowpos.setY(_nowpos.y()+steps*75);
                break;
            case 3:
                this->_nowpos.setX(_nowpos.x()-steps*65);
                break;
            case 4:
              this->_nowpos.setX(_nowpos.x()+steps*65);
                break;
        }

    }

   QPoint MyObject::getNext(int direction){
       switch (direction){
           case 1:
               return QPoint(this->getNow().x(),this->getNow().y()-75);
           case 2:
              return  QPoint(this->getNow().x(),this->getNow().y()+75);
           case 3:
              return  QPoint(this->getNow().x()-70,this->getNow().y());
           case 4:
              return QPoint(this->getNow().x()+70,this->getNow().y());
       }
   }


