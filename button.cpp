#include "Button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <qDebug>
#include <QPainter>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // draw the rect

    btn_normal = QPixmap(":/img/btn_menu_normal.png");
    btn_hover = QPixmap(":/img/btn_menu_hover.png");
    btn_clicked = QPixmap(":/img/btn_menu_clicked.png");

    text = new QGraphicsTextItem(name,this);
    text->setFont({"Helvetica", 18});
    int xPos = btn_normal.width()/2 - text->boundingRect().width()/2;
    int yPos = btn_normal.height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);


    QPainter painter (&btn_normal);
    setPixmap(btn_normal);

    // draw the text




    // allow responding to hover events
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    setPixmap(btn_clicked);
    emit clicked();

}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    // change color to cyan
    setPixmap(btn_hover);

}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    // change color to dark cyan
    setPixmap(btn_normal);

}
