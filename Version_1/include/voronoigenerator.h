#ifndef VORONOIGENERATOR_H
#define VORONOIGENERATOR_H

#include <include/generator.h>
#include <include/voronoiwidget.h>

#include <vector>

class VoronoiGenerator : public Generator
{
    Q_OBJECT
public:
    VoronoiGenerator();

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    virtual void heightDataProcess();

    CImg<unsigned char> m_heightData;
    VoronoiWidget *_voronoi;

    int _number;

private slots:
    void infoCome(int number);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // VORONOIGENERATOR_H
