#include "header/itemfactory.h"

ItemFactory::ItemFactory()
{

}

Item *ItemFactory::buildItem(ITEM_TYPE type)
{
    Item *item;
    switch (type) {
    case ITEM_TYPE::Constant_Generator:{
        item = new ConstantGenerator();
        break;
    }
    case ITEM_TYPE::Layout_Generator:{
        item = new LayoutGenerator();
        break;
    }
    case ITEM_TYPE::Perlin_Generator:{
        item = new PerlinGenerator();
        break;
    }
    case ITEM_TYPE::Gradient_Generator:{
        item = new GradientGenerator();
        break;
    }
    default:
        break;
    }
    return item;
}

Item *ItemFactory::buildItem(ITEM_TYPE type, QString name)
{
    Item *item = buildItem(type);
    item->setName(name);
    return item;
}

Item *ItemFactory::buildItem(ITEM_TYPE type, int x, int y)
{
    Item *item = buildItem(type);
    item->setPos(x,y);
    return item;
}

Item *ItemFactory::buildItem(ITEM_TYPE type, QString name, int x, int y)
{
    Item *item = buildItem(type);
    item->setName(name);
    item->setPos(x,y);
    return item;
}

