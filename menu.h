#ifndef MENU_H
#define MENU_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "game.h"
#include "button.h"
#include <QObject>
#include <QPushButton>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QPixmap>
#include <QPainter>
#include "image.h"


class Menu: public QGraphicsView{
 Q_OBJECT
public: Menu(QWidget * parent=0);
    QGraphicsScene * scene;
    QPushButton *m_button;
    Game * game;
    QMediaPlayer * bgsound;
    Image* logo;
    bool loggedin = false;

public slots:
    void start();
    void settings();

};
#endif // MENU_H
