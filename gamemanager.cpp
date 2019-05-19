#include "gamemanager.h"
#include "enemie.h"
#include "Avion.h"
#include "gamescene.h"
#include "manarecharge.h"

#include <QTime>
#include <QEventLoop>
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <array>

GameManager::GameManager() : QObject() {
    this->scene_ = new GameScene();

    this->view_ = new QGraphicsView(scene_);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    view_->setFixedSize(1440, 700);
    view_->setBackgroundBrush(QBrush(QImage("/Users/remy.d.w/project/GOT/ressources/Spaceship-shooter-environment/back.png")));


    this->player_ = new Avion(scene_);

    player_->setFlag(QGraphicsItem::ItemIsFocusable);

    player_->setFocus();


    scene_->addItem(player_);

    scene_->setSceneRect(0, 0, 1440, 700);

    player_->setPos(scene_->width()/2, scene_->height() - 100 - 10);




    // add enemy to the scene


}



void GameManager::show(){
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(addEnemie()));
    timer->start(350);

    QTimer * timerMana = new QTimer();
    connect(timerMana, SIGNAL(timeout()), this, SLOT(addMana()));
    timerMana->start(400);
    this->view_->show();
}

void GameManager::addEnemie()
{
    std::array<std::string, 3> enemy_type = {"/Users/remy.d.w/project/GOT/ressources/Spaceship-shooter-environment/spritesheets/enemy-big.png",
                        "/Users/remy.d.w/project/GOT/ressources/Spaceship-shooter-environment/spritesheets/enemy-medium.png",
                        "/Users/remy.d.w/project/GOT/ressources/Spaceship-shooter-environment/spritesheets/enemy-small.png"};
    unsigned long enemy_index = random() % 3;
    Enemie *new_enemie = new Enemie(this->scene_, this->level_, enemy_type.at(enemy_index));
    int rand_x = random() % static_cast<int>(scene_->width());
    new_enemie->setPos(rand_x, 1);
    this->scene_->addItem(new_enemie);
}

void GameManager::addMana()
{
    ManaRecharge *new_mana = new ManaRecharge(this->scene_);
    int rand_x = random() % static_cast<int>(scene_->width());
    new_mana->setPos(rand_x, 1);
    this->scene_->addItem(new_mana);
}



void GameManager::delay()
{
        QTime dieTime= QTime::currentTime().addSecs(1);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 5);
}




