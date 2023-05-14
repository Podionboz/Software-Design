#include "square.h"
#include <QPainter>

Square::Square(QPointF point, QObject *parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Square::~Square() {}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget) {
  painter->setPen(QPen(Qt::black, 2));

  QRectF rect(
      endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
      endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
      qAbs(endPoint().x() - startPoint().x()),
      qAbs(endPoint().x() - startPoint().x()));

  painter->drawRect(rect);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}
