#include "include/subtract.h"

Subtract::Subtract():Math(ITEM_TYPE::Subtract_Math)
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);
}

QRectF Subtract::boundingRect() const
{
    return QRectF(0,0,150,90);
}

void Subtract::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ItemDrawMaster *drawMaster = new ItemDrawMaster(getType(),painter,focused);
    drawMaster->draw();
}

void Subtract::processHeightData()
{
    if(!data.is_empty()){
        m_heightData.assign(512,512,1,1);
        for (int i = 0; i < 512; i++){
            for (int j = 0; j < 512; j++){
                m_heightData(i, j, 0, 0) -= _subtractValue;
            }
        }
    }
}

void Subtract::infoCome(int value)
{
    _subtractValue = value;
    processHeightData();
}

void Subtract::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void Subtract::focusInEvent(QFocusEvent *event)
{
    focused = true;
    update();
    QGraphicsItem::focusInEvent(event);
}

void Subtract::focusOutEvent(QFocusEvent *event)
{
    focused = false;
    update();
    QGraphicsItem::focusOutEvent(event);
}

