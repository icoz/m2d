#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "block.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sc = new QGraphicsScene(this);
    ui->gvMain->setScene(sc);
    sc->addItem(new Block(Dirt));
    sc->addItem(new Block(Gold,QPointF(16,0)));
    sc->addItem(new Block(Stone,QPointF(16,16)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
