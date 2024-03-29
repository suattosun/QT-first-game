#include"Bullet.h"
#include <QTimer>
#include<QGraphicsScene>
#include<QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game;
Bullet::Bullet(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/2.png"));

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}



void Bullet::move()
{
    // if bullet collides with enemy , destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; ++i){
        if(typeid (*(colliding_items[i])) == typeid (Enemy)){
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem((this));
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(),y() - 10);
    if(pos().y()   < 0){
        scene()->removeItem(this);
        delete this;

    }
}
