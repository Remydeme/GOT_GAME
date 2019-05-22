#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>

class Score : public QGraphicsTextItem
{


public:
    Score(QGraphicsItem *parent = nullptr);

    void increaseScore();
    void decreaseScore();

private:

    int score_ = 0;
};

#endif // SCORE_H
