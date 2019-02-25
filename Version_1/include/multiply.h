#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <include/math.h>
#include <include/itemdrawmaster.h>

class Multiply : public Math
{
public:
    Multiply();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // MULTIPLY_H
