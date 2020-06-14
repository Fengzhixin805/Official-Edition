#include "world.h"
#include"button.h"
#include<QMediaPlayer>
#include<QLabel>

void World::show(QPainter * painter){
    int n = this->_monsterlist.size();
    for (int i=0;i<n;i++){
        this->_monsterlist[i]->draw(painter);
    }
    return;
}


