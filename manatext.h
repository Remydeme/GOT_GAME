#ifndef MANATEXT_H
#define MANATEXT_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>

class ManaText : public QGraphicsTextItem
{

public:

    ManaText(QGraphicsItem *parent = nullptr);

    void increaseScore(int manaRecharge);
    void decreaseScore(int shootCost);
    void setMana(int mana);

private:

    int score_ = 0;
};

#endif // MANATEXT_H
