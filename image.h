#ifndef IMAGE_H
#define IMAGE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Image: public QGraphicsPixmapItem{

public:
    Image(QGraphicsItem * parent=0);

    QPixmap img;
    QPixmap mWalkPixmap;


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};


#endif // IMAGE_H
