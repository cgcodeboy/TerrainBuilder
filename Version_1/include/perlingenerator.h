/*----------------------------------------------------------------------
Copyright [09.28.2018] by [cgcodeboy]
Distributed under the LGPL License(http://www.gnu.org/licenses/lgpl.html)
-----------------------------------------------------------------------*/
#ifndef PERLIN_GRNERATOR_H
#define PERLIN_GRNERATOR_H

#include <include/generator.h>
#include <include/perlinwidget.h>
#include <include/perlinnoise.h>

class PerlinGenerator: public Generator
{
    Q_OBJECT
public:
    PerlinGenerator();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    virtual void heightDataProcess();

    CImg<unsigned char> m_heightData;

    float _persistence;
    int _octaves;

    PerlinWidget* _perlin;

    static int counterNum;

private slots:
    void infoCome(float persistence,int octaves);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // PERLIN_GRNERATOR_H
