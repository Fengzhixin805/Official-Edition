#include "tower.h"
#include "myobject.h"
#include"rpgobj.h"
#include"mw1.h"
#include<QAction>

Tower::Tower(int type,QPoint x):QPushButton(0)
{
    _pos=x;
    switch (type)
    {
    case 1:
    this->type=1;
    _money= 20;
    _range=250;
    setPixmap("://pics/tower1.png");
    break;
     case 2:
     this->type=2;    
    _money= 30;
    _range=350;
    setPixmap(("://pics/tower2.png"));
    break;
     }

}

void Tower::setArgu(int rg,int mny){
    _range=rg;
    _money=mny;
}



