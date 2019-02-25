#include "include/layoutgenerator.h"

LayoutGenerator::LayoutGenerator():Generator(ITEM_TYPE::Layout_Generator)
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);

    _layout = new LayoutWidget;
}

QRectF LayoutGenerator::boundingRect() const
{
    return QRectF(0,0,150,70);
}

void LayoutGenerator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ItemDrawMaster *drawMaster = new ItemDrawMaster(getType(),painter,focused);
    drawMaster->draw();
}

void LayoutGenerator::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    _layout->show();
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void LayoutGenerator::focusInEvent(QFocusEvent *event)
{
    focused = true;
    update();
    QGraphicsItem::focusInEvent(event);
}

void LayoutGenerator::focusOutEvent(QFocusEvent *event)
{
    focused = false;
    update();
    QGraphicsItem::focusOutEvent(event);
}

