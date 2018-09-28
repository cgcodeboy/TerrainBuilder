#ifndef OUTPUT_H
#define OUTPUT_H

#include <header/item.h>

class Output : public Item
{
public:
    Output();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void setName(QString name);
protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // OUTPUT_H
