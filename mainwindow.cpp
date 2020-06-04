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

    // Vehicle Paramaters initialization
    velocity = 0.0;
    steeringAngle = 0.0;
    x = 0.0;
    y = 0.0;
    theta = 0.0;
    wheelBase = 2.0;

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
