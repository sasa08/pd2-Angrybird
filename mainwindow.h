#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <QKeyEvent>
#include <iostream>
#include <QTime>
#include <QPushButton>

#include <gameitem.h>
#include <barrier.h>
#include <land.h>
#include <bird.h>
#include <pig.h>
#include <red.h>
#include <chuck.h>
#include <bomb.h>
#include <the_blues.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    MainWindow *w;
    void keyPressEvent(QKeyEvent *event);
    void showEvent(QShowEvent *event);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    void GenerateBird(int);
    void GeneratePig();
    void GenerateBrick();
    void ChoosePlane();
    void Finish();
    int a;
    int planet = 0;
    int click = 1;
    Red *red;
    Chuck *chuck;
    Bomb *bomb;
    The_Blues *the_blues;
    The_Blues *tm1_blues;
    The_Blues *tm2_blues;
    pig *p;
    pig *p1;
    pig *p2;
    Barrier *b1;
    Barrier *b2;
    Barrier *b3;

    QPushButton *leave;
    QGraphicsTextItem *starttxt;
    QGraphicsTextItem *starttxt1;
    QGraphicsTextItem *starttxt2;
    QGraphicsTextItem *starttxt3;
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
};

#endif // MAINWINDOW_H
