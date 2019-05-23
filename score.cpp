#include "score.h"

#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    setPlainText("Score : " + QString::number(this->score_));
    setDefaultTextColor(Qt::white);
    setFont(QFont("Times", 24));
}

void Score::increaseScore()
{
    this->score_ += 1;
    setPlainText("Score : " + QString::number(this->score_));
}

void Score::decreaseScore()
{
    this->score_ -= 1;
    setPlainText("Score : " + QString::number(this->score_));
}

void Score::reset(){
    score_ = 0;
}
