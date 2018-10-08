/*----------------------------------------------------------------------
Copyright [09.28.2018] by [cgcodeboy]
Distributed under the LGPL License(http://www.gnu.org/licenses/lgpl.html)
-----------------------------------------------------------------------*/
#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsItem>
#include <QDebug>
#include <QPainter>
#include <QString>
#include <QList>

#include <CImg.h>

using namespace cimg_library;

enum ITEM_TYPE{
    Arrow,
    Connect,
    Layout_Generator,
    Perlin_Generator,
    Constant_Generator,
    Gradient_Generator,
    Radial_Generator,
    Voronoi_Generator,
    Simple_Conbiner,
    Constraint_Conbiner,
    Blur_Filter,
    Clamp_Filter,
    Noise_Filter,
    Terrace_Filter,
    Add_Math,
    Subtract_Math,
    Multiply_Math,
    Divide_Math,
    Invert_Math,
    WaterErosion_Nature,
    ThemalErosion_Nature,
    HeightField_Output,
    Texture_Output
};

class Item :public QObject, public QGraphicsItem
{
public:
    Item(ITEM_TYPE type,QGraphicsItem *parent = 0);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setName(QString name);
    QString getName() const;

    ITEM_TYPE getType() const;
private:
    virtual void heightDataProcess();
    ITEM_TYPE m_type;

signals:
    void heightDataReady(CImg<unsigned char>);
    void textureDataReady(CImg<unsigned char>);


protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);

    bool focused;
    QString m_name;
    QList<QGraphicsLineItem*> m_inLineList;
    QList<QGraphicsLineItem*> m_outLineList;
};

#endif // ITEM_H
