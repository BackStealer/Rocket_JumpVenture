#ifndef SOLDIER_H
#define SOLDIER_H

#include "Skill.h"
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
public slots:
    void spawn();
    void intelSpawn();
    void endLaugh();
    void move();
private:
    Skill *skill;
};

#endif // SOLDIER_H
