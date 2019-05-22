#pragma once

#include <QGraphicsRectItem>
#include <QKeyEvent>

#define SHIP_IMAGE_PATH ":/images/Spaceship-shooter-environment/spritesheets/ship.png"

class Avion : public QGraphicsPixmapItem {

    enum move : int32_t {
        JUMP_HIGH = 5,
    };

    enum mana : int {
        MANA_FIRE_COST = 2,
        MANA_RECHARGE = 15,
    };



    public:
        Avion(QGraphicsScene* scene);

        void keyPressEvent(QKeyEvent *event);
        ~Avion() = default;

   public:

        // This function decrease the life of the player when he is hit by an enemie
        void playerHit();

        // state function check if the user is alive
        bool isAlive();

        // this function increse the mana of the avion when it is hit by a mana object
        void playerHitByMana();

        //
        int getMana();



    private:

        int sideMoveSpeed_ = 29;
        int mana_ = 60;
        int life_ = 10;
        int score_ = 0;
        QGraphicsScene * scene_= nullptr;
};
