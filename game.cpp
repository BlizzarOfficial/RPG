#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QMediaPlaylist>

Game::Game(QWidget *parent){
    // create the scene
    int width = 960;
    int height = 544;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,width,height); // make the scene 800x600 instead of infinity by infinity (default)

    QImage background = QImage(":/img/background.png");
    setBackgroundBrush(QBrush(background.scaled(width,height+40,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width,height);
    trainer = new abilityTrainer();
    trainer->setPos(600,410);
    scene->addItem(trainer);
    // create the player
    player = new Player();
     // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,200); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    // add the player to the scene
    scene->addItem(player);


    //schrank (links rechts | oben unten | breite | höhe)
    scene->addRect(160,70,130,90,QPen(Qt::NoPen));
    //Kiste
    scene->addRect(125,170,25,50,QPen(Qt::NoPen));
    // Händler
    scene->addRect(125,360,220,150,QPen(Qt::NoPen));
    //Essenstisch
    scene->addRect(350,70,160,110,QPen(Qt::NoPen));
    //Holzschrank
    scene->addRect(315,70,20,170,QPen(Qt::NoPen));
    //rezeption
    scene->addRect(530,125,300,110,QPen(Qt::NoPen));
    // Holzkisten
    scene->addRect(780,385,10,40,QPen(Qt::NoPen));
    scene->addRect(720,440,50,5,QPen(Qt::NoPen));
    scene->addRect(765,430,30,15,QPen(Qt::NoPen));
    // Trainer
    scene->addRect(590,430,30,15,QPen(Qt::NoPen));
    scene->addRect(600,415,48,40,QPen(Qt::NoPen));



    // spawn enemies
    QTimer * timer = new QTimer();
    timer->start(2000);

    //Play BG music
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer * bgsound = new QMediaPlayer();
    bgsound->setPlaylist(playlist);

    bgsound->play();
    show();
}
