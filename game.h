#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "abilitytrainer.h"

class Game: public QGraphicsView{

public:
    Game(QWidget * parent=0);
    QGraphicsScene * scene;
    Player * player;
    abilityTrainer * trainer;
};
#endif // GAME_H
