#include "Player.h"
#include<QKeyEvent>
#include<QGraphicsScene>
#include <Bullet.h>
#include"enemy.h"

Player :: Player(QGraphicsItem * parent) : QGraphicsRectItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet.wav"));
}


void Player::keyPressEvent(QKeyEvent *event)
{


     if(event->key() == Qt::Key_A)
     {
         if(pos().x() > 0)
            setPos(x()-10, y());
     }
     else if(event->key() == Qt::Key_D)
     {
         if(pos().x() + 100 < 800)
            setPos(x()+10, y());
     }

     else if(event->key() == Qt::Key_Space){
         Bullet *myBullet = new Bullet();
         myBullet->setPos(x(),y());
         scene()->addItem(myBullet);
         if(bulletsound->state() == QMediaPlayer::PlayingState){
             bulletsound->setPosition(0);
         }
         if(bulletsound->state() == QMediaPlayer::StoppedState){
             bulletsound->play();
         }

     }

}

void Player::spawn()
{
   Enemy * enemy = new Enemy();
   scene()->addItem(enemy);

}
