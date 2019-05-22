#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>

class Life : public QGraphicsTextItem
{


public:

    Life(QGraphicsItem *parent = nullptr);

    void increaseScore();
    void decreaseScore();
    void setLife(int life);

private:

    int score_ = 0;
};

#endif // LIFE_H
