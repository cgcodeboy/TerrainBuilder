#ifndef MATH_H
#define MATH_H

#include <include/item.h>

class Math : public Item
{
public:
    Math(ITEM_TYPE type);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // MATH_H
