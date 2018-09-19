#ifndef GRADIENT_GRNERATOR_H
#define GRADIENT_GRNERATOR_H

#include <generator.h>

class GradientGenerator : public Generator
{
public:
    GradientGenerator();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    bool focused;
protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // GRADIENT_GRNERATOR_H
