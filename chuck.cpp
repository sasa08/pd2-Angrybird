#include "chuck.h"

Chuck::Chuck(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}

void Chuck::effect(){
    //g_body ->SetAngularVelocity(90);(rotate)
    b2Vec2 pos = g_body->GetPosition();
    setLinearVelocity(b2Vec2((pos.x+5)*3,-pos.y*3));
}
