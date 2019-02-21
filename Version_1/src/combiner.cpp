#include "include/combiner.h"

Combiner::Combiner(ITEM_TYPE type):Item(type)
{

}

void Combiner::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void Combiner::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void Combiner::focusInEvent(QFocusEvent *event)
{
    QGraphicsItem::focusInEvent(event);
}

void Combiner::focusOutEvent(QFocusEvent *event)
{
    QGraphicsItem::focusOutEvent(event);
}

