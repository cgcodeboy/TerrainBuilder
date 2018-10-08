#include "include/math.h"

Math::Math(ITEM_TYPE type):Item(type)
{

}

void Math::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void Math::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void Math::focusInEvent(QFocusEvent *event)
{
    QGraphicsItem::focusInEvent(event);
}

void Math::focusOutEvent(QFocusEvent *event)
{
    QGraphicsItem::focusOutEvent(event);
}

