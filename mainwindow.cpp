#include "mainwindow.h"
#include "mw1.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPushButton>
#include <QPixmap>
#include "button.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(800,600);
    ui->setupUi(this);

    Button1 *bt =new Button1("://pics/action.png");
    bt->setParent(this);
    bt->move(300,350);
    MW1 *map2 =new MW1;
    connect(bt,&QPushButton::clicked,this,[=](){
        this->close();
        map2->show();
    });
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/pics/startwindow.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}

Button1::Button1(QString x): QPushButton(0){
    QPixmap pixmap(x);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border.Qpx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}
