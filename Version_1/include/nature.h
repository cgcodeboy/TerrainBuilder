#ifndef NATURE_H
#define NATURE_H

#include <include/item.h>

class Nature : public Item
{
public:
    Nature(ITEM_TYPE type);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // NATURE_H
