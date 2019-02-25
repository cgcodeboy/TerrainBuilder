#include "include/heightoutput.h"

HeightOutput::HeightOutput():Output(ITEM_TYPE::Height_Output)
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);
}

QRectF HeightOutput::boundingRect() const
{
    return QRectF(0,0,150,70);
}

void HeightOutput::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ItemDrawMaster *drawMaster = new ItemDrawMaster(getType(),painter,focused);
    drawMaster->draw();
}

void HeightOutput::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{

}

void HeightOutput::focusInEvent(QFocusEvent *event)
{

}

void HeightOutput::focusOutEvent(QFocusEvent *event)
{

}

