#ifndef RADIALGENERATOR_H
#define RADIALGENERATOR_H

#include <include/generator.h>

class RadialGenerator : public Generator
{
public:
    RadialGenerator();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // RADIALGENERATOR_H
