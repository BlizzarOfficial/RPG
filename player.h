#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include "abilitytrainer.h"

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    int pressedKey;
    int mCurrentFrame = 0;
    int move = 0;
    int SPEED = 5;
    abilityTrainer * trainer;
    bool collide = false;

   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:

    void nextFrame();


private:
    QRectF boundingRect() const;
    QPainterPath shape() const;
    QPixmap mPixmap;
    QPixmap mWalkPixmap;


};

#endif // PLAYER_H
