/*----------------------------------------------------------------------
Copyright [09.28.2018] by [cgcodeboy]
Distributed under the LGPL License(http://www.gnu.org/licenses/lgpl.html)
-----------------------------------------------------------------------*/
#ifndef ITEM_H
#define ITEM_H


#include <math.h>
#define _USE_MATH_DEFINES

#include <QGraphicsItem>
#include <QDebug>
#include <QPainter>
#include <QString>
#include <QList>
#include <include/bezierline.h>

#include <CImg.h>

using namespace cimg_library;
#define cimg_use_bmp

enum ITEM_TYPE{
    Arrow,
    Connect,
    Layout_Generator,
    Perlin_Generator,
    Constant_Generator,
    Gradient_Generator,
    Radial_Generator,
    Voronoi_Generator,
    Simple_Combiner,
    Constraint_Combiner,
    Blur_Filter,
    Clamp_Filter,
    Noise_Filter,
    Terrace_Filter,
    Add_Math,
    Subtract_Math,
    Multiply_Math,
    Divide_Math,
    Invert_Math,
    Sqrt_Math,
    WaterErosion_Nature,
    ThermalErosion_Nature,
    Height_Output,
    Texture_Output
};

const QString TYPE_NAMES[] = {    "Arrow",
                                "Connect",
                                "Layout_Generator",
                                "Perlin_Generator",
                                "Constant_Generator",
                                "Gradient_Generator",
                                "Radial_Generator",
                                "Voronoi_Generator",
                                "Simple_Combiner",
                                "Constraint_Combiner",
                                "Blur_Filter",
                                "Clamp_Filter",
                                "Noise_Filter",
                                "Terrace_Filter",
                                "Add_Math",
                                "Subtract_Math",
                                "Multiply_Math",
                                "Divide_Math",
                                "Invert_Math",
                                "Sqrt_Math",
                                "WaterErosion_Nature",
                                "ThermalErosion_Nature",
                                "Height_Output",
                                "Texture_Output"
                           };

QString getElemTypeName(ITEM_TYPE type);


class Item :public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Item(ITEM_TYPE type,QGraphicsItem *parent = 0);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setName(QString name);
    QString getName() const;

    ITEM_TYPE getType() const;
private:
    virtual void processHeightData();
    ITEM_TYPE m_type;

signals:
    void heightDataReady(const CImg<unsigned char>&);
    void textureDataReady(const CImg<unsigned char>&);


protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);

    bool focused;
    QString m_name;
    QList<BezierLine*> m_inLineList;
    QList<BezierLine*> m_outLineList;
};

#endif // ITEM_H
