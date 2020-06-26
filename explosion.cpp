#include "explosion.h"

void Explosion::show(QPainter *painter){
    painter->drawPixmap(_pos,_pixmap);
}
