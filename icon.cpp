#include "icon.h"
#include<iostream>

pair<string,ICON> pairArray[] =
{
    make_pair("setTower",ICON("setTower",70,75,"://pics/setTower.png")),
    make_pair("Tower1",ICON("Tower1",70,75,"://pics/tower1.png")),

};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));


ICON::ICON(string name, int w, int h,QString pix):_pix(pix){
    this->typeName = name;
    this->width = w;
    this->height = h;
}


ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;
    kv = ICON::GAME_ICON_SET.find(type);
    if (kv==ICON::GAME_ICON_SET.end()){

       cout<<"Error: cannot find ICON"<<endl;
       return ICON();
    }
    else{
        return kv->second;
    }
}
