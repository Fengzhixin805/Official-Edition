#include "bullet.h"
#include<QVector2D>
Bullet::Bullet(QPoint startPos,QPoint EndPos,double distance):QObject(0),_pixmap("://pics/bullet.png")
{
    _start=startPos;
    _end=EndPos;
    _currentPos=startPos;
    speed=(int)distance/4;
}

void Bullet::move(){
    QVector2D vector(_end-_start);
    vector.normalize();
    _currentPos=_currentPos+vector.toPoint()*speed;
}

void Bullet::draw(QPainter *painter){
    painter->drawPixmap(_currentPos,_pixmap);
}
