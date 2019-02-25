#include "include/sqrt.h"

Sqrt::Sqrt():Math(ITEM_TYPE::Sqrt_Math)
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);
}

QRectF Sqrt::boundingRect() const
{
    return QRectF(0,0,150,90);
}

void Sqrt::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ItemDrawMaster *drawMaster = new ItemDrawMaster(getType(),painter,focused);
    drawMaster->draw();
}

void Sqrt::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void Sqrt::focusInEvent(QFocusEvent *event)
{
    focused = true;
    update();
    QGraphicsItem::focusInEvent(event);
}

void Sqrt::focusOutEvent(QFocusEvent *event)
{
    focused = false;
    update();
    QGraphicsItem::focusOutEvent(event);
}

void Sqrt::processHeightData()
{

}


void Sqrt::infoCome(int value)
{

}
