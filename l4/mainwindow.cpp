#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  scene = new PaintScene();
  ui->graphicsView->setScene(scene);
  ui->graphicsView->setRenderHint(QPainter::Antialiasing);
  ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  timer = new QTimer();
  connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
  timer->start(100);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::slotTimer() {
  timer->stop();
  scene->setSceneRect(0, 0, ui->graphicsView->width() - 20,
                      ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
  timer->start(100);
  QMainWindow::resizeEvent(event);
}

void MainWindow::on_pushButton_clicked() {
  scene->setTypeFigure(PaintScene::RombType);
}

void MainWindow::on_pushButton_2_clicked() {
  scene->setTypeFigure(PaintScene::SquareType);
}

void MainWindow::on_pushButton_3_clicked() {
  scene->setTypeFigure(PaintScene::TriangleType);
}
