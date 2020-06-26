#include "bullet.h"
#include<QVector2D>
Bullet::Bullet(QPoint startPos,QPoint EndPos):QObject(0),_pixmap("://pics/bullet.png")
{
    _start=startPos;
    _end=EndPos;
    _currentPos=startPos;
    speed=8;//(int)distance/10;
}

void Bullet::move(){
    QVector2D vector(_end-_start);
    vector.normalize();
    _currentPos=_currentPos+vector.toPoint()*speed;
}

void Bullet::draw(QPainter *painter){
    painter->drawPixmap(_currentPos,_pixmap);
}
