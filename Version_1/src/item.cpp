#include "include/item.h"

Item::Item(ITEM_TYPE type,QGraphicsItem *parent):m_type(type),QGraphicsItem(parent)
{

}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void Item::setName(QString name)
{
    m_name = name;
}

QString Item::getName() const
{
    return m_name;
}

ITEM_TYPE Item::getType() const
{
    return m_type;
}

void Item::heightDataProcess()
{

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

