#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "gamemanager.h"


int main(int argc, char *argv[]){

    QApplication app(argc,argv);
    GameManager::instance().displayMainMenu();
    GameManager::instance().show();
    return app.exec();
}
