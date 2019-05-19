#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "gamemanager.h"
int main(int argc, char *argv[]){

    QApplication app(argc,argv);
    GameManager *manager = new GameManager();
    manager->show();
    return app.exec();
}
