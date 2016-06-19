#ifndef BARRIER_H
#define BARRIER_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define Barrier_DENSITY 10.0f
#define Barrier_FRICTION 0.2f
#define Barrier_RESTITUTION 0.5f

class Barrier:public GameItem
{
public:
    Barrier(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BARRIER_H
