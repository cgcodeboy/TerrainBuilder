#include "include/nature.h"

Nature::Nature(ITEM_TYPE type):Item(type)
{

}

void Nature::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void Nature::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void Nature::focusInEvent(QFocusEvent *event)
{
    QGraphicsItem::focusInEvent(event);
}

void Nature::focusOutEvent(QFocusEvent *event)
{
    QGraphicsItem::focusOutEvent(event);
}


