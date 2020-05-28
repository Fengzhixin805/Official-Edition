#ifndef ICON_H
#define ICON_H
#include <string>
#include <map>
#include <QString>
using namespace std;

//将一类图标定位到素材图片上的具体区域
class ICON
{
public:

    ICON(){}
    ICON(string name,int w, int h,QString _pix);

    string getTypeName() const{return this->typeName;}
    int getWidth() const{return this->width;}
    int getHeight() const{return this->height;}
    QString getPath() const{return this->_pix;}

    static map<string,ICON> GAME_ICON_SET;
        //确定各类物体子素材图片的位置，高、宽等数据
    static ICON findICON(string type);
        //根据物体类型名找到图标

private:
    string typeName;
    int width, height;
    QString _pix;

};

#endif // ICON_H
