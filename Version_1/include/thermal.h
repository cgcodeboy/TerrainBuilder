#ifndef THERMAL_EROSION_H
#define THERMAL_EROSION_H

#include <include/nature.h>
#include <include/itemdrawmaster.h>

class ThermalErosion : public Nature
{
public:
    ThermalErosion();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // THERMAL_H
