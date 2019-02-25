/*----------------------------------------------------------------------
Copyright [09.28.2018] by [cgcodeboy]
Distributed under the LGPL License(http://www.gnu.org/licenses/lgpl.html)
-----------------------------------------------------------------------*/
#ifndef CONSTRAINTCombiner_H
#define CONSTRAINTCombiner_H

#include <include/combiner.h>
#include <include/itemdrawmaster.h>

class ConstraintCombiner : public Combiner
{
public:
    ConstraintCombiner();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // CONSTRAINTCombiner_H
