#include "mw1.h"
#include "ui_mw1.h"
#include"tower.h"
#include"button.h"
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
int M=0;
double GetDistance(int X1,int Y1,int X2,int Y2){
    return abs(sqrt((((X1) - (X2)) * ((X1) - (X2))) + (((Y1) - (Y2)) * ((Y1) - (Y2)))));
}

MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
   // setFixedSize(800, 600);
    ui->setupUi(this);
    innitBtns();
    innitBtn();
    drawlabel();

    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc://sounds/hdl.mp3"));
    player->setVolume(30);
    player->play();



    timer2 = new QTimer(this);      //用于插入怪物定时器
    connect(timer2,SIGNAL(timeout()),this,SLOT(addmonster()));
    timer2->start(5000);
    timer2->setInterval(1500);

    timer1=new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(Move()));
    //Move()为自定义槽函数
    timer1->start(5000);
    timer1->setInterval(1000);     //时间可设置难度

    QTimer* updt2=new QTimer(this);
    connect(updt2,SIGNAL(timeout()),this,SLOT(bulletadd()));
    updt2->start(800);
    //子弹运动
    QTimer* updt=new QTimer(this);
    connect(updt,&QTimer::timeout,this,&MW1::updateScreen);
    connect(updt,SIGNAL(timeout()),this,SLOT(deletBullet()));
    updt->start(250);
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
         //就是和这里的范围圈怎么调整都不准确！！
         painter->drawEllipse(defei->getPos().x()-defei->getRange()*2/5, defei->getPos().y()-defei->getRange()*2/5,defei->getRange(), defei->getRange());
        //画出所有防御塔子弹
      /*   foreach (BulletStr* bulli, defei->GetBulletVec()) {
         painter->drawPixmap(bulli->coor.x, bulli->coor.y, defei->GetBulletWidth(), defei->GetBulletHeight(),QPixmap(defei->GetBulletPath()));
         }*/
    }
}

//绘画事件
void MW1::paintEvent(QPaintEvent *){
 /*//输赢界面
    if (m_gameEnd ||m_gameWin)
    {
        QString text = m_gameEnd ? "YOU LOST!!!" : "YOU WIN!!!";
        QPainter painter(this);
        painter.setPen(QPen(Qt::red));
        painter.drawText(rect(), Qt::AlignCenter, text);
        return;
    }*/
    QPainter painter(this);
    QPixmap pixmap("://pics/map2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    QPixmap renyu("://pics/renyu.png");
    painter.drawPixmap(700,325,100,125,renyu);
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
        DeductionLife(x->GetPower());
        _monsterlist.removeOne(x);     //但删除失败
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
    if(_life-life<0)return true;
    this->_money -= life; //扣除生命
    lifelable->setText(QString("生命：%1").arg(this->_life)); //刷新标签文本
    update();
    return false;
}

//增加怪兽
void MW1::addmonster()
{
    if(_monsterlist.size()<6){
    int d=rand()%2+1;
    setmonster(d,QPoint(200,-75));
}
}
void MW1::setmonster(int type,QPoint x){
    MyObject *monster=new MyObject(type,x);
    _monsterlist.push_back(monster);
}

//加载放塔键
void MW1::innitBtns(){

    for(int i=0;i<3;i++){
    Button *bt =new Button("://pics/setTower2.png",QPoint(267,75+150*i),2);
    bt->setParent(this);
    bt->move(267,75+150*i);
    _buttonlist.push_back(bt);

    Button *bt2 =new Button("://pics/setTower.png",QPoint(400,150+150*i),1);
    bt2->setParent(this);
    bt2->move(400,150+150*i);    
    _buttonlist.push_back(bt2);
    }

    Button *bt3 =new Button("://pics/setTower2.png",QPoint(135,225),2);
    bt3->setParent(this);
    bt3->move(135,225);
    _buttonlist.push_back(bt3);


    Button *bt4 =new Button("://pics/setTower2.png",QPoint(530,150),2);
    bt4->setParent(this);
    bt4->move(530,150);
    _buttonlist.push_back(bt4);

    Button *bt5 =new Button("://pics/setTower.png",QPoint(535,375),1);
    bt5->setParent(this);
    bt5->move(535,375);
    _buttonlist.push_back(bt5);
}

//测试按钮，以下内容是不存入QVector里的两个测试按钮
void MW1::setTower(){
    Tower* x=new Tower(1,QPoint(135,75));
    connect(x,&Tower::choose_up,this,[=](){
        x->upup();
    });
   _towerlist.push_back(x);
   this->update();
}

void MW1::setTower_(){
    Tower* x=new Tower(1,QPoint(130,455));
    connect(x,&Button::clicked,x,&Tower::upup);
    _towerlist.push_back(x);
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


    foreach (Button *iter, _buttonlist) {
        if((iter)->_type==1){
    connect (iter, &Button::clicked, this ,[=](){
      setTower1((iter)->getPos());
    }) ;
    connect(iter,&Button::released,iter,&Button::hide);
        }
       else{
            connect(iter,&Button::clicked,this,[=](){
                setTower2((iter)->getPos());
            });
            connect(iter,&Button::released,iter,&Button::hide);
    }
    }
}

//放置塔
void MW1::setTower1(QPoint pos){
    Tower* x=new Tower(1,pos);
    _towerlist.push_back(x);
    x->setParent(this);
    DeductionMoney(x->getMoney());
    update();
}
void MW1::setTower2(QPoint pos){
    Tower* x=new Tower(2,pos);
    DeductionMoney(x->getMoney());
    _towerlist.push_back(x);
    x->setParent(this);
    update();
}

//添加子弹进入qvector
void MW1::addBullet(QPoint start,QPoint end,double distance){
    Bullet* x=new Bullet(start,end,distance);
    _bulletlist.push_back(x);
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
        if(defei->type==2){
            continue;
        }
    QPoint _st=QPoint(defei->getPos().x()+30,defei->getPos().y()+35);
    int n=_monsterlist.size();
    for(int i=n-1;i>=0;i--){
        double dis=GetDistance(_monsterlist.at(i)->GetX()+30,_monsterlist.at(i)->GetY()+35,_st.x(),_st.y());
        if(dis<defei->getRange()){
            addBullet(_st,_monsterlist.at(i)->getNow(),dis);
        }
    }
    }
}
//判断出界或击中删除子弹
void MW1::deletBullet(){
    foreach (Bullet* x, _bulletlist) {
        double y=GetDistance(x->getPosnow().x(),x->getPosnow().y(),x->getPosStart().x(),x->getPosStart().y());
        if(x->getPosnow()==x->getPosend()||y>150){
            _bulletlist.removeOne(x);
            update();
        }
    }
}
