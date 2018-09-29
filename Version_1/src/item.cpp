#include "include/item.h"

Item::Item(QGraphicsItem *parent):QGraphicsItem(parent)
{

}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void Item::setName(QString name)
{
    m_name = name;
}

void Item::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"mouse double click";
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void Item::focusInEvent(QFocusEvent *event)
{
    qDebug()<<"focus in";
    QGraphicsItem::focusInEvent(event);
}

void Item::focusOutEvent(QFocusEvent *event)
{
    qDebug()<<"focus out";
    QGraphicsItem::focusOutEvent(event);
}

