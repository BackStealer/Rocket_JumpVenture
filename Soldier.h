#ifndef SOLDIER_H
#define SOLDIER_H

#include "Skill.h"
#include "Intel.h"

#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QObject>
#include <QMediaPlayer>
#include <QUrl>
#include <QMap>
#include <QTimer>
#include <QWidget>

class Soldier: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Soldier(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
  //void mousePressEvent(QMouseEvent *event);
    QMediaPlayer *rktShoot, *laugh;
    QMap<int, bool> pressedKeys;
    QPointF position;
    int check;
    bool cooldown;
    bool skillCooldown;    
    bool ingame;
public slots:
    void spawn();
    void heavySpawn();
    void pyroSpawn();
    void intelSpawn();
    void endLaugh();
    void move();
    void SkillInfo();
    void unlock();
    void unlockSkill();
    void caughtIntel();
    void megaStop();
private:
    Skill *skill;
};

#endif // SOLDIER_H
