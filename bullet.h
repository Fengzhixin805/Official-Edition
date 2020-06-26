#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include<QPoint>
#include<QPainter>

class Bullet : public QObject
{
    Q_OBJECT
public:
   Bullet(QPoint startPos,QPoint EndPos);

   void move();
   void draw(QPainter* painter);
   QPoint getPosnow(){return _currentPos;}
   QPoint getPosend(){return _end;}
   QPoint getPosStart(){return _start;}
private:
   QString _pixmap;
   QPoint _start;
   QPoint _end;
   QPoint _currentPos;
   qreal speed;
signals:

public slots:
};

#endif // BULLET_H
