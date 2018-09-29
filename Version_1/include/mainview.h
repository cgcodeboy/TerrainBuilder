/*----------------------------------------------------------------------
Copyright [09.28.2018] by [cgcodeboy]
Distributed under the LGPL License(http://www.gnu.org/licenses/lgpl.html)
-----------------------------------------------------------------------*/
#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QDebug>
#include <QQmlEngine>
#include <QQmlComponent>
#include <include/itemfactory.h>

using namespace std;

class MainView : public QGraphicsView
{
    Q_OBJECT
public:
    MainView(QWidget *parent);

    QGraphicsScene *getScene() const;

    void setCur_type(const ITEM_TYPE type);

    void initBluePrint();

private:
    QGraphicsScene *scene;
    ITEM_TYPE cur_type;
    QGraphicsItem* startItem;
    QGraphicsItem* endItem;
    ItemFactory *itembuilder;
    bool connectState;

    virtual void mousePressEvent(QMouseEvent * event);

private slots:
    void addItem(ITEM_TYPE type, int x, int y);
};

#endif // MAINVIEW_H
