#include "include/paintwidget.h"

PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent),currShapeCode(Shape::Line), shape(NULL), perm(false)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void PaintWidget::saveBMP()
{
    QPainter p;
    QPixmap map(size().width(),size().height());
    map.fill(Qt::gray);

    p.begin(&map);
    foreach(Shape * shape, shapeList) {
        shape->paint(p);
    }
    p.end();

    if(map.save("./tmp/image/test.bmp", "BMP")){
        qDebug()<<"save right";
    }
}


void PaintWidget::setCurrentShape(Shape::Code s)
{
    if(s != currShapeCode) {
        currShapeCode = s;
    }
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0, 0, size().width(), size().height());
    foreach(Shape * shape, shapeList) {
        shape->paint(painter);
    }
    if(shape) {
        shape->paint(painter);
    }
}

void PaintWidget::mousePressEvent(QMouseEvent *event)
{
    switch(currShapeCode){
    case Shape::Line:{
        shape = new Line;
        break;
    }
    case Shape::Rect:{
        shape = new Rect;
        break;
    }
    }
    if(shape != NULL) {
        perm = false;
        shapeList<<shape;
        shape->setStart(event->pos());
        shape->setEnd(event->pos());
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(shape && !perm) {
        shape->setEnd(event->pos());
        update();
    }
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
    perm = true;
}
