#ifndef ABILITYTRAINER_H
#define ABILITYTRAINER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class abilityTrainer: public QGraphicsPixmapItem{

public:
    abilityTrainer(QGraphicsItem * parent=0);

    int mCurrentFrame = 0;

    QPixmap mPixmap;
    QPixmap mWalkPixmap;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // ABILITYTRAINER_H
