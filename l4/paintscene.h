#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include "figure.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class PaintScene : public QGraphicsScene {
  Q_OBJECT
  Q_PROPERTY(int typeFigure READ typeFigure WRITE setTypeFigure NOTIFY
                 typeFigureChanged)

public:
  explicit PaintScene(QObject *parent = 0);
  ~PaintScene();

  int typeFigure() const;
  void setTypeFigure(const int type);

  enum FigureTypes { SquareType, RombType, TriangleType };

signals:
  void typeFigureChanged();

private:
  Figure *tempFigure;
  int m_typeFigure;

private:
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
