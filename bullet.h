#ifndef BULLET_H
#define BULLET_H



#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QObject>

class Bullet : public QObject, public QGraphicsPixmapItem {

Q_OBJECT

public:

    Bullet(QGraphicsScene *scene);
    ~Bullet() = default;


public slots:

    void move();


private :

    QGraphicsScene * scene_ = nullptr;
};

#endif // BULLET_H
