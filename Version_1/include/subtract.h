#ifndef SUBTRACT_H
#define SUBTRACT_H

#include <include/math.h>
#include <include/itemdrawmaster.h>

class Subtract : public Math
{
public:
    Subtract();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // SUBTRACT_H
