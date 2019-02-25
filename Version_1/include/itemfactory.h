/*----------------------------------------------------------------------
Copyright [09.28.2018] by [cgcodeboy]
Distributed under the LGPL License(http://www.gnu.org/licenses/lgpl.html)
-----------------------------------------------------------------------*/
#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <QGraphicsScene>
#include <include/constantgenerator.h>
#include <include/layoutgenerator.h>
#include <include/perlingenerator.h>
#include <include/gradientgenerator.h>
#include <include/radialgenerator.h>
#include <include/voronoigenerator.h>
#include <include/simplecombiner.h>
#include <include/constraintcombiner.h>
#include <include/add.h>
#include <include/subtract.h>
#include <include/multiply.h>
#include <include/divide.h>
#include <include/invert.h>
#include <include/blur.h>
#include <include/clamp.h>
#include <include/noise.h>
#include <include/terrace.h>
#include <include/water.h>
#include <include/thermal.h>
#include <include/heightoutput.h>
#include <include/textureoutput.h>

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
