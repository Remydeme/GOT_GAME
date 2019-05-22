#ifndef MANARECHARGE_H
#define MANARECHARGE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QObject>

#include "Avion.h"

#define MANA_RECHARGE_IMAGE_PATH ":/images/Spaceship-shooter-environment/spritesheets/power-up.png"

class ManaRecharge : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    public:

        ManaRecharge(QGraphicsScene *scene);

        ~ManaRecharge() = default;

    public slots:

        void move();


    private :

        QGraphicsScene * scene_ = nullptr;
    };


#endif // MANARECHARGE_H
