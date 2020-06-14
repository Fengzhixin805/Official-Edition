#ifndef RPGOBJ_H
#define RPGOBJ_H
//#include <QMediaPlayer>
#include <QImage>
#include <QPainter>
#include <string>
#include <icon.h>
#include <map>

#include"icon.h"
using namespace std;

class RPGObj
{
public:
    RPGObj(string type,QPoint x);

    void show(QPainter * painter);

    void setPos(QPoint y){this->_pos=y;}
    QPoint getPos(){return this->_pos;}
    int getHeight() const{return this->_icon.getHeight();}
    int getWidth() const{return this->_icon.getWidth();}
    bool canEat() const{return this->_eatable;}

    string getObjType() const{return this->_icon.getTypeName();}//返回类名
    QPixmap getObjPath() const{return this->_icon.getPath();}

private:
    //所有坐标，单位均为游戏中的格
    QPoint _pos;
    ICON _icon;//可以从ICON中获取对象的素材，尺寸等信息
    bool _eatable;
};

#endif // RPGOBJ_H
