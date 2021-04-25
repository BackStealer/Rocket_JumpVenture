#include "Health.h"
#include "Game.h"
#include <QFont>

extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 3;
    setPlainText(QString("Lives: ") + QString::number(health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",25));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Lives: ") + QString::number(health));
    if(health==0)
    {
        game->FailS();
    }
}
int Health::getHealth()
{
    return health;
}
