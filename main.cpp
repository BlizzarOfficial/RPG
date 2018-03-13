#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include "menu.h"
#include "game.h"
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <iostream>
#include <QtDebug>
#include "login.h"
using namespace std;
/*

  RPG Game by Stephan Dautzenberg

  Version 0.4
*/

Game * game;
Menu * menu;
Login * login;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    QString servername = "localhost";
    QString dbname = "db_rpg";
    QString dbuser = "root";
    QString dbpassword = "";

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName(servername);
    db.setUserName(dbuser);
    db.setPassword(dbpassword);
    db.setDatabaseName(dbname);

    if(db.open()){

        qDebug() << "Brush";
    }
    else{
        qDebug() << "hurensohn";
    }



    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/img/splash.png"));
    splash->show();

    menu = new Menu();
    menu->show();
    login = new Login();
    login->show();
    //game = new Game();
    //game->show();

   QTimer::singleShot(40,splash,SLOT(close()));
   QTimer::singleShot(40,menu,SLOT(show()));

    return a.exec();

}
