#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>
#include <QTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  QTimer *timer = new QTimer;
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  timer->start(1000);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::paintEvent(QPaintEvent *) {
  QPainter painter;
  painter.begin(this);
  QTime time = QTime::currentTime();
  painter.setRenderHint(QPainter::Antialiasing);
  painter.translate(width() / 2, height() / 2);
  painter.save();
  QPolygon home;
  home << QPoint(0, 0) << QPoint(0, -90) << QPoint(180, -90) << QPoint(180, 0);
  painter.rotate(6 * time.second());
  painter.setPen(Qt::NoPen);
  painter.setBrush(QColor(45, 128, 64));
  painter.drawPolygon(home);
  painter.restore();

  painter.save();
  QPolygon roof;
  roof << QPoint(0, -90) << QPoint(90, -180) << QPoint(180, -90);
  painter.rotate(6 * time.second());
  painter.setPen(Qt::NoPen);
  painter.setBrush(QColor(0, 127, 127, 191));

  painter.drawPolygon(roof);
  painter.restore();

  painter.save();
  QPolygon window;
  window << QPoint(20, -70) << QPoint(60, -70) << QPoint(60, -30)
         << QPoint(20, -30);
  painter.rotate(6 * time.second());
  painter.setPen(Qt::NoPen);
  painter.setBrush(QColor(176, 201, 216));

  painter.drawPolygon(window);
  painter.restore();

  painter.save();
  QPolygon door;
  door << QPoint(120, 0) << QPoint(120, -50) << QPoint(150, -50)
       << QPoint(150, 0);
  painter.rotate(6 * time.second());
  painter.setPen(Qt::NoPen);
  painter.setBrush(QColor(210, 183, 166));

  painter.drawPolygon(door);
  painter.restore();
  painter.save();
}
