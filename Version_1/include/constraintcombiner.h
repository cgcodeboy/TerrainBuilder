/*----------------------------------------------------------------------
Copyright [09.28.2018] by [cgcodeboy]
Distributed under the LGPL License(http://www.gnu.org/licenses/lgpl.html)
-----------------------------------------------------------------------*/
#ifndef CONSTRAINTCombiner_H
#define CONSTRAINTCombiner_H

#include <include/combiner.h>
#include <include/constraintwidget.h>
#include <include/itemdrawmaster.h>

class ConstraintCombiner : public Combiner
{
    Q_OBJECT
public:
    ConstraintCombiner();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    virtual void heightDataProcess();

    CImg<unsigned char> inputHeightData_1;
    CImg<unsigned char> inputHeightData_2;
    CImg<unsigned char> outputHeightData;

    ConstraintWidget *_constraint;
    int _coeffcient;

private slots:
    void infoCome(int value);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // CONSTRAINTCombiner_H
