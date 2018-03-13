#include "menu.h"
#include <QImage>
#include <QGraphicsTextItem>
#include <game.h>
#include <QDebug>
#include <QRect>
#include <QPoint>
#include <QSize>
#include <QApplication>
#include <QMediaPlaylist>
#include <QPainter>


Menu::Menu(QWidget *parent)
    {

    int width = 960;
    int height = 544;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,width,height);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //logo = new QPixmap(":/img/btn_menu_normal.png");
    //QPixmap logo = QPixmap(":/img/btn_menu_normal.png");

    //QImage background = QImage(":/img/login.png");
    //setScene(scene);
    //  setBackgroundBrush(QBrush(background.scaled(width,height+40,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

    //if(loggedin == true)
    // {
    logo = new Image();
    logo->setPos(this->width()/2,120);
    scene->addItem(logo);

    setFixedSize(width,height);

    QImage background = QImage(":/img/menubg.png");
    setScene(scene);
    setBackgroundBrush(QBrush(background.scaled(width,height+40,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

    //game = new Game();
    //game->show();

    // Play Button
    Button* start = new Button (QString("Play Game"));

    int btn_start_xPos = this->width()/2 - start->boundingRect().width()/2;
    int btn_start_yPos = 230;
    start->setPos(btn_start_xPos,btn_start_yPos);

    connect(start,SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(start);
    // Settings Button

    Button* settings = new Button (QString("Settings"));
    int btn_settings_xPos = this->width()/2 - settings->boundingRect().width()/2;
    int btn_settings_yPos = 320;
    settings->setPos(btn_settings_xPos,btn_settings_yPos);
    connect(settings,SIGNAL(clicked()), this, SLOT(settings()));
    scene->addItem(settings);

    // Quit Button
    Button* quit = new Button (QString("Quit"));
    int btn_quit_xPos = this->width()/2 - quit->boundingRect().width()/2;
    int btn_quit_yPos = 410;
    quit->setPos(btn_quit_xPos,btn_quit_yPos);
    connect(quit,SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quit);

    //Play BG music
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    bgsound = new QMediaPlayer();
    bgsound->setPlaylist(playlist);
    bgsound->play();
   // }
    show();

}

void Menu::start()
{

    bgsound->stop();
    this->close();

    game = new Game();
    game->show();
}

void Menu::settings()
{
    QMessageBox::information(
        this,
        tr("RPG Game by Stephan Dautzenberg"),
        tr("This Feature Comming Soon.") );
}

