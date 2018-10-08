#include "include/filter.h"

Filter::Filter(ITEM_TYPE type):Item(type)
{

}

void Filter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void Filter::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void Filter::focusInEvent(QFocusEvent *event)
{
    QGraphicsItem::focusInEvent(event);
}

void Filter::focusOutEvent(QFocusEvent *event)
{
    QGraphicsItem::focusOutEvent(event);
}

