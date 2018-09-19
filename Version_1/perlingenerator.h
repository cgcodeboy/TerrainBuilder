#ifndef PERLIN_GRNERATOR_H
#define PERLIN_GRNERATOR_H

#include <generator.h>

class PerlinGenerator : public Generator
{
public:
    PerlinGenerator();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    bool focused;
protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // PERLIN_GRNERATOR_H
