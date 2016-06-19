#ifndef CHUCK_H
#define CHUCK_H

#include <bird.h>
class Chuck : public Bird
{
public:
    Chuck(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void effect();
};


#endif // CHUCK_H
