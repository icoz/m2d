#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "block.h"
#include "chunk.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sc = new QGraphicsScene(this);
    ui->gvMain->setScene(sc);
    ui->gvMap->setScene(sc);
//    sc->addItem(new Block(Dirt));
//    sc->addItem(new Block(Gold,QPointF(16,0)));
//    sc->addItem(new Block(Stone,QPointF(16,16)));
//    QGraphicsItemGroup *g = new QGraphicsItemGroup();
//    g->addToGroup(new Block(Dirt));
//    g->addToGroup(new Block(Gold,QPointF(16,0)));
//    g->addToGroup(new Block(Stone,QPointF(16,16)));
//    g->setPos(QPointF(32,32));
//    sc->addItem(g);
    Chunk *c = new Chunk("chunk0_0.chunk");
    sc->addItem(c);
    ui->gvMain->scale(2,2);
    ui->gvMap->setSceneRect(sc->width()/2,sc->height()/2, 64*16, 64*16);
}

MainWindow::~MainWindow()
{
    delete ui;
}
