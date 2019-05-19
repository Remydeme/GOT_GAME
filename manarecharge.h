#ifndef MANARECHARGE_H
#define MANARECHARGE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QObject>

#include "Avion.h"


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
