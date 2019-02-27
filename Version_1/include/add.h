#ifndef ADD_H
#define ADD_H

#include <include/math.h>
#include <include/addwidget.h>
#include <include/itemdrawmaster.h>

class Add : public Math
{
    Q_OBJECT
public:
    Add();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);

private:
    AddWidget *_add;
    int _addValue;
    CImg<unsigned char> m_heightData;

    virtual void processHeightData();

private slots:
    void infoCome(int value);
};

#endif // ADD_H
