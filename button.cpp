#include "button.h"
#include<QPixmap>
#include<QMouseEvent>
#include<QMenu>

Button::Button(QString x): QPushButton(0){
    QPixmap pixmap(x);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border.Qpx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}

void Button::mouseMoveEvent(QMouseEvent *event)
{
    const QRect customBtnRect = this->geometry();
    const QPoint mousePos = event->pos() + customBtnRect.topLeft();

    if (customBtnRect.contains(mousePos))
    {
        if (this->menu())
        {
            this->menu()->popup(this->mapToGlobal(QPoint(0, 0)));
        }
    }
}
