#ifndef TERRACE_H
#define TERRACE_H

#include <include/filter.h>
#include <include/itemdrawmaster.h>

class Terrace : public Filter
{
public:
    Terrace();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // TERRACE_H
