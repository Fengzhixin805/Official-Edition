#include "tower.h"

Tower::Tower()
{

}

Tower::Tower(QPoint pos,string tp):  _hasTower(false) {
    this->setPos(pos);
    this->initObj(tp);
}

void Tower::setPower(int rg,int dmg,int rt){
    this->_damage=dmg;
    this->_range=rg;
    this->_rate=rt;
}

void Tower:: draw(QPainter *painter){

    painter->save();
    painter->setPen(Qt::white);
    // 绘制攻击范围
    painter->drawEllipse(this->getPos(), this->getRange(), this->getRange());

    // 绘制偏转坐标,由中心+偏移=左上
    // 尺寸大小派上用场了,当然也可以直接获取图片大小,是一样的
    static const QPoint offsetPoint(65 / 2, 70 / 2);
    // 绘制炮塔并选择炮塔
    // 这里将坐标原点移到m_pos,绘制的适合,就要加上那个偏移点到左上角
    painter->translate(this->getPos());
    painter->drawPixmap(offsetPoint,this->getObjPath() );
    painter->restore();
}
