#include "Blu_bots.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsSimpleTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    setBackgroundBrush(QBrush(QImage(":/new/img/img_res/bg.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    soldier = new Soldier();
    soldier->setPos(30,250);

    soldier->setFlag(QGraphicsItem::ItemIsFocusable);
    soldier->setFocus();

    scene->addItem(soldier);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(),health->y()+35);
    scene->addItem(health);

    skill = new Skill();
    skill->setPos(skill->x(),skill->y()+70);
    scene->addItem(skill);

    QTimer * spwnTimer = new QTimer();
    QObject::connect(spwnTimer,SIGNAL(timeout()),soldier,SLOT(spawn()));
    spwnTimer->start(1500);

    QTimer * intelSpwnTimer = new QTimer();
    QObject::connect(intelSpwnTimer,SIGNAL(timeout()),soldier,SLOT(intelSpawn()));
    intelSpwnTimer->start(60000);

    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/new/sound/sound_res/Rocket Jump Waltz Remix [NO HEAVY] - HD.mp3"));
    playlist->addMedia(QUrl("qrc:/new/sound/sound_res/Team Fortress 2 Soundtrack Intruder Alert.mp3"));
    playlist->addMedia(QUrl("qrc:/new/sound/sound_res/The Calm and ROBOTS! combined (Team Fortress 2 music).mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player = new QMediaPlayer;
    player->setPlaylist(playlist);
    player->setVolume(3);
    player->play();

    show();
}
