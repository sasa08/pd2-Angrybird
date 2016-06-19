#ifndef RED_H
#define RED_H

#include <bird.h>


class Red : public Bird
{
public:
    Red(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void effect();
};

#endif // RED_H
