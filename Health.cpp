#include "Health.h"
#include <QFont>
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
}
int Health::getHealth()
{
    return health;
}
