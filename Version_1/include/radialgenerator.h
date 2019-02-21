#ifndef RADIALGENERATOR_H
#define RADIALGENERATOR_H

#include <include/generator.h>
#include <include/radialwidget.h>

class RadialGenerator : public Generator
{
    Q_OBJECT
public:
    RadialGenerator();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    virtual void heightDataProcess();

    CImg<unsigned char> m_heightData;
    RadialWidget* _radial;
    int _radius;
    int _type;

private slots:
    void infoCome(int radius, int radial_type);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // RADIALGENERATOR_H
