#include "paintscene.h"
#include "rectangle.h"
#include "romb.h"
#include "square.h"
#include "triangle.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent) {}

PaintScene::~PaintScene() {}

int PaintScene::typeFigure() const { return m_typeFigure; }

void PaintScene::setTypeFigure(const int type) { m_typeFigure = type; }

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  tempFigure->setEndPoint(event->scenePos());
  this->update(QRectF(0, 0, this->width(), this->height()));
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  switch (m_typeFigure) {
  case SquareType: {
    Square *item = new Square(event->scenePos());
    item->setPos(event->pos());
    tempFigure = item;
    break;
  }
  case RombType: {
    Romb *item = new Romb(event->scenePos());
    item->setPos(event->pos());
    tempFigure = item;
    break;
  }
  case TriangleType: {
    Triangle *item = new Triangle(event->scenePos());
    item->setPos(event->pos());
    tempFigure = item;
    break;
  }
  default: {
    Rectangle *item = new Rectangle(event->scenePos());
    item->setPos(event->pos());
    tempFigure = item;
    break;
  }
  }
  this->addItem(tempFigure);
}
