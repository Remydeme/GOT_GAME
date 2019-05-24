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
            GameManager::instance().decreaseLife();
            Avion * player = static_cast<Avion*>(colliding_items[i]);
            player->playerHit();
            if (player->isAlive() == false){

                QString *text = nullptr;

                int score = GameManager::instance().getScore();

                QString str_score = QString::number(score);

                 if (score > 50){
                    text = new QString("You are not too bad your with your " + QString(str_score) + "  :) !");
                }
                else if (score > 200){
                    text = new QString("Oh! Got damn !! you are good !! Score  " + QString(str_score) + "  ;) !");
                }
                else if (score > 400){
                    text = new QString("A Stark ! take the throne with your " + QString(str_score) + "  O_* !");
                }
                else {
                    text = new QString("Got dammn! It's a realy bad Score  " + QString(str_score) + "  *_* !");
                }
                GameManager::instance().displayGameOverWindow(*text);
                delete player;
                scene_->removeItem(player);
                return;
            }
            scene_->removeItem(this);
            delete this;
        }
    }

    setPos(x(), y() + 5);
    if (pos().y() > this->scene_->height()){
        this->scene_->removeItem(this);
        delete this;
    }
}

