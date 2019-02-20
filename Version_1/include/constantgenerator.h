/*----------------------------------------------------------------------
Copyright [09.28.2018] by [cgcodeboy]
Distributed under the LGPL License(http://www.gnu.org/licenses/lgpl.html)
-----------------------------------------------------------------------*/
#ifndef CONSTANT_GRNERATOR_H
#define CONSTANT_GRNERATOR_H

#include <include/generator.h>
#include <include/constantwidget.h>

class ConstantGenerator : public Generator
{
    Q_OBJECT
public:
    ConstantGenerator();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    virtual void heightDataProcess();

    CImg<unsigned char> m_heightData;

    ConstantWidget *_constant;

    int _constantValue;

    static int counterNum;
    int _number;

private slots:
    void infoCome(int value);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // CONSTANT_GRNERATOR_H
