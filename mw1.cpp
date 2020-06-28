#include "mw1.h"
#include "ui_mw1.h"
#include"tower.h"
#include"button.h"
#include"mw2.h"
#include<QRectF>
#include<QTime>
#include<QTimer>
#include<QPainter>
#include<QList>
#include<QMediaPlayer>
#include <QAction>
#include<QLabel>
#include<QSignalMapper>
#include<QPalette>
#include<QSignalMapper>
#include<QDebug>
#include<QSound>
int M=0;
double GetDistance(int X1,int Y1,int X2,int Y2){
    return abs(sqrt((((X1) - (X2)) * ((X1) - (X2))) + (((Y1) - (Y2)) * ((Y1) - (Y2)))));
}

MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    setFixedSize(800, 600);
    ui->setupUi(this);
    innitBtn();
    drawlabel();

    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc://sounds/hdl.mp3"));
    player->setVolume(30);
    player->play();

    //用于插入怪物定时器
    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(addmonster()));
    timer2->start(5000);
    timer2->setInterval(1500);

    //怪兽移动和受击判断
    timer1=new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(Move()));
    connect(timer1,&QTimer::timeout,this,&MW1::attacked);//Move()为自定义槽函数
    timer1->start(1000);
   // timer1->setInterval(1000);     //时间可设置难度

    QTimer* updt2=new QTimer(this);
    connect(updt2,SIGNAL(timeout()),this,SLOT(bulletadd()));
    updt2->start(1000);
    //子弹运动
    QTimer* updt=new QTimer(this);
    connect(updt,&QTimer::timeout,this,&MW1::updateScreen);
    connect(updt,SIGNAL(timeout()),this,SLOT(deletBullet()));
    updt->start(100);
}

MW1::~MW1()
{
    delete ui;
}

//画标签
void MW1::drawlabel(){
    //生命标签
    QPalette pe;
    lifelable->setGeometry(630,0,150,80);   //设置控件位置和大小
    lifelable->setFont(QFont("黑体", 16));
    pe.setColor(QPalette::WindowText, Qt::white);//设置颜色
    lifelable->setPalette(pe);
    lifelable->setText(QString("生命：%1").arg(_life));
    //金钱标签
    moneylable->setGeometry(460,0,200,80);   //设置控件位置和大小
    moneylable->setFont(QFont("黑体", 16));
    pe.setColor(QPalette::WindowText, Qt::white);//设置颜色
    moneylable->setPalette(pe);
    moneylable->setText(QString("金币：%1").arg(_money));
}

//画塔
void MW1::DrawTower(QPainter* painter)
{
    //遍历防御塔数组
    foreach (Tower* defei, _towerlist) {
         painter->drawPixmap(defei->getPos(),defei->pixmap);
         painter->setPen(QPen(Qt::white));  //使用白色画出范围
         painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
         painter->drawEllipse(defei->getPos().x()-defei->getRange()*2/5, defei->getPos().y()-defei->getRange()*2/5,defei->getRange(), defei->getRange());
    }
}

//绘画事件
void MW1::paintEvent(QPaintEvent *){
    if(_money>500){
        MW2 *win =new MW2;
        this->close();
        win->show();
    }
    QPainter painter(this);
    QPixmap pixmap("://pics/map2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    QPixmap renyu("://pics/home.png");
    painter.drawPixmap(700,325,100,125,renyu);
    //画塔
    DrawTower(&painter);
   //画按钮
    int a=this->_buttonlist.size();
    for(int k=0;k<a;k++){
        this->_buttonlist[k]->draw(&painter);
    }
    //画怪兽
    int n = this->_monsterlist.size();
    for (int i=0;i<n;i++){
        this->_monsterlist[i]->draw(&painter);
    }
    //画子弹
    foreach (Bullet* x, _bulletlist) {
        x->draw(&painter);
    }
    //画轰击
    foreach (Explosion* x, _plosionlist) {
        x->show(&painter);
    }
}

//monster的移动函数
void MW1::Move(){    
    foreach (MyObject* x,_monsterlist) {
    if(x->F<2){
    x->move(2,1);
    x->F++;
    this->repaint();
    continue;
    }
    if(x->F<4){
        x->move(3,1);
        x->F++;
        this->repaint();
        continue;
    }
    if(x->F<7){
         x->move(2,1);
        x->F++;
        this->repaint();
        continue;
    }
    if(x->F<9){
         x->move(4,1);
        this->repaint();
        x->F++;
        continue;
    }
    if(x->F<10){
         x->move(2,1);
        this->repaint();
        x->F++;
        continue;
    }
    if(x->F<12){
         x->move(4,1);
        this->repaint();
        x->F++;
        continue;
    }
    if(x->F<17){
         x->move(1,1);
        this->repaint();
        x->F++;
        continue;
    }
    if(x->F<21){
         x->move(4,1);
        this->repaint();
        x->F++;
        continue;
    }
    if(x->F<23){
         x->move(2,1);
        this->repaint();
        x->F++;
        continue;
       }
    if(x->F<25){
         x->move(3,1);
        this->repaint();
        x->F++;
        continue;
    }
    if(x->F<28){
         x->move(2,1);
        this->repaint();
        x->F++;
        continue;
    }
    if(x->F<30){
         x->move(4,1);
        this->repaint();
        x->F++;
        continue;
    }
    if(x->F<31){
         x->move(1,1);
        this->repaint();
        x->F++;
        continue;
    }
    if(x->F<33){
         x->move(4,1);
        this->repaint();
        x->F++;
        continue;
    }
    if(x->F<24){
        x->move(4,1);        
        x->F++;            
        this->repaint();
        continue;
    }
    if(x->F<25){
        x->move(4,1);       
        this->repaint();
    }
}
    return;
}

//刷新标签
inline bool MW1::DeductionMoney(int money)
{
    if (this->_money - money < 0) return true; //判断金钱是否足够
    this->_money -= money; //扣除金钱
    moneylable->setText(QString("金钱：%1").arg(this->_money)); //刷新标签文本
    update();
    return false;
}
inline bool MW1::DeductionLife(int life)
{
    if(_life-life>0)return true;
    this->_life -= life; //扣除生命
    lifelable->setText(QString("生命：%1").arg(this->_life)); //刷新标签文本
    update();
    return false;
}

//增加怪兽
void MW1::addmonster()
{
    if(_monsterlist.size()<10){
    int d=rand()%3+1;
    setmonster(d,QPoint(200,-75));
}
}
void MW1::setmonster(int type,QPoint x){
    MyObject *monster=new MyObject(type,x);
    _monsterlist.push_back(monster);
}

//测试按钮，以下内容是不存入QVector里的两个测试按钮
void MW1::setTower(){
    Tower* x=new Tower(1,QPoint(135,75));
    if(_money-x->getMoney()>=0){
    DeductionMoney(x->getMoney());
   _towerlist.push_back(x);
   this->update();}
    else
        delete x;
}

void MW1::setTower_(){
    Tower* x=new Tower(1,QPoint(130,455));
    if(_money-x->getMoney()>=0){
    connect(x,&Button::clicked,x,&Tower::upup);
    DeductionMoney(x->getMoney());
    _towerlist.push_back(x);}
    else
        delete x;
}

void MW1::setTower__(){
    Tower* x=new Tower(1,QPoint(267,75));
    if(_money-x->getMoney()>=0){
    connect(x,&Button::clicked,x,&Tower::upup);
    DeductionMoney(x->getMoney());
    _towerlist.push_back(x);}
    else
        delete x;
}

void MW1::setTower3(){
    Tower* x=new Tower(2,QPoint(135,225));
    if(_money-x->getMoney()>=0){
    connect(x,&Button::clicked,x,&Tower::upup);
    DeductionMoney(x->getMoney());
    _towerlist.push_back(x);}
    else
        delete x;
}

void MW1::setTower4(){
    Tower* x=new Tower(2,QPoint(530,150));
    if(_money-x->getMoney()>=0){
    connect(x,&Button::clicked,x,&Tower::upup);
    DeductionMoney(x->getMoney());
    _towerlist.push_back(x);}
    else
        delete x;
}

void MW1::setTower5(){
    Tower* x=new Tower(1,QPoint(535,375));
    if(_money-x->getMoney()>=0){
    connect(x,&Button::clicked,x,&Tower::upup);
    DeductionMoney(x->getMoney());
    _towerlist.push_back(x);}
    else
        delete x;
}

void MW1::setTower6(){
    Tower* x=new Tower(1,QPoint(267,225));
    if(_money-x->getMoney()>=0){
    connect(x,&Button::clicked,x,&Tower::upup);
    DeductionMoney(x->getMoney());
    _towerlist.push_back(x);}
    else
        delete x;
}

void MW1::setTower7(){
    Tower* x=new Tower(1,QPoint(267,375));
    if(_money-x->getMoney()>=0){
    connect(x,&Button::clicked,x,&Tower::upup);
    DeductionMoney(x->getMoney());
    _towerlist.push_back(x);}
    else
        delete x;
}

void MW1::setTower8(){
    Tower* x=new Tower(2,QPoint(400,150));
    if(_money-x->getMoney()>=0){
    connect(x,&Button::clicked,x,&Tower::upup);
    DeductionMoney(x->getMoney());
    _towerlist.push_back(x);}
    else
        delete x;
}

void MW1::setTower9(){
    Tower* x=new Tower(1,QPoint(400,300));
    if(_money-x->getMoney()>=0){
    connect(x,&Button::clicked,x,&Tower::upup);
    DeductionMoney(x->getMoney());
    _towerlist.push_back(x);}
    else
        delete x;
}

void MW1::setTower10(){
    Tower* x=new Tower(2,QPoint(400,450));
    if(_money-x->getMoney()>=0){
    connect(x,&Button::clicked,x,&Tower::upup);
    DeductionMoney(x->getMoney());
    _towerlist.push_back(x);}
    else
        delete x;
}

void MW1::innitBtn(){
    Button *x =new Button("://pics/setTower.png",QPoint(130,455),1);
    x->setParent(this);
    x->move(130,455);
    connect(x,&Button::clicked,this,&MW1::setTower_);
    connect(x,&Button::released,x,&Button::hide);

    Button *bt1 =new Button("://pics/setTower.png",QPoint(135,75),1);
    bt1->setParent(this);
    bt1->move(135,75);
    connect(bt1,&Button::clicked,this,&MW1::setTower);
    connect(bt1,&Button::released,bt1,&Button::hide);

    Button *bt =new Button("://pics/setTower.png",QPoint(267,75),1);
    bt->setParent(this);
    bt->move(267,75);
    connect(bt,&Button::clicked,this,&MW1::setTower__);
    connect(bt,&Button::released,bt,&Button::hide);

    Button *bt6 =new Button("://pics/setTower.png",QPoint(267,225),1);
    bt6->setParent(this);
    bt6->move(267,225);
    connect(bt6,&Button::clicked,this,&MW1::setTower6);
    connect(bt6,&Button::released,bt6,&Button::hide);

    Button *bt7 =new Button("://pics/setTower.png",QPoint(267,375),1);
    bt7->setParent(this);
    bt7->move(267,375);
    connect(bt7,&Button::clicked,this,&MW1::setTower7);
    connect(bt7,&Button::released,bt7,&Button::hide);

    Button *bt8 =new Button("://pics/setTower2.png",QPoint(400,150),2);
    bt8->setParent(this);
    bt8->move(400,150);
    connect(bt8,&Button::clicked,this,&MW1::setTower8);
    connect(bt8,&Button::released,bt8,&Button::hide);

    Button *bt9 =new Button("://pics/setTower.png",QPoint(400,300),1);
    bt9->setParent(this);
    bt9->move(400,300);
    connect(bt9,&Button::clicked,this,&MW1::setTower9);
    connect(bt9,&Button::released,bt9,&Button::hide);

    Button *bt10 =new Button("://pics/setTower2.png",QPoint(400,450),2);
    bt10->setParent(this);
    bt10->move(400,450);
    connect(bt10,&Button::clicked,this,&MW1::setTower10);
    connect(bt10,&Button::released,bt10,&Button::hide);

    Button *bt3 =new Button("://pics/setTower2.png",QPoint(135,225),2);
    bt3->setParent(this);
    bt3->move(135,225);
    connect(bt3,&Button::clicked,this,&MW1::setTower3);
    connect(bt3,&Button::released,bt3,&Button::hide);

    Button *bt4 =new Button("://pics/setTower2.png",QPoint(530,150),2);
    bt4->setParent(this);
    bt4->move(530,150);
    connect(bt4,&Button::clicked,this,&MW1::setTower4);
    connect(bt4,&Button::released,bt4,&Button::hide);

    Button *bt5 =new Button("://pics/setTower.png",QPoint(535,375),1);
    bt5->setParent(this);
    bt5->move(535,375);
    connect(bt5,&Button::clicked,this,&MW1::setTower5);
    connect(bt5,&Button::released,bt5,&Button::hide);
}

//添加子弹进入qvector
void MW1::addBullet(QPoint start,QPoint end){
    Bullet* x=new Bullet(start,end);
    _bulletlist.push_back(x);
    update();
}

void MW1::addplosion(QPoint position){
    Explosion* x=new Explosion(position);
    _plosionlist.push_back(x);
    update();
}

//更新界面
void MW1::updateScreen(){
    foreach (Bullet* x, _bulletlist) {
        x->move();
    }
    update();
}

//子弹动画
void MW1::bulletadd(){
    foreach (Tower* defei, _towerlist) {
        QPoint _st=QPoint(defei->getPos().x()+30,defei->getPos().y()+35);
        int n=_monsterlist.size();
        if(defei->type==2){
            for(int i=n-1;i>=0;i--){
                double dis=GetDistance(_monsterlist.at(i)->GetX()+30,_monsterlist.at(i)->GetY()+35,_st.x(),_st.y());
                if(dis<defei->getRange()&&_plosionlist.size()<=3){
                    addplosion(_monsterlist.at(i)->getNow());
                }
            }
        }
        else{
    for(int i=n-1;i>=0;i--){
        double dis=GetDistance(_monsterlist.at(i)->GetX()+30,_monsterlist.at(i)->GetY()+35,_st.x(),_st.y());
        if(dis<defei->getRange()){
        addBullet(_st,_monsterlist.at(i)->getNow());
        }
    }
        }
    }
}

//判断出界或击中删除子弹
void MW1::deletBullet(){
    foreach (Bullet* x, _bulletlist) {
        double y=GetDistance(x->getPosnow().x(),x->getPosnow().y(),x->getPosStart().x(),x->getPosStart().y());
        if(x->getPosnow()==x->getPosend()||y>125){
            _bulletlist.removeOne(x);
            update();
        }
    }
}

//怪兽减血
void MW1::attacked(){
    int n=_monsterlist.size();
    for(int i=n-1;i>=0;i--){        
            if(_monsterlist.at(i)->GetHealth()<0)
            {
             _monsterlist.remove(i);
             DeductionMoney(-_monsterlist.at(i)->Getmny());
             update();
            }
            foreach (Bullet* x, _bulletlist) {
            double dis=GetDistance(_monsterlist.at(i)->getNow().x(),_monsterlist.at(i)->getNow().y(),x->getPosnow().x()+30,x->getPosnow().y()+35);           
            if(dis<30){
                _bulletlist.removeOne(x);
                _monsterlist.at(i)->Getattacked(20);
                update();
            }
            }
        foreach(Explosion* y,_plosionlist){
            if(_monsterlist.at(i)->getNow()==y->getPos()){
                _plosionlist.removeOne(y);
                delete y;
                _monsterlist.at(i)->Getattacked(80);
                update();
            }
        }
     if(_monsterlist.at(i)->getNow()==QPoint(720,375)){
        _life=_life-15;
        _monsterlist.remove(i);
        update();
    }
    }
}
