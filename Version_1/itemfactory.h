#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <QGraphicsScene>
#include <constantgenerator.h>
#include <layoutgenerator.h>
#include <perlingenerator.h>
#include <gradientgenerator.h>
#include <item.h>

class ItemFactory
{
public:
    ItemFactory();

    Item *buildItem(ITEM_TYPE type);

    Item *buildItem(ITEM_TYPE type,QString name);

    Item *buildItem(ITEM_TYPE type, int x, int y);

    Item *buildItem(ITEM_TYPE type,QString name,int x,int y);
};

#endif // ITEMFACTORY_H
