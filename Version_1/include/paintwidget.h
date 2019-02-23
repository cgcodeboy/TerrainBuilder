#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QtGui>
#include <QWidget>
#include <QDebug>
#include "include/shape.h"

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = 0);

    void saveBMP();

signals:

public slots:
    void setCurrentShape(Shape::Code s);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Shape::Code currShapeCode;
    Shape *shape;
    bool perm;
    QList<Shape*> shapeList;
};

#endif // PAINTWIDGET_H
