#ifndef LAYOUT_GRNERATOR_H
#define LAYOUT_GRNERATOR_H

#include <generator.h>

class LayoutGenerator : public Generator
{
public:
    LayoutGenerator();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    bool focused;
protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // LAYOUT_GRNERATOR_H
