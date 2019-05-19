#include "avion.h"
#include "bullet.h"
#include <QDebug>


#include "enemie.h"


Avion::Avion(QGraphicsScene* scene) : QGraphicsPixmapItem ()
{
    this->scene_ = scene;

    this->setPixmap(QPixmap("/Users/remy.d.w/project/GOT/ressources/Spaceship-shooter-environment/spritesheets/ship.png"));
}

void Avion::keyPressEvent(QKeyEvent *event)
{
    // detect a move to the left
    if (event->key() == Qt::Key_Left){
        double x_left = x() - this->sideMoveSpeed_;
        if (x_left > 0){
            setPos(x() - this->sideMoveSpeed_ , y());
        }
        else {
                setPos((this->scene_->width() - this->sideMoveSpeed_ * 0.5) , y());
            }
    }
    // detect a move to the right
   if (event->key() == Qt::Key_Right){
       double x_right = x() + this->sideMoveSpeed_;
       if (x_right < this->scene_->width()){
           setPos(x() + this->sideMoveSpeed_ , y());
       }
       else {
               setPos((0 + this->sideMoveSpeed_ * 0.5) , y());
           }
    }
    if (event->key() == Qt::Key_Space){
        if (mana_ > 0){
            Bullet *bullet = new Bullet(this->scene_);
            bullet->setPos(x() + 10,y());
            //this->collidesWithItem()
            this->scene_->addItem(bullet);
            this->mana_ -= mana::MANA_FIRE_COST;
        }
    }
}

void Avion::playerHit()
{
    this->life_ -= 1;
}

bool Avion::isAlive()
{
    return true;
}

void Avion::playerHitByMana()
{
    this->mana_ += 5;
}

