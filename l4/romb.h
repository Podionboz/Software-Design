#ifndef ROMB_H
#define ROMB_H

#include "figure.h"
#include <QGraphicsItem>
#include <QObject>

class Romb : public Figure {
  Q_OBJECT

public:
  explicit Romb(QPointF point, QObject *parent = 0);
  ~Romb();

private:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
};

#endif // ROMB_H
