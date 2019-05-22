#include "gamemanager.h"
#include "enemie.h"
#include "Avion.h"
#include "gamescene.h"
#include "manarecharge.h"
#include "button.h"

#include <QTime>
#include <QEventLoop>
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <array>



#include "score.h"



GameManager::GameManager() : QObject() {

    // Create the GAME Scene
    this->scene_ = new GameScene();

    scene_->setSceneRect(0, 0, 1440, 900);



    this->view_ = new QGraphicsView(scene_);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    view_->setFixedSize(1440, 900);
    view_->setBackgroundBrush(QBrush(QImage(":/images/Spaceship-shooter-environment/background.png")));

    // add game Music
    music_ = new QMediaPlayer();

    music_->setMedia(QUrl(":/sounds/auloster.mp3"));

    music_->play();


    // add enemy to the scene
}

void GameManager::displayMainMenu()
{
    // create the title text
        QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("GOT"));
        QFont titleFont("comic sans",50);
        titleText->setFont(titleFont);
        int txPos = static_cast<int>(this->scene_->width()/2 - titleText->boundingRect().width()/2);
        int tyPos = 150;
        titleText->setPos(txPos,tyPos);
        scene_->addItem(titleText);

        // create the play button
        Button* playButton = new Button(QString("Play"));
        int bxPos = static_cast<int>(this->scene_->width()/2 - playButton->boundingRect().width()/2);
        int byPos = 275;
        playButton->setPos(bxPos,byPos);
        connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
        scene_->addItem(playButton);

        // create the quit button
        Button* quitButton = new Button(QString("Quit"));
        int qxPos = static_cast<int>(this->scene_->width()/2 - quitButton->boundingRect().width()/2);
        int qyPos = 350;
        quitButton->setPos(qxPos,qyPos);
        connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
        scene_->addItem(quitButton);
}



void GameManager::start(){

    // clear the scene before staring the game
    scene_->clear();

    // create player

    this->player_ = new Avion(scene_);

    player_->setPos(scene_->width()/2, scene_->height() - 100 - 10);

    player_->setFlag(QGraphicsItem::ItemIsFocusable);

    player_->setFocus();

    scene_->addItem(player_);

    drawGUI();

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(addEnemie()));
    timer->start(200);

    QTimer * timerMana = new QTimer();
    connect(timerMana, SIGNAL(timeout()), this, SLOT(addMana()));
    timerMana->start(400);

}

void GameManager::close()
{
    exit(EXIT_SUCCESS);
}

void GameManager::addEnemie()
{
    std::array<std::string, 3> enemy_type = {
                                                BIG_ENEMIE,
                                                MEDIUM_ENEMI,
                                                SMALL_ENEMI
                                             };

    unsigned long enemy_index =  random() % 3;
    Enemie *new_enemie = new Enemie(this->scene_, this->level_, enemy_type.at(enemy_index));
    int rand_x = GAME_SCENE_START_POINT + (random() % static_cast<int>(scene_->width() - GAME_SCENE_START_POINT));
    new_enemie->setPos(rand_x, 1);
    this->scene_->addItem(new_enemie);
}

void GameManager::addMana()
{
    ManaRecharge *new_mana = new ManaRecharge(this->scene_);
    int rand_x = GAME_SCENE_START_POINT + (random() % static_cast<int>(scene_->width() - GAME_SCENE_START_POINT));
    new_mana->setPos(rand_x, 1);
    this->scene_->addItem(new_mana);
}



void GameManager::delay()
{
        QTime dieTime= QTime::currentTime().addSecs(1);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 5);
}

void GameManager::show()
{
    this->view_->show();
}

void GameManager::increaseScore()
{
    score_->increaseScore();
}

void GameManager::decreaseLife()
{
    life_->decreaseScore();
}

void GameManager::rechargeMana(int manaRecharge)
{
    manaText_->increaseScore(manaRecharge);
}

void GameManager::decreaseMana(int shootCost)
{
    manaText_->decreaseScore(shootCost);
}

// panel for game settings
void GameManager::drawPanel(int x, int y, int width, int height, QColor color, double opacity)
{
    QGraphicsRectItem* panel = new QGraphicsRectItem(x, y,width, height);

    QBrush brush;

    brush.setStyle(Qt::SolidPattern);

    brush.setColor(color);

    panel->setBrush(brush);

    panel->setOpacity(opacity);

    scene_->addItem(panel);

}

void GameManager::drawGUI()
{
    drawPanel(0, 0, GAME_SCENE_START_POINT, 990, Qt::black);

    // life
    life_ = new Life();
    life_->setPos(7, 50);
    life_->setLife(player::PLAYER_LIFE);
    this->scene_->addItem(life_);

    // add score and level text
    score_ = new Score();
    score_->setPos(7, 20);
    scene_->addItem(score_);


    // Mana text
    manaText_ = new ManaText();
    manaText_->setPos(7, 80);
    manaText_->setMana(player_->getMana());
    this->scene_->addItem(manaText_);    // add view
}













