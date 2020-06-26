#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QObject>
#include <QPoint>
#include<QPainter>

class Explosion : public QObject
{
    Q_OBJECT
public:
    Explosion(QPoint showPos):_pixmap(":/pics/explosion_.png"){_pos=showPos;}
    void show(QPainter* painter);
    QPoint getPos(){return _pos;}

private:
    QString _pixmap;
    QPoint _pos;
signals:

public slots:
};

#endif // EXPLOSION_H
