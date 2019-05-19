#include "bullet.h"
#include "Avion.h"
#include <QTimer>
#include <QGraphicsScene>
#include "enemie.h"
#include <QPixmap>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>

Bullet::Bullet(QGraphicsScene *scene) : QObject() , QGraphicsPixmapItem (){

    this->scene_ = scene;
    this->setPixmap(QPixmap("/Users/remy.d.w/project/GOT/ressources/Spaceship-shooter-environment/spritesheets/laser-bolts.png"));

    // connect
    QTimer *timer = new QTimer();


    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(3);
}


void delay()
{
        QTime dieTime= QTime::currentTime().addSecs(1);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
}

void Bullet::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();


    for (int i = 0, number_colliders = colliding_items.size(); i < number_colliders ; i++){

        if (typeid(*(colliding_items[i])) == typeid(Enemie)){

            Enemie *enemie = static_cast<Enemie *>(colliding_items[i]);
            enemie->setPixmap(QPixmap("/Users/remy.d.w/project/GOT/ressources/Spaceship-shooter-environment/spritesheets/explosion.png"));
            // wait one seconde before removing the items
            // remove the enemie
            scene_->removeItem(colliding_items[i]);
            // remove the bullet
            scene_->removeItem(this);

            // delete from the memory
            delete this;
            delete colliding_items[i];
            return;
        }
    }

    setPos(x(), y() - 10);

    if (pos().y() < 0){
        this->scene_->removeItem(this);
        delete this;
    }
}
