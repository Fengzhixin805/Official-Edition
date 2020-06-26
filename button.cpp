#include "button.h"
#include"tower.h"
#include<QPixmap>
#include<QMouseEvent>
#include<QMenu>
#include<QAction>
#include<QVector2D>

Button::Button(QString x,QPoint pos,int type): QPushButton(0){
    QPixmap pixmap(x);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border.Qpx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    this->_pos=pos;
    this->_stpos=pos;
    this->pixmap=x;
    this->_end=_stpos+QPoint(pos.x(),600);
    _type=type;
}

