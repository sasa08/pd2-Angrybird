#ifndef THE_BLUES_H
#define THE_BLUES_H

#include <bird.h>

class The_Blues : public Bird
{
public:
    The_Blues(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void effect();
    double blueposx();
    double blueposy();
};

#endif // THE_BLUES_H
