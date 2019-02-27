#include "include/constraintcombiner.h"

ConstraintCombiner::ConstraintCombiner():Combiner(ITEM_TYPE::Constraint_Combiner)
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);

    _constraint = new ConstraintWidget;
    connect(_constraint,SIGNAL(infoConfirm(int)),this,SLOT(infoCome(int)));
}

QRectF ConstraintCombiner::boundingRect() const
{
    return QRectF(0,0,150,90);
}

void ConstraintCombiner::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ItemDrawMaster *drawMaster = new ItemDrawMaster(getType(),painter,focused);
    drawMaster->draw();
}

void ConstraintCombiner::heightDataProcess()
{
    for(int i = 0;i<255;i++)
        for(int j = 0;j<255;j++)
            outputHeightData(i,j,0,0) = (inputHeightData_1(i,j,0,0)*_coeffcient + inputHeightData_1(i,j,0,0))*(1 - _coeffcient);
}

void ConstraintCombiner::infoCome(int value)
{
    _coeffcient = value;
}

void ConstraintCombiner::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    _constraint->show();
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void ConstraintCombiner::focusInEvent(QFocusEvent *event)
{
    focused = true;
    update();
    QGraphicsItem::focusInEvent(event);
}

void ConstraintCombiner::focusOutEvent(QFocusEvent *event)
{
    focused = false;
    update();
    QGraphicsItem::focusOutEvent(event);
}

