#include "mw2.h"
#include "ui_mw2.h"


MW2::MW2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW2)
{
    setFixedSize(800, 600);
    ui->setupUi(this);
}

MW2::~MW2()
{
    delete ui;
}

void MW2::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap("://pics/win.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);


}
