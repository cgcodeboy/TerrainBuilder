#ifndef NOISE_H
#define NOISE_H

#include <include/filter.h>
#include <include/itemdrawmaster.h>


class Noise : public Filter
{
public:
    Noise();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // NOISE_H
