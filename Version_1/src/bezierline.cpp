#include "include/bezierline.h"

BezierLine::BezierLine(QPoint startPoint, QPoint endPoint, QPoint controlPoint_1, QPoint controlPoint_2, QGraphicsItem *parent):
   QGraphicsItem(parent),_startPoint(startPoint),_endPoint(endPoint),_controlPoint_1(controlPoint_1),_controlPoint_2(controlPoint_2)
{
    qDebug()<<"start:"<<_startPoint.x()<<_startPoint.y();
}

void BezierLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPainterPath myPath;
    painter->setPen(Qt::red);
    myPath.moveTo(_startPoint);
    myPath.cubicTo(_controlPoint_1, _controlPoint_2, _endPoint);
    painter->drawPath(myPath);
}

QRectF BezierLine::boundingRect() const
{
    if(_startPoint.x()<_endPoint.x()&&_startPoint.y()<_endPoint.y())
        return QRect(_startPoint,_endPoint);
    else if(_startPoint.x()<_endPoint.x()&&_startPoint.y()>_endPoint.y())
        return QRect(QPoint(_startPoint.x(),_endPoint.y()),QPoint(_endPoint.x(),_startPoint.y()));
    else if(_startPoint.x()>_endPoint.x()&&_startPoint.y()<_endPoint.y())
        return QRect(QPoint(_endPoint.x(),_startPoint.y()),QPoint(_startPoint.x(),_endPoint.y()));
    else
        return QRect(_endPoint,_startPoint);
}

CImg<unsigned char> &BezierLine::getData() const
{
    return this->m_heightData;
}

void BezierLine::dataCome(CImg<unsigned char> data)
{
    m_heightData.assign(512,512,1,1);
    for (int i = 0; i < 512; i++){
        for (int j = 0; j < 512; j++){
            m_heightData(i, j, 0, 0) = data.atXYZC(i,j,0,0);
        }
    }
    emit dataReady();
}

void BezierLine::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void BezierLine::focusInEvent(QFocusEvent *event)
{
    QGraphicsItem::focusInEvent(event);
    qDebug()<<"focus in";
}

void BezierLine::focusOutEvent(QFocusEvent *event)
{
    QGraphicsItem::focusOutEvent(event);
    qDebug()<<"focus out";
}
