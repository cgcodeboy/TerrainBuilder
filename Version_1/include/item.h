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

enum ITEM_TYPE{
    Arrow,
    Connect,
    Layout_Generator,
    Perlin_Generator,
    Constant_Generator,
    Gradient_Generator,
    Radial_Generator,
    Voronoi_Generator
};

class Item : public QGraphicsItem
{
public:
    Item(QGraphicsItem *parent = 0);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setName(QString name);
private:
    QString m_name;


protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);

    bool focused;
};

#endif // ITEM_H
