#include "include/conbiner.h"

Conbiner::Conbiner(ITEM_TYPE type):Item(type)
{

}

void Conbiner::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void Conbiner::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void Conbiner::focusInEvent(QFocusEvent *event)
{
    QGraphicsItem::focusInEvent(event);
}

void Conbiner::focusOutEvent(QFocusEvent *event)
{
    QGraphicsItem::focusOutEvent(event);
}

