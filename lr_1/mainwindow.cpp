#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

struct Point {
    float x;
    float y;
};

struct Triangle {
    Point p1;
    Point p2;
    Point p3;
};

Triangle Head;

float calcdist(float p2x, float p1x, float p2y, float p1y) {
    return sqrt((pow((p2x - p1x), 2)) + (pow((p2y - p1y), 2)));
}

void MainWindow::on_pushButton_clicked() {
    float d1, d2, d3;

        Head.p1.x = ui->x_1Edit->text().toFloat();
        Head.p1.y = ui->y_1Edit->text().toFloat();
        Head.p2.x = ui->x_2Edit->text().toFloat();
        Head.p2.y = ui->y_2Edit->text().toFloat();
        Head.p3.x = ui->x_3Edit->text().toFloat();
        Head.p3.y = ui->y_3Edit->text().toFloat();

        d1 = calcdist(Head.p2.x, Head.p1.x, Head.p2.y, Head.p1.y);
        d2 = calcdist(Head.p3.x, Head.p2.x, Head.p3.y, Head.p2.y);
        d3 = calcdist(Head.p1.x, Head.p3.x, Head.p1.y, Head.p3.y);

        if ((d1 + d2 > d3) && (d2 + d3 > d1) && (d1 + d3 > d2)){
            if (d1 == d2 && d1 == d3)
                ui->triangle_check->setText("Це рівносторонній трикутник.");
            //QMessageBox::about(this, "triangle", "It's equilateral triangle");
            else if (d1 != d2 && d2 != d3 && d3 != d1)
                ui->triangle_check->setText("Це різносторонній трикутник.");
            //QMessageBox::about(this, "triangle", "It's scalene triangle");
            else
                ui->triangle_check->setText("Це рівнобедрений трикутник.");
            //QMessageBox::about(this, "triangle", "It's isosceles triangle");
        }
        else
            ui->triangle_check->setText("Введені координати точок трикутника не вірні!\nТакий трикутник не може існувати.");
}
