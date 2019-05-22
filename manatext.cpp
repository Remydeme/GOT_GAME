#include "manatext.h"

#include <QFont>


ManaText::ManaText(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    setPlainText("Mana : " + QString::number(this->score_));
    setDefaultTextColor(Qt::white);
    setFont(QFont("Times", 24));
}

void ManaText::increaseScore(int manaRecharge)
{
    this->score_ += manaRecharge;
    setPlainText("Mana : " + QString::number(this->score_));
}

void ManaText::decreaseScore(int shootCost)
{
    this->score_ -= shootCost;
    setPlainText("Mana : " + QString::number(this->score_));
}

void ManaText::setMana(int mana){
    this->score_ = mana;
}
