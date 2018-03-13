#include "abilitytrainer.h"
#include <QPixmap>
#include <QPainter>

abilityTrainer::abilityTrainer(QGraphicsItem* parent){

    mWalkPixmap = QPixmap(":/img/skill.png");
    mPixmap = mWalkPixmap;


}

void abilityTrainer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0, mPixmap, mCurrentFrame, 50, 45, 50);
}
