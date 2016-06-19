#include "bomb.h"

Bomb::Bomb(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}

void Bomb::effect(){
    b2Vec2 pos = g_body->GetPosition();
    g_body ->SetAngularVelocity(360);
    setLinearVelocity(b2Vec2(pos.x*2,-pos.y*2));
}
