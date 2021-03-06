#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QUrl>
#include <QGraphicsItem>
#include "Soldier.h"
#include "Rocket.h"
#include "Score.h"
#include "Health.h"
#include "Intel.h"
#include "Skill.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene, * failScene;
    Soldier * soldier;
    Rocket * rocket;
    Score * score;
    Health * health;
    Skill * skill;
    QMediaPlaylist * playlist;
    QMediaPlayer * player,* mainM;
    QTimer * spwnTimer;
    QTimer * pyroTimer;
    QTimer * heavyTimer;
    QTimer * intelSpwnTimer;
public slots:
    void StartGame();
    void FailS();
signals:
    void Stop();
};

#endif // GAME_H
