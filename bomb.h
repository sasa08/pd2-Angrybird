#ifndef BOMB_H
#define BOMB_H

#include<bird.h>

class Bomb:public Bird
{
public:
    Bomb(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void effect();
};

#endif // BOMB_H
