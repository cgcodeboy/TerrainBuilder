#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QDebug>
#include <itemfactory.h>

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
