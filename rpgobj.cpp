#include "rpgobj.h"
#include "icon.h"
#include <iostream>

void RPGObj::initObj(string type)
{
    //TODO 所支持的对象类型应定义为枚举
    if (type.compare("setTower")==0){
        this->_eatable =false;
    }
    else if (type.compare("Tower")==0){
        this->_eatable = false;
    }
    else{
        //TODO 应由专门的错误日志文件记录
        cout<<"invalid ICON type."<<endl;
        return;
    }
     this->_icon = ICON::findICON(type);
}

void RPGObj::show(QPainter * pa){
    pa->drawPixmap(this->_pos,this->getObjPath());
}



