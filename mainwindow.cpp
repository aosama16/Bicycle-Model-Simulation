#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    scene->setSceneRect(-400, -400, 800, 800);
    setCentralWidget(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scale(1, -1);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    drawVehicle();
}

void MainWindow::drawVehicle()
{
    vehicleFrame = new QGraphicsEllipseItem();
    scene->addItem(vehicleFrame);

    QGraphicsTextItem *arrow = new QGraphicsTextItem(">", vehicleFrame);
    arrow->setPos(15, 3);

    QGraphicsRectItem *vehicle = new QGraphicsRectItem(vehicleFrame);
    vehicle->setRect(0, 0, 50, 30);
}

MainWindow::~MainWindow()
{
    delete ui;
}
