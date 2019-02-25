#ifndef SQRT_H
#define SQRT_H


#include <include/math.h>
#include <include/itemdrawmaster.h>

class Sqrt : public Math
{
    Q_OBJECT
public:
    Sqrt();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
    virtual void processHeightData();

private:
    CImg<unsigned char> m_heightData;

private slots:
    void infoCome(int value);
};

#endif // SQRT_H
