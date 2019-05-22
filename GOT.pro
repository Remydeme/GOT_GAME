#-------------------------------------------------
#
# Project created by QtCreator 2019-05-16T17:17:11
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GOT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    avion.cpp \
    bullet.cpp \
    button.cpp \
    enemie.cpp \
    gamemanager.cpp \
    gamescene.cpp \
    life.cpp \
    main.cpp \
    manarecharge.cpp \
    manatext.cpp \
    score.cpp

HEADERS += \
    Avion.h \
    avion.h \
    bullet.h \
    button.h \
    enemie.h \
    gamemanager.h \
    gamescene.h \
    life.h \
    main.h \
    manarecharge.h \
    manatext.h \
    score.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../Music/iTunes/iTunes Media/Music/Unknown Artist/Unknown Album/auloster.mp3 \
    ../../Music/iTunes/iTunes Media/Music/Unknown Artist/Unknown Album/auloster.mp3 \
    ressources/Spaceship-shooter-environment/PSD/layered.psd \
    ressources/Spaceship-shooter-environment/back.png \
    ressources/Spaceship-shooter-environment/background.jpg \
    ressources/Spaceship-shooter-environment/background.png \
    ressources/Spaceship-shooter-environment/background1.png \
    ressources/Spaceship-shooter-environment/backgrounds/clouds-transparent.png \
    ressources/Spaceship-shooter-environment/backgrounds/clouds.png \
    ressources/Spaceship-shooter-environment/backgrounds/desert-backgorund.png \
    ressources/Spaceship-shooter-environment/readme.txt \
    ressources/Spaceship-shooter-environment/spritesheets/enemy-big.png \
    ressources/Spaceship-shooter-environment/spritesheets/enemy-medium.png \
    ressources/Spaceship-shooter-environment/spritesheets/enemy-small.png \
    ressources/Spaceship-shooter-environment/spritesheets/explosion.png \
    ressources/Spaceship-shooter-environment/spritesheets/laser-bolts.png \
    ressources/Spaceship-shooter-environment/spritesheets/power-up.png \
    ressources/Spaceship-shooter-environment/spritesheets/ship.png \
    ressources/free_plane_sprite/png/BG.png \
    ressources/free_plane_sprite/png/Bullet/Bullet (1).png \
    ressources/free_plane_sprite/png/Bullet/Bullet (2).png \
    ressources/free_plane_sprite/png/Bullet/Bullet (2).png \
    ressources/free_plane_sprite/png/Bullet/Bullet (2).png \
    ressources/free_plane_sprite/png/Bullet/Bullet (3).png \
    ressources/free_plane_sprite/png/Bullet/Bullet (3).png \
    ressources/free_plane_sprite/png/Bullet/Bullet (3).png \
    ressources/free_plane_sprite/png/Bullet/Bullet (4).png \
    ressources/free_plane_sprite/png/Bullet/Bullet (4).png \
    ressources/free_plane_sprite/png/Bullet/Bullet (4).png \
    ressources/free_plane_sprite/png/Bullet/Bullet (5).png \
    ressources/free_plane_sprite/png/Bullet/Bullet (5).png \
    ressources/free_plane_sprite/png/Bullet/Bullet (5).png \
    ressources/free_plane_sprite/png/Bullet/Bullet1.png \
    ressources/free_plane_sprite/png/Plane/Dead (1).png \
    ressources/free_plane_sprite/png/Plane/Dead.png \
    ressources/free_plane_sprite/png/Plane/Fly (1).png \
    ressources/free_plane_sprite/png/Plane/Fly (2).png \
    ressources/free_plane_sprite/png/Plane/Fly (2).png \
    ressources/free_plane_sprite/png/Plane/Fly (2).png \
    ressources/free_plane_sprite/png/Plane/Fly (2).png \
    ressources/free_plane_sprite/png/Plane/Fly.png \
    ressources/free_plane_sprite/png/Plane/Shoot (1).png \
    ressources/free_plane_sprite/png/Plane/Shoot (1).png \
    ressources/free_plane_sprite/png/Plane/Shoot (2).png \
    ressources/free_plane_sprite/png/Plane/Shoot (3).png \
    ressources/free_plane_sprite/png/Plane/Shoot (3).png \
    ressources/free_plane_sprite/png/Plane/Shoot (3).png \
    ressources/free_plane_sprite/png/Plane/Shoot (4).png \
    ressources/free_plane_sprite/png/Plane/Shoot (4).png \
    ressources/free_plane_sprite/png/Plane/Shoot (4).png \
    ressources/free_plane_sprite/png/Plane/Shoot (5).png \
    ressources/free_plane_sprite/png/Plane/Shoot (5).png \
    ressources/free_plane_sprite/png/Plane/Shoot (5).png \
    ressources/free_plane_sprite/png/Plane/Shoot.png \
    ressources/free_plane_sprite/png/Plane/Shoot2.png \
    ressources/free_plane_sprite/vector/BG.ai \
    ressources/free_plane_sprite/vector/BG.svg \
    ressources/free_plane_sprite/vector/Char.ai \
    ressources/free_plane_sprite/vector/Char.svg \
    ressources/sounds/alien-gun.wav \
    ressources/sounds/auloster.mp3 \
    ressources/sounds/canvasbusinessModel - copie 3 copy.key \
    ressources/sounds/gun.wav

RESOURCES += \
    ressources/res.qrc
