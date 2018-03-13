#include "Image.h"
#include <QPixmap>
#include <QPainter>

Image::Image(QGraphicsItem* parent){

    mWalkPixmap = QPixmap(":/img/logomenu.png");
    img = mWalkPixmap;

}

void Image::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0, img, 0, 0, 296, 200);
}
