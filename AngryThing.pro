#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T02:17:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AngryThing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameitem.cpp \
    bird.cpp \
    land.cpp \
    box2D_cpps/b2BlockAllocator.cpp \
    box2D_cpps/b2Body.cpp \
    box2D_cpps/b2BroadPhase.cpp \
    box2D_cpps/b2ChainAndCircleContact.cpp \
    box2D_cpps/b2ChainAndPolygonContact.cpp \
    box2D_cpps/b2ChainShape.cpp \
    box2D_cpps/b2CircleContact.cpp \
    box2D_cpps/b2CircleShape.cpp \
    box2D_cpps/b2CollideCircle.cpp \
    box2D_cpps/b2CollideEdge.cpp \
    box2D_cpps/b2CollidePolygon.cpp \
    box2D_cpps/b2Collision.cpp \
    box2D_cpps/b2Contact.cpp \
    box2D_cpps/b2ContactManager.cpp \
    box2D_cpps/b2ContactSolver.cpp \
    box2D_cpps/b2Distance.cpp \
    box2D_cpps/b2DistanceJoint.cpp \
    box2D_cpps/b2Draw.cpp \
    box2D_cpps/b2DynamicTree.cpp \
    box2D_cpps/b2EdgeAndCircleContact.cpp \
    box2D_cpps/b2EdgeAndPolygonContact.cpp \
    box2D_cpps/b2EdgeShape.cpp \
    box2D_cpps/b2Fixture.cpp \
    box2D_cpps/b2FrictionJoint.cpp \
    box2D_cpps/b2GearJoint.cpp \
    box2D_cpps/b2Island.cpp \
    box2D_cpps/b2Joint.cpp \
    box2D_cpps/b2Math.cpp \
    box2D_cpps/b2MotorJoint.cpp \
    box2D_cpps/b2MouseJoint.cpp \
    box2D_cpps/b2PolygonAndCircleContact.cpp \
    box2D_cpps/b2PolygonContact.cpp \
    box2D_cpps/b2PolygonShape.cpp \
    box2D_cpps/b2PrismaticJoint.cpp \
    box2D_cpps/b2PulleyJoint.cpp \
    box2D_cpps/b2RevoluteJoint.cpp \
    box2D_cpps/b2Rope.cpp \
    box2D_cpps/b2RopeJoint.cpp \
    box2D_cpps/b2Settings.cpp \
    box2D_cpps/b2StackAllocator.cpp \
    box2D_cpps/b2TimeOfImpact.cpp \
    box2D_cpps/b2Timer.cpp \
    box2D_cpps/b2WeldJoint.cpp \
    box2D_cpps/b2WheelJoint.cpp \
    box2D_cpps/b2World.cpp \
    box2D_cpps/b2WorldCallbacks.cpp \
    pig.cpp \
    red.cpp \
    chuck.cpp \
    bomb.cpp \
    the_blues.cpp \
    barrier.cpp

HEADERS  += mainwindow.h \
    gameitem.h \
    bird.h \
    land.h \
    Box2D/Collision/Shapes/b2ChainShape.h \
    Box2D/Collision/Shapes/b2CircleShape.h \
    Box2D/Collision/Shapes/b2EdgeShape.h \
    Box2D/Collision/Shapes/b2PolygonShape.h \
    Box2D/Collision/Shapes/b2Shape.h \
    Box2D/Collision/b2BroadPhase.h \
    Box2D/Collision/b2Collision.h \
    Box2D/Collision/b2Distance.h \
    Box2D/Collision/b2DynamicTree.h \
    Box2D/Collision/b2TimeOfImpact.h \
    Box2D/Common/b2BlockAllocator.h \
    Box2D/Common/b2Draw.h \
    Box2D/Common/b2GrowableStack.h \
    Box2D/Common/b2Math.h \
    Box2D/Common/b2Settings.h \
    Box2D/Common/b2StackAllocator.h \
    Box2D/Common/b2Timer.h \
    Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h \
    Box2D/Dynamics/Contacts/b2CircleContact.h \
    Box2D/Dynamics/Contacts/b2Contact.h \
    Box2D/Dynamics/Contacts/b2ContactSolver.h \
    Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h \
    Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2PolygonContact.h \
    Box2D/Dynamics/Joints/b2DistanceJoint.h \
    Box2D/Dynamics/Joints/b2FrictionJoint.h \
    Box2D/Dynamics/Joints/b2GearJoint.h \
    Box2D/Dynamics/Joints/b2Joint.h \
    Box2D/Dynamics/Joints/b2MotorJoint.h \
    Box2D/Dynamics/Joints/b2MouseJoint.h \
    Box2D/Dynamics/Joints/b2PrismaticJoint.h \
    Box2D/Dynamics/Joints/b2PulleyJoint.h \
    Box2D/Dynamics/Joints/b2RevoluteJoint.h \
    Box2D/Dynamics/Joints/b2RopeJoint.h \
    Box2D/Dynamics/Joints/b2WeldJoint.h \
    Box2D/Dynamics/Joints/b2WheelJoint.h \
    Box2D/Dynamics/b2Body.h \
    Box2D/Dynamics/b2ContactManager.h \
    Box2D/Dynamics/b2Fixture.h \
    Box2D/Dynamics/b2Island.h \
    Box2D/Dynamics/b2TimeStep.h \
    Box2D/Dynamics/b2World.h \
    Box2D/Dynamics/b2WorldCallbacks.h \
    Box2D/Rope/b2Rope.h \
    Box2D/Box2D.h \
    ui_mainwindow.h \
    pig.h \
    red.h \
    chuck.h \
    bomb.h \
    the_blues.h \
    barrier.h


FORMS    += mainwindow.ui

#LIBS += -L. -lBox2D

RESOURCES += \
    res.qrc
