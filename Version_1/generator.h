#ifndef GENERATOR_H
#define GENERATOR_H

#include <item.h>

class Generator : public Item
{
public:
    Generator();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void setName(QString name);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // GENERATOR_H
