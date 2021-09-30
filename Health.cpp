#include"Health.h"
#include<QFont>
Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent){

    health = 3;
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}

void Health::decrease()
{
    health--;
    setPlainText("Health: " + QString::number(health));

}

int Health::getHealth()
{
    return health;
}


