#include "include/add.h"

Add::Add():Math(ITEM_TYPE::Add_Math)
{
    _add = new AddWidget;
    connect(_add,SIGNAL(infoConfirm(int)),this,SLOT(infoCome(int)));
}

QRectF Add::boundingRect() const
{
    return QRectF(0,0,100,200);
}

void Add::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(focused){
        painter->setPen(Qt::green);
        painter->drawRect(0,0,100,200);
        QBrush brush(QColor(255,0,0,100));
        painter->fillRect(QRect(0,0,100,200),brush);
    }
    else
    {
        QRectF rec1(0,0,100,50);
        QImage image(":/image/resource/image/item/add.jpg");
        painter->drawImage(rec1,image);

        QRectF rec2(0,50,100,150);
        QBrush brush(QColor(30,40,50,50));
        painter->fillRect(rec2,brush);

        painter->setPen(Qt::green);
        painter->drawEllipse(2,68,5,5);

        painter->drawText(10,70,"hello");
    }
}

void Add::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
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
    BezierLine *input = m_inLineList.at(0);
    CImg<unsigned char> data = input->getData();
    if(!data.is_empty()){
        m_heightData.assign(512,512,1,1);
        for (int i = 0; i < 512; i++){
            for (int j = 0; j < 512; j++){
                m_heightData(i, j, 0, 0) = data.atXYZC(i,j,0,0)+_value;
            }
        }
    }
    emit heightDataReady(m_heightData);
}

void Add::infoCome(int value)
{
    this->_value = value;
}

