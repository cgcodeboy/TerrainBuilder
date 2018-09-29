#ifndef VORONOIGENERATOR_H
#define VORONOIGENERATOR_H

#include <include/generator.h>

class VoronoiGenerator : public Generator
{
public:
    VoronoiGenerator();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // VORONOIGENERATOR_H
