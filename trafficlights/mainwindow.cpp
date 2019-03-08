#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "world.h"
#include"initialise.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    drawSurfacePixmap = NULL;
    drawSurfacePainter = NULL;
    initRenderSurface();
    QPointF WSize= WorldSize();
    mainWorld = new World(WSize);
    worldMap = new map();
    // worldPainter = new WorldPainter(drawSurfacePainter, this,WSize.x()/mainWorld->maxX,WSize.y()/mainWorld->maxY);
    worldPainter = new WorldPainter(drawSurfacePainter, this);
    worldIterator = new WorldIterator(mainWorld, worldPainter, worldMap);
    worldPainter->repaint(mainWorld, worldMap);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    //initRenderSurface();
}

void MainWindow::renderPixmap()
{
    ui->drawSurface->setPixmap(*drawSurfacePixmap);
}

void MainWindow::initRenderSurface()
{
    if(drawSurfacePixmap != NULL)
        delete drawSurfacePixmap;
    if(drawSurfacePainter != NULL)
        delete drawSurfacePainter;

    ui->drawSurface->setFixedSize(this->size());
    int w = ui->drawSurface->width();
    int h = ui->drawSurface->height();

    drawSurfacePixmap = new QPixmap(w,h);
    drawSurfacePainter = new QPainter(drawSurfacePixmap);

}

MainWindow::~MainWindow()
{
    delete worldIterator;
    delete worldPainter;
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    if(ui->startButton->text()=="Start"){
        worldIterator->start();
        ui->startButton->setText("Stop");
    }
    else{
        worldIterator->stop();
        ui->startButton->setText("Start");
    }
}
/*
void MainWindow::on_networkCheckBox_clicked()
{
    worldPainter->paintNetwork = ui->networkCheckBox->isChecked();
    worldPainter->repaint(mainWorld);
}

void MainWindow::on_restartButton_clicked()
{
    drawSurfacePixmap = NULL;
    drawSurfacePainter = NULL;
    initRenderSurface();
    QPointF WSize=WorldSize();
    mainWorld = new World(WSize);
    // worldPainter = new WorldPainter(drawSurfacePainter, this,WSize.x()/mainWorld->maxX,WSize.y()/mainWorld->maxY);
    worldPainter = new WorldPainter(drawSurfacePainter, this);
    worldIterator = new WorldIterator(mainWorld, worldPainter);
    worldPainter->repaint(mainWorld);
} */
