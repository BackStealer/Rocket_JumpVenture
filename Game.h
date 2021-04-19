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
#include "Intel.h"
#include "Skill.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Soldier * soldier;
    Score * score;
    Health * health;
    Skill * skill;
    QMediaPlaylist * playlist;
    QMediaPlayer * player;
};

#endif // GAME_H
