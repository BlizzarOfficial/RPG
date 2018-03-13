#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QLabel>
#include <QPainter>
#include <QList>
#include "abilitytrainer.h"
#include <QDebug>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    mWalkPixmap = QPixmap(":/img/player.png");
    mPixmap = mWalkPixmap;
}
QRectF Player::boundingRect() const{
    //Größe Charackter umriss
    return QRectF(0,0,39,39);
}
QPainterPath Player::shape() const
{
QPainterPath path;
path.addEllipse(boundingRect());
return path;
}
void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right

    if (event->key() == Qt::Key_Left){
        if (pos().x() > 120)
        setPos(x()- SPEED ,y());
        move = 2;
        nextFrame();

        // Check ob Player an Wand stoßt
        if(!scene()->collidingItems(this).isEmpty()){
            this->setX(this->x()+5);
        }

    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() < 810)
        setPos(x()+ SPEED,y());
        move = 3;
        nextFrame();
        if(!scene()->collidingItems(this).isEmpty()){
            this->setX(this->x()-5);
        }

    }
    else if(event->key() == Qt::Key_Up){
        // Check ob player am Rand
        if(pos().y() > 120)
        {
        setPos(x(),y()- SPEED);

        }
        move = 0;
        nextFrame();
        if(!scene()->collidingItems(this).isEmpty()){
            this->setY(this->y()+5);
        }

    }
    else if(event->key() == Qt::Key_Down){
         // Check ob player am Rand
        if(pos().y() < 443)
        {
        setPos(x(),y()+SPEED);

        }
        move = 1;
        nextFrame();
        if(!scene()->collidingItems(this).isEmpty()){
            this->setY(this->y()-5);
        }

    }
    // Talk with Space
    else if (event->key() == Qt::Key_Space){
        if (pos().x() < 1024)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_C){

    }
    scene()->invalidate();
}

void Player::nextFrame(){
    mCurrentFrame += 32;
    if (mCurrentFrame >= 96 ) {
        mCurrentFrame = 0;
    }
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    if(move == 0)
    {
        // Erste Zahl: Höhe
        // Zweite Zahl: Länge
        //Dritte Zahl: gesamtgröße
        painter->drawPixmap(0,0, mPixmap, mCurrentFrame, 0, 39, 32);

    }
    else if(move == 1)
    {
        painter->drawPixmap(0,0, mPixmap, mCurrentFrame,65, 39, 32);

    }
    else if(move == 2)
    {
        painter->drawPixmap(0,0, mPixmap, mCurrentFrame, 32, 39, 32);

    }
    else if(move == 3)
    {
        painter->drawPixmap(0,0, mPixmap, mCurrentFrame, 96, 39, 32);

    }
  setTransformOriginPoint(boundingRect().center());
  Q_UNUSED(widget);
  Q_UNUSED(option);


}




