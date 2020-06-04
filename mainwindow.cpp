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
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(updateVehiclePosition()));
    timer->start(20);
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

void MainWindow::updateVehiclePosition()
{
    double delta_x      = velocity * qCos(qDegreesToRadians(theta));
    double delta_y      = velocity * qSin(qDegreesToRadians(theta));
    double delta_theta  = (velocity/wheelBase) * qTan(qDegreesToRadians(steeringAngle));

    x+= delta_x;
    y+= delta_y;
    theta += delta_theta;

    vehicleFrame->setX(x);
    vehicleFrame->setY(y);
    vehicleFrame->setRotation(theta);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W) // Forward
    {
        velocity = MAX_VELOCITY;
    }
    else if (event->key() == Qt::Key_S) // Backward
    {
        velocity = -1.0 * MAX_VELOCITY;
    }
    else if (event->key() == Qt::Key_A) // Left
    {
        steeringAngle = MAX_STEERING;
    }
    else if (event->key() == Qt::Key_D) // Right
    {
        steeringAngle = -1.0 * MAX_STEERING;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W) // Forward
    {
        velocity = 0.0;
    }
    else if (event->key() == Qt::Key_S) // Backward
    {
        velocity = 0.0;
    }
    else if (event->key() == Qt::Key_A) // Left
    {
        steeringAngle = 0.0;
    }
    else if (event->key() == Qt::Key_D) // Right
    {
        steeringAngle = 0.0;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
