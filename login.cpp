#include "login.h"
#include <QPixmap>

Login::Login(QWidget *parent)
    {

    int width = 960;
    int height = 544;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,width,height);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    setFixedSize(width,height);

    QImage background = QImage(":/img/login.png");
    setScene(scene);
    setBackgroundBrush(QBrush(background.scaled(width,height+40,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

    // Login Button
    Button* login = new Button (QString("Login"));

    int btn_start_xPos = this->width()/2 - login->boundingRect().width()/2 -150;
    int btn_start_yPos = 410;
    login->setPos(btn_start_xPos,btn_start_yPos);

    connect(login,SIGNAL(clicked()), this, SLOT(checkLogin()));
    scene->addItem(login);

    // Register Button
    Button* reg = new Button (QString("Register"));

    int btn_reg_xPos = this->width()/2 - reg->boundingRect().width()/2 +150;
    int btn_reg_yPos = 410;cd
    reg->setPos(btn_reg_xPos,btn_reg_yPos);

    connect(reg,SIGNAL(clicked()), this, SLOT(openRegister()));
    scene->addItem(reg);
}

void Login::checkLogin()
{


}

void Login::openRegister()
{
    QMessageBox::information(
        this,
        tr("RPG Game by Stephan Dautzenberg"),
        tr("This Feature Comming Soon.") );
}


