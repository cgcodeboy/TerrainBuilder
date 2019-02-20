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
    PerlinWidget* _perlin;
    PerlinNoise* noise;

    static int counterNum;
    int _number;

private slots:
    void infoCome(float persistence,float frequency,float amplitude,int octaves,int randomseed);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // PERLIN_GRNERATOR_H
