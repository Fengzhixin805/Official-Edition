#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPushButton>
#include<QPixmap>
#include<QString>
#include"rpgobj.h"

class Button : public QPushButton
{
    Q_OBJECT
public:
   Button(QString x,QPoint pos,int type);
   void draw(QPainter *painter){
       painter->drawPixmap(_pos,pixmap);
   }
   QPoint getPos(){return _pos;}
   int _type;

private:
   QPoint _pos;
   QPoint _stpos;
   QPoint _end;
   QPixmap pixmap;
signals:

public slots:

};

#endif // BUTTON_H
