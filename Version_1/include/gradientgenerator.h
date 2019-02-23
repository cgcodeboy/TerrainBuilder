/*----------------------------------------------------------------------
Copyright [09.28.2018] by [cgcodeboy]
Distributed under the LGPL License(http://www.gnu.org/licenses/lgpl.html)
-----------------------------------------------------------------------*/
#ifndef GRADIENT_GRNERATOR_H
#define GRADIENT_GRNERATOR_H

#include <include/generator.h>
#include <include/gradientwidget.h>

class GradientGenerator : public Generator
{
    Q_OBJECT
public:
    GradientGenerator();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    virtual void heightDataProcess();

    CImg<unsigned char> m_heightData;
    GradientWidget *_gradient;
    int _width;
    int _direction;

private slots:
    void infoCome(int direction, int width);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // GRADIENT_GRNERATOR_H
