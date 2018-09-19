#include "perlingenerator.h"

PerlinGenerator::PerlinGenerator()
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);
}

QRectF PerlinGenerator::boundingRect() const
{
    return QRectF(0,0,60,40);
}

void PerlinGenerator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    if(focused){
        painter->setPen(Qt::green);
        painter->drawRect(0,0,60,40);
        QBrush brush(QColor(255,0,0,100));
        painter->fillRect(QRect(0,0,60,40),brush);
    }
    else
    {
        QImage image(":/image/resource/image/mountain_3.bmp");
        painter->drawImage(rect,image);
    }

    painter->drawRect(rect);
}

void PerlinGenerator::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void PerlinGenerator::focusInEvent(QFocusEvent *event)
{
    focused = true;
    update();
    QGraphicsItem::focusInEvent(event);
}

void PerlinGenerator::focusOutEvent(QFocusEvent *event)
{
    focused = false;
    update();
    QGraphicsItem::focusOutEvent(event);
}

