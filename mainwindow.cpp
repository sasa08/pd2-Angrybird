#include "mainwindow.h"
#include "ui_mainwindow.h"
int cnt=2;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{

    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    QPixmap bg;
    bg.load(":/startbg.jpg");
    bg = bg.scaled(width(),ui->graphicsView->height());
    scene->setBackgroundBrush(bg);

    //Text
    starttxt = new QGraphicsTextItem("Press M from earth to moon");
    starttxt->setPos(QPointF(width()/1.4,15));
    starttxt->setScale(1.5);
    scene ->addItem(starttxt);

    starttxt1 = new QGraphicsTextItem("Press E from moon to earth");
    starttxt1->setPos(QPointF(width()/1.4,40));
    starttxt1->setScale(1.5);
    scene ->addItem(starttxt1);

    starttxt2 = new QGraphicsTextItem("Press G to exit the game");
    starttxt2->setPos(QPointF(width()/1.4,65));
    starttxt2->setScale(1.5);
    scene ->addItem(starttxt2);

   // Create world
   // ChoosePlane();
    world = new b2World(b2Vec2(0.0f, 0.0f));
    //world = new b2World(b2Vec2(0.0f, -3.2f));
    /*
    if(planet == 1){
        world = new b2World(b2Vec2(0.0f, -9.8f));
    }
    if(planet == 2){
        world = new b2World(b2Vec2(0.0f, -3.2f));
    }*/
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,1.0,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));

    // Create bird (You can edit here)
    //Bird *birdie[10] = new Bird;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    a = qrand()%4;
    //a = 0;
    GenerateBird(a);
    //0.0f (float)
    //SetGravityScale
    //都跟g_body有關

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
        if(event ->key() ==Qt::Key_E ){
            //lazy to fix the repeat question
            //earth
            QPixmap bg;
            bg.load(":/ebg.png");
            bg = bg.scaled(width(),ui->graphicsView->height());
            scene->setBackgroundBrush(bg);
            planet = 1;
            ChoosePlane();
            GenerateBrick();
            GeneratePig();
            scene ->removeItem(starttxt);
            scene ->removeItem(starttxt1);
        }

        if(event ->key() ==Qt::Key_M ){
             //lazy to fix the repeat question
            //Virus
            QPixmap bg;
            bg.load(":/mbg.jpg");
            bg = bg.scaled(width(),ui->graphicsView->height());
            scene->setBackgroundBrush(bg);
            planet = 2;
            ChoosePlane();
            GenerateBrick();
            GeneratePig();
            scene ->removeItem(starttxt);
            scene ->removeItem(starttxt1);
        }

        if(event ->key() ==Qt::Key_G ){
            //Virus
            QPixmap bg;
            bg.load(":/endbg.png");
            bg = bg.scaled(width(),ui->graphicsView->height());
            scene->setBackgroundBrush(bg);
            scene ->removeItem(starttxt);
            scene ->removeItem(starttxt1);
            scene ->removeItem(starttxt2);


            starttxt2 = new QGraphicsTextItem("Play Again?");
            starttxt2->setPos(QPointF(width()/8,90));
            starttxt2->setScale(1.5);
            scene ->addItem(starttxt2);

            starttxt3 = new QGraphicsTextItem("Press R to restart");
            starttxt3->setPos(QPointF(width()/8,120));
            starttxt3->setScale(1.5);
            scene ->addItem(starttxt3);


        }

        if(event ->key() ==Qt::Key_R ){
            //Virus
            scene ->removeItem(starttxt2);
            scene ->removeItem(starttxt3);
            //pig -> QPixmap("");
            //w->hide();
            w = new MainWindow();
            w ->show();
        }

}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    b2Vec2 pos;
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here */
        std::cout << click;
        if(click == 1){
             //std::cout << "Press !" << std::endl ;
            switch(a){
                case 0:
                    pos = red->g_body -> GetPosition();
                    red ->setLinearVelocity(b2Vec2(7,7));
                    break;
                case 1:
                    pos = chuck->g_body -> GetPosition();
                    chuck ->setLinearVelocity(b2Vec2(5,5));
                break;

                case 2:
                    pos = bomb->g_body -> GetPosition();
                    bomb ->setLinearVelocity(b2Vec2(6,6));
                break;

                case 3:
                    pos = the_blues->g_body -> GetPosition();
                    the_blues ->setLinearVelocity(b2Vec2(5,5));
                break;

            }
            //std:: cout <<"GG";
        }
        else if(click == -6){//點一次會有多次
           // std::cout << "jizzz";
        QPixmap tmp;
        switch(a){
            case 0:
            red -> effect();
            //birdie->accerlate();
            //std::cout << "accerlate!" << std::endl ;
            break;

            case 1:
                chuck ->effect();
            break;

            case 2:
                bomb -> effect();
                //birdie->spilit();
                //std::cout << "spilit !" << std::endl ;
                break;

            case 3:
                the_blues ->effect();
                while(cnt){
                    tmp.load(":/bird3.png");
                    if(cnt == 2){
                        tm1_blues = new The_Blues( the_blues ->blueposx(),the_blues ->blueposy(),0.7f,&timer,tmp.scaled(height()/9.0,height()/9.0),world,scene);
                        tm1_blues->effect();
                    }
                    else{
                        tm2_blues = new The_Blues(the_blues ->blueposx(),the_blues ->blueposy(),0.7f,&timer,tmp.scaled(height()/9.0,height()/9.0),world,scene);
                        tm2_blues->effect();
                    }
                    cnt--;
                 }
                //birdie->explode();
                //std::cout << "explode !" << std::endl ;
                break;

            default:
                break;
        }
        }
        else{;}
        click--;
    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;

        switch(a){
            //case 0:

        }
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
       // std::cout << "Release !" << std::endl ;
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::GenerateBird(int rand){
    QPixmap birdp;
    switch(rand){
        case 0:
        birdp.load(":/bird1.png");
        red = new Red(5.0f,10.0f,0.7f,&timer,birdp.scaled(height()/9.0,height()/9.0),world,scene);
        // Setting the Velocity
        red->setLinearVelocity(b2Vec2(0,0));
        itemList.push_back(red);
        break;

        case 1:
        birdp.load(":/bird2.png");
        chuck = new Chuck(5.0f,10.0f,0.7f,&timer,birdp.scaled(height()/9.0,height()/9.0),world,scene);
    // Setting the Velocity
        chuck->setLinearVelocity(b2Vec2(0,0));
        itemList.push_back(chuck);
        break;

        case 2:
        birdp.load(":/bird4.png");
        bomb = new Bomb(5.0f,10.0f,0.7f,&timer,birdp.scaled(height()/9.0,height()/9.0),world,scene);
    // Setting the Velocity
        bomb->setLinearVelocity(b2Vec2(0,0));
        itemList.push_back(bomb);
        break;

        case 3:
        birdp.load(":/bird3.png");
        the_blues = new The_Blues(5.0f,10.0f,0.7f,&timer,birdp.scaled(height()/9.0,height()/9.0),world,scene);
    // Setting the Velocity
        the_blues->setLinearVelocity(b2Vec2(0,0));
        itemList.push_back(the_blues);
        break;

        default:
            break;
    }

}

void MainWindow::GenerateBrick(){
    b1= new Barrier (18.0f,5.0f,0.8f,&timer,QPixmap(":/brick.png").scaled(height()/9.0,height()/9.0),world,scene);

    b2 = new Barrier (25.0f,3.0f,0.8f,&timer,QPixmap(":/brick.png").scaled(height()/9.0,height()/9.0),world,scene);

    b3 = new Barrier (18.0f,6.0f,0.8f,&timer,QPixmap(":/brick.png").scaled(height()/9.0,height()/9.0),world,scene);
}

void MainWindow::GeneratePig(){
    //三隻小豬
    p = new pig (25.0f,4.0f,0.7f,&timer,QPixmap(":/pig.png").scaled(height()/9.0,height()/9.0),world,scene);
    p->setLinearVelocity(b2Vec2(0,0));

    p1 = new pig (25.0f,5.0f,0.7f,&timer,QPixmap(":/pig.png").scaled(height()/9.0,height()/9.0),world,scene);
    p1->setLinearVelocity(b2Vec2(0,0));

    p2= new pig (28.0f,4.0f,0.7f,&timer,QPixmap(":/pig.png").scaled(height()/9.0,height()/9.0),world,scene);
    p2->setLinearVelocity(b2Vec2(0,0));
}

void MainWindow::ChoosePlane(){
    if(planet == 1){
        world->SetGravity( b2Vec2(0,-9.8f) );
    }
    if(planet == 2){
        world->SetGravity( b2Vec2(0,-3.2f) );
    }
}

/*
void MainWindow::Finish(){
       leave = new QPushButton("STOP",this);
       leave ->setGeometry(QRect(QPoint(width()/2, 50),QSize(200, 50)));
       leave->setText("Example");
       // resize button
       leave->resize(100,100);
     //  connect(this, SIGNAL (released()), this, SLOT (handleButton()));
}
*/


