#include "manarecharge.h"
#include <QTimer>

ManaRecharge::ManaRecharge(QGraphicsScene *scene) : QGraphicsPixmapItem ()
{

    this->scene_ = scene;
    this->setPixmap(QPixmap("/Users/remy.d.w/project/GOT/ressources/Spaceship-shooter-environment/spritesheets/power-up.png"));

    // connect
    QTimer *timer = new QTimer();


    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(1);
}

void ManaRecharge::move()
{

    QList<QGraphicsItem *> colliding_items = collidingItems();


    for (int i = 0, number_colliders = colliding_items.size(); i < number_colliders ; i++){

        if (typeid(*(colliding_items[i])) == typeid(Avion)){

            Avion *player = static_cast<Avion*>(colliding_items[i]);
            player->playerHitByMana();
            // remove the bullet
            scene_->removeItem(this);

            // delete from the memory
            delete this;

            return;
        }
    }
    setPos(x(), y() + 5);
    if (pos().y() > this->scene_->height()){
        this->scene_->removeItem(this);
        delete this;
    }
}


