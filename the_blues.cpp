#include "the_blues.h"

int c = 3;
b2Vec2 pos ;
The_Blues::The_Blues(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}

void The_Blues::effect(){

        if(c==3){
            pos = g_body->GetPosition();
            setLinearVelocity(b2Vec2(pos.x*2,pos.y));
            c--;
        }
        else if(c==2){
            setLinearVelocity(b2Vec2(pos.x*4,pos.y*1.2));
            c--;
        }
        else{
            setLinearVelocity(b2Vec2(pos.x*2,pos.y));
            c--;
        }

}

double The_Blues::blueposx(){
    b2Vec2 bpos = g_body->GetPosition();
    double x = bpos.x;
    return x;
}

double The_Blues::blueposy(){
    b2Vec2 bpos = g_body->GetPosition();
    double y = bpos.y;
    return y;
}
