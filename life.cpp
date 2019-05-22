#include "life.h"


#include <QFont>

Life::Life(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    setPlainText("Life : " + QString::number(this->score_));
    setDefaultTextColor(Qt::green);
    setFont(QFont("Times", 24));
}

void Life::increaseScore()
{
    this->score_ += 1;
    setPlainText("Life : " + QString::number(this->score_));
}

void Life::decreaseScore()
{
    this->score_ -= 1;
    setPlainText("Life : " + QString::number(this->score_));
}

void Life::setLife(int life)
{
    this->score_ = life;
    setPlainText("Life : " + QString::number(this->score_));
}
