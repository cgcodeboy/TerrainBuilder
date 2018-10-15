#ifndef BEZIERLINE_H
#define BEZIERLINE_H

#include <QObject>
#include <QPainter>
#include <QDebug>
#include <QGraphicsItem>
#include <CImg.h>

using namespace cimg_library;

class BezierLine : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit BezierLine(QPoint startPoint,QPoint endPoint,QPoint controlPoint_1,QPoint controlPoint_2,QGraphicsItem *parent = 0);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;

    CImg<unsigned char>& getData() const;

signals:
    void dataReady();

public slots:
    void dataCome(CImg<unsigned char> data);

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void focusInEvent(QFocusEvent *event);
    void focusOutEvent(QFocusEvent *event);

private:
    QPoint _startPoint,_endPoint,_controlPoint_1,_controlPoint_2;
    CImg<unsigned char> m_heightData;
};

#endif // BEZIERLINE_H
