#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem* vehicleFrame;
    void drawVehicle();

    // Vehicle Parameters
    const double MAX_VELOCITY = 5.0;
    const double MAX_STEERING = 60.0;

    double velocity;
    double steeringAngle;
    double x;
    double y;
    double theta;
    double wheelBase;

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void updateVehiclePosition();
};

#endif // MAINWINDOW_H
