#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Avion.h"
#include "gamescene.h"
#include <QObject>


class GameManager : public QObject
{

    Q_OBJECT
public:

    enum enemie : int
    {
        MOVE_UPDATE_NOVICE = 10,
        MOVE_UPDATE_MEDIUM = 5,
        MOVE_UPDATE_HARD = 2,
        MOVE_UPDATE_INSANE = 1,
    };


    GameManager();

    // Value for timer timeout()  function
    // by reducing this value we increase the speed of the enemie



    // show the view
    void show();
    // create enemie

    void delay();
    // change the speed

    // change the color

    // handle the score

    // handle the level
public slots:

    // add new enemie
    void addEnemie();

    // add Mana
    void addMana();




private:

   Avion *player_ = nullptr;
   GameScene *scene_ = nullptr;
   QGraphicsView *view_ = nullptr;
private:

   bool gameOver_ = false;
   bool level_ = enemie::MOVE_UPDATE_INSANE;
};

#endif // GAMEMANAGER_H
