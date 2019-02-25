#ifndef WATER_EROSION_H
#define WATER_EROSION_H

#include <include/nature.h>
#include <include/itemdrawmaster.h>

class WaterErosion : public Nature
{
public:
    WaterErosion();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // WATER_H
