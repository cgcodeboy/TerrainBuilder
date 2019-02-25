#include "include/terrace.h"

Terrace::Terrace():Filter(ITEM_TYPE::Terrace_Filter)
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);
}

QRectF Terrace::boundingRect() const
{
    return QRectF(0,0,150,70);
}

void Terrace::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ItemDrawMaster *drawMaster = new ItemDrawMaster(getType(),painter,focused);
    drawMaster->draw();
}

void Terrace::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void Terrace::focusInEvent(QFocusEvent *event)
{
    focused = true;
    update();
    QGraphicsItem::focusInEvent(event);
}

void Terrace::focusOutEvent(QFocusEvent *event)
{
    focused = false;
    update();
    QGraphicsItem::focusOutEvent(event);
}
