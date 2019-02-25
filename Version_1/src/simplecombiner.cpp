#include "include/simplecombiner.h"

SimpleCombiner::SimpleCombiner():Combiner(ITEM_TYPE::Simple_Combiner)
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);
}

QRectF SimpleCombiner::boundingRect() const
{
    return QRectF(0,0,150,90);
}

void SimpleCombiner::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ItemDrawMaster *drawMaster = new ItemDrawMaster(getType(),painter,focused);
    drawMaster->draw();
}

void SimpleCombiner::heightDataProcess()
{
    for(int i = 0;i<255;i++)
        for(int j = 0;j<255;j++)
            outputHeightData(i,j,0,0) = (inputHeightData_1(i,j,0,0) + inputHeightData_1(i,j,0,0))/2;
}

void SimpleCombiner::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void SimpleCombiner::focusInEvent(QFocusEvent *event)
{
    focused = true;
    update();
    QGraphicsItem::focusInEvent(event);
}

void SimpleCombiner::focusOutEvent(QFocusEvent *event)
{
    focused = false;
    update();
    QGraphicsItem::focusOutEvent(event);
}

