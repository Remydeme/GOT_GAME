#ifndef ENEMIE_H
#define ENEMIE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QObject>
#include "Avion.h"
#include "gamemanager.h"

class Enemie : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT



    public:

        Enemie(QGraphicsScene *scene, double update_speed, std::string enemy_type);
        ~Enemie() = default;

    public slots:
        void move();


    private :

        QGraphicsScene * scene_ = nullptr;
    };


#endif // ENEMIE_H
