#ifndef LOGIN_H
#define LOGIN_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "button.h"
#include <QObject>
#include <QPushButton>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QPixmap>
#include <QPainter>
#include "image.h"

class Login: public QGraphicsView{
 Q_OBJECT
public: Login(QWidget * parent=0);
    QGraphicsScene * scene;
    QPushButton *m_button;
    QMediaPlayer * bgsound;
    Image* logo;

public slots:
    void checkLogin();
    void openRegister();

};
#endif // LOGIN_H
