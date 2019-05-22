#ifndef BULLET_H
#define BULLET_H



#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QObject>
#include <QMediaPlayer>
#include "Avion.h"
#include "gamemanager.h"


#define BULLET_IMAGE_PATH ":/images/Spaceship-shooter-environment/spritesheets/laser-bolts.png"

#define BULLET_SOUND_PATH "qrc:/sounds/alien-gun.wav"

class Bullet : public QObject, public QGraphicsPixmapItem {

Q_OBJECT

public:

    Bullet(QGraphicsScene *scene);
    ~Bullet() = default;
    void play();
    QMediaPlayer& getSound();


public slots:

    void move();


private :

    QGraphicsScene * scene_ = nullptr;
    QMediaPlayer* sound_ = nullptr;
};

#endif // BULLET_H
