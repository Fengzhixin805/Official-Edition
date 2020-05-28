#include "mw1.h"
#include "ui_mw1.h"
#include "tower.h"

#include<QPainter>
#include<QList>
#include <QAction>

MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);

    paintSetBtn();      //   画出放置塔的按钮


}

void MW1::setTower1(QPoint x){
  Tower *a=new Tower(x,"Tower1");
    _towerlist.push_back(a);
}

MW1::~MW1()
{
    delete ui;
}

void MW1::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap("://pics/map2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    QPixmap renyu("://pics/renyu.png");
    painter.drawPixmap(700,325,100,125,renyu);
}

void MW1::paintSetBtn(){
    Button *x =new Button("://pics/setTower.png");
    _buttonlist.push_back(x);
    x->setParent(this);
    x->move(70,75);

    Button *bt1 =new Button("://pics/setTower.png");
    _buttonlist.push_back(bt1);
    bt1->setParent(this);
    bt1->move(135,75);

    for(int i=0;i<5;i++){
    Button *bt =new Button("://pics/setTower.png");
    _buttonlist.push_back(bt);
    bt->setParent(this);
    bt->move(267,75+75*i);

    Button *bt2 =new Button("://pics/setTower.png");
    _buttonlist.push_back(bt2);
    bt2->setParent(this);
    bt2->move(400,150+75*i);
    }
    for(int k=0;k<2;k++){
        for (int j=0;j<2;j++){
            Button *bt3 =new Button("://pics/setTower.png");
            _buttonlist.push_back(bt3);
            bt3->setParent(this);
            bt3->move(135+j*65,225+75*k);
        }
    }

    Button *bt4 =new Button("://pics/setTower.png");
    _buttonlist.push_back(bt4);
    bt4->setParent(this);
    bt4->move(70,455);

    Button *bt5 =new Button("://pics/setTower.png");
    _buttonlist.push_back(bt5);
    bt5->setParent(this);
    bt5->move(130,455);

    for (int i=0;i<2;i++)
{    Button *bt6 =new Button("://pics/setTower.png");
    _buttonlist.push_back(bt6);
    bt6->setParent(this);
    bt6->move(465+65*i,150);
}
    for (int i=0;i<2;i++)
{    Button *bt6 =new Button("://pics/setTower.png");
    _buttonlist.push_back(bt6);
    bt6->setParent(this);
    bt6->move(535,300+i*75);
}
    int s=_buttonlist.size();
        for(int i=0;i<s;i++){
            _buttonlist[i]->setGeometry(_buttonlist[i]->pos().x(),_buttonlist[i]->pos().y(),50,25); //设置一下菜单按钮的大小
            QMenu *menu = new QMenu(this); //创建一个菜单项
            _buttonlist[i]->setMenu(menu); //将按钮设置成刚刚创建的菜单项
             QMenu *e = menu->addMenu(QString("初级塔"));
             QMenu *h = menu->addMenu(QString("高级塔"));
        }

}
