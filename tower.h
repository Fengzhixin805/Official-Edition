#ifndef TOWER_H
#define TOWER_H

#include "rpgobj.h"

class Tower:public RPGObj
{
public:
    Tower();
    Tower(QPoint pos,string tp);
    void setPower(int rg,int dmg,int rt);
    void draw(QPainter *painter);
    int getRange(){return this->_range;}
    int getDamage(){return this->_damage;}
    int getRate(){return this->_rate;}
private:
    int _range;
    int _damage;
    int _rate;
    bool _hasTower;
};

#endif // TOWER_H
