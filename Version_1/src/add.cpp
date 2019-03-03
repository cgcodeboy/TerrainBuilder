#include "include/add.h"

Add::Add():Math(ITEM_TYPE::Add_Math)
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);

    _add = new AddWidget;
    connect(_add,SIGNAL(infoConfirm(int)),this,SLOT(infoCome(int)));
}

QRectF Add::boundingRect() const
{
    return QRectF(0,0,150,90);
}

void Add::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ItemDrawMaster *drawMaster = new ItemDrawMaster(getType(),painter,focused);
    drawMaster->draw();
}

void Add::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    _add->show();
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void Add::focusInEvent(QFocusEvent *event)
{
    focused = true;
    update();
    QGraphicsItem::focusInEvent(event);
}

void Add::focusOutEvent(QFocusEvent *event)
{
    focused = false;
    update();
    QGraphicsItem::focusOutEvent(event);
}

void Add::processHeightData()
{
    //BezierLine *input = m_inLineList.at(0);
    //CImg<unsigned char> data = input->getData();
    //if(!data.is_empty()){
        m_heightData.assign(512,512,1,1);
        for (int i = 0; i < 512; i++){
            for (int j = 0; j < 512; j++){
                m_heightData(i, j, 0, 0) += _addValue;
            }
        }
    //}
    //emit heightDataReady(m_heightData);
}

void Add::infoCome(int value)
{
    this->_addValue = value;
    processHeightData();
}

