#include "button.h"
#include"tower.h"
#include<QPixmap>
#include<QMouseEvent>
#include<QMenu>
#include<QAction>

Button::Button(QString x,QPoint pos,int type): QPushButton(0){
    QPixmap pixmap(x);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border.Qpx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    this->_pos=pos;
    this->pixmap=x;
    _type=type;
}


