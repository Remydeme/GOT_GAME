#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include "Avion.h"
#include "gamescene.h"
#include <QObject>
#include "score.h"
#include "life.h"
#include "manatext.h"

#define SMALL_ENEMI ":/images/Spaceship-shooter-environment/spritesheets/enemy-small.png"
#define MEDIUM_ENEMI ":/images/Spaceship-shooter-environment/spritesheets/enemy-medium.png"
#define BIG_ENEMIE ":/images/Spaceship-shooter-environment/spritesheets/enemy-big.png"


#define GAME_SCENE_START_POINT 210
class GameManager : public QObject
{

    Q_OBJECT


    public:

        static GameManager& instance(){
            static GameManager *instance = nullptr;
            if (instance == nullptr){
                instance = new GameManager();
            }
            return *instance;
        }

    private:

        GameManager();

        GameManager(GameManager& ){}


        // create singleton



        ~GameManager() = default;

    public:

        enum enemie : int
        {
            MOVE_UPDATE_NOVICE = 7,
            MOVE_UPDATE_MEDIUM = 4,
            MOVE_UPDATE_HARD = 2,
            MOVE_UPDATE_INSANE = 1,
        };

        enum player : int {
            PLAYER_LIFE = 5,
        };

        // Value for timer timeout()  function
        // by reducing this value we increase the speed of the enemie


        // draw the user main menu
        void displayMainMenu();




    private :

        // delay function
        void delay();



    public:


        // show the scene
        void show();

        // function that build a custom panel
        void drawPanel(int x, int y, int width, int height, QColor color, double opacity=1);


        // draw the game left UI that display the score and all the game informations
        void drawGUI();

        void increaseScore();
        // change the speed

        void decreaseLife();


        // Handle Mana

        void rechargeMana(int manaRecharge);

        void decreaseMana(int shootCost);
        // handle the score


    public slots:

        // add new enemie
        void addEnemie();

        // add Mana
        void addMana();

        //lauch the game
        void start();

        // close the windows game
        void close();


    private:

       Avion *player_ = nullptr;
       GameScene *scene_ = nullptr;
       QGraphicsView *view_ = nullptr;
       QMediaPlayer* music_ = nullptr;

    private:

       ManaText *manaText_ = nullptr;
       Score *score_ = nullptr;
       Life *life_ = nullptr;
       int level_ = enemie::MOVE_UPDATE_INSANE;
       bool gameOver_ = false;
};

#endif // GAMEMANAGER_H
