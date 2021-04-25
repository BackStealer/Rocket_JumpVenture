#include "Blu_bots.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsSimpleTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent)
{
    soldier = new Soldier();

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    soldier->setPos(-100,-100);
    scene->addItem(soldier);
    soldier->setFlag(QGraphicsItem::ItemIsFocusable);
    soldier->setFocus();
    soldier->setPixmap(QPixmap("bruh"));

    setBackgroundBrush(QBrush(QImage(":/new/img/img_res/main_menu.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    spwnTimer = new QTimer();

    pyroTimer = new QTimer();

    heavyTimer = new QTimer();

    intelSpwnTimer = new QTimer();

    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/new/sound/sound_res/Rocket Jump Waltz Remix [NO HEAVY] - HD.mp3"));
    playlist->addMedia(QUrl("qrc:/new/sound/sound_res/Team Fortress 2 Soundtrack Intruder Alert.mp3"));
    playlist->addMedia(QUrl("qrc:/new/sound/sound_res/The Calm and ROBOTS! combined (Team Fortress 2 music).mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player = new QMediaPlayer;
    player->setPlaylist(playlist);
    player->setVolume(3);

    mainM = new QMediaPlayer;
    mainM->setMedia(QUrl("qrc:/new/sound/sound_res/Team Fortress 2 - Rocket Jump Waltz Orchestra (Extended 6 minutes).mp3"));
    mainM->setVolume(3);
    mainM->play();

    show();
}

void Game::StartGame()
{
    mainM->stop();
    setBackgroundBrush(QBrush(QImage(":/new/img/img_res/bg.png")));

    soldier->setPos(30,250);
    soldier->setPixmap(QPixmap(":/new/img/img_res/Soldier.png"));

//    soldier->setFlag(QGraphicsItem::ItemIsFocusable);
//    soldier->setFocus();

//    scene->addItem(soldier);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(),health->y()+35);
    scene->addItem(health);

    skill = new Skill();
    skill->setPos(skill->x(),skill->y()+70);
    scene->addItem(skill);

    QObject::connect(spwnTimer,SIGNAL(timeout()),soldier,SLOT(spawn()));
    QObject::connect(pyroTimer,SIGNAL(timeout()),soldier,SLOT(pyroSpawn()));
    QObject::connect(heavyTimer,SIGNAL(timeout()),soldier,SLOT(heavySpawn()));
    QObject::connect(intelSpwnTimer,SIGNAL(timeout()),soldier,SLOT(intelSpawn()));

    spwnTimer->start(1500);
    pyroTimer->start(3000);
    heavyTimer->start(4000);
    intelSpwnTimer->start(60000);

    player->play();
}

void Game::FailS()
{
    failScene = new QGraphicsScene;
    failScene->setSceneRect(0,0,800,600);
    player->stop();
    setScene(failScene);
    setBackgroundBrush(QBrush(QImage(":/new/img/img_res/trollge.png")));

    score->setPos(score->x(),score->y()+300);
    failScene->addItem(score);

    mainM->setMedia(QUrl("qrc:/new/sound/sound_res/The Caretaker - It's just a burning memory (2016).mp3"));
    mainM->play();

    spwnTimer->stop();
    pyroTimer->stop();
    heavyTimer->stop();
    intelSpwnTimer->stop();
}
