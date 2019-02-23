/*----------------------------------------------------------------------
Copyright [09.28.2018] by [cgcodeboy]
Distributed under the LGPL License(http://www.gnu.org/licenses/lgpl.html)
-----------------------------------------------------------------------*/
#ifndef SIMPLECOMBINER_H
#define SIMPLECOMBINER_H

#include <include/combiner.h>

class SimpleCombiner : public Combiner
{
public:
    SimpleCombiner();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    virtual void heightDataProcess();

    CImg<unsigned char> inputHeightData_1;
    CImg<unsigned char> inputHeightData_2;
    CImg<unsigned char> outputHeightData;

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // SIMPLECOMBINER_H
