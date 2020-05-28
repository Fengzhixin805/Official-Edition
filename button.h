#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPushButton>
#include"rpgobj.h"

class Button : public QPushButton
{
    Q_OBJECT
public:
   Button(QString x);
   void mouseMoveEvent(QMouseEvent *event);         // 鼠标移动事件
signals:

public slots:
};

#endif // BUTTON_H
