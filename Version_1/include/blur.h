#ifndef BLUR_H
#define BLUR_H

#include <include/filter.h>
#include <include/blurwidget.h>
#include <include/itemdrawmaster.h>

class Complex{
public:
    double real;
    double imag;
    Complex(double _real = 0,double _imag = 0){
        real = _real;
        imag = _imag;
    }
};

class Blur : public Filter
{
public:
    Blur();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    BlurWidget *_blur;
    int _type;
    CImg<unsigned char> m_heightData;

    virtual void processHeightData();

private slots:
    void infoCome(int type);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // BLUR_H
