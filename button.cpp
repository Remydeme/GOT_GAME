#include "button.h"

#include <QGraphicsTextItem>
#include <QBrush>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    int xPos = static_cast<int>(rect().width()/2 - text->boundingRect().width()/2);
    int yPos = static_cast<int>(rect().height()/2 - text->boundingRect().height()/2);
    text->setPos(xPos,yPos);
    // allow responding to hover events
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (event){
        emit clicked();
    }
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if (event){
        // change color to cyan
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::cyan);
        setBrush(brush);
    }

}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    if (event){
        // change color to dark cyan
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkCyan);
        setBrush(brush);
    }
}
