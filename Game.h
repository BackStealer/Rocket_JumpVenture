#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QUrl>
#include "Soldier.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Soldier * soldier;
    Score * score;
    Health * health;
    QMediaPlaylist * playlist;
    QMediaPlayer * player;
};

#endif // GAME_H
