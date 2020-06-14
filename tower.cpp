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
    _money= 10;
    _range=250;
    setPixmap("://pics/tower1.png");
    break;
     case 2:
     this->type=2;    
    _money= 15;
    _range=350;
    setPixmap(("://pics/tower2.png"));
    break;
     }
    this->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction* up=new QAction(this);
    up->setText("升级");
    this->addAction(up);
    connect(up,&QAction::triggered,this,[=](){
        emit choose_up();
    });
}

void Tower::setArgu(int rg,int mny){
    _range=rg;
    _money=mny;
}

MyObject* Tower::GetAimsMonster() const //返回当前防御塔的目标怪物
{
    return aimsmon;
}

void Tower::SetAimsMonster(MyObject* mon)  //设置当前防御塔的目标怪物
{
    aimsmon = mon;
}


