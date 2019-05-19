#include "enemie.h"
#include "enemie.h"
#include <QTimer>
#include <QGraphicsScene>
#include <random>


Enemie::Enemie(QGraphicsScene *scene, double update_speed, std::string enemy_type) : QObject(), QGraphicsPixmapItem (){

    this->scene_ = scene;
    this->setPixmap(QPixmap(enemy_type.c_str()));

    // connect
    QTimer *timer = new QTimer();


    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    int speed = static_cast<int>(update_speed);

    timer->start(speed);
}



void Enemie::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();


    for (int i = 0, number_colliders = colliding_items.size(); i < number_colliders ; i++){

        if (typeid(*(colliding_items[i])) == typeid(Avion)){

            Avion * player = static_cast<Avion*>(colliding_items[i]);
            player->playerHit();
            if (player->isAlive() == false){
                scene_->removeItem(player);
                scene_->removeItem(this);
                delete player;
                delete this;
                return;
            }

        }
    }

    setPos(x(), y() + 5);
    if (pos().y() > this->scene_->height()){
        this->scene_->removeItem(this);
        delete this;
    }
}

