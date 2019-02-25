#include "include/itemfactory.h"

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
    case ITEM_TYPE::Radial_Generator:{
        item = new RadialGenerator();
        break;
    }
    case ITEM_TYPE::Voronoi_Generator:{
        item = new VoronoiGenerator();
        break;
    }
    case ITEM_TYPE::Simple_Combiner:{
        item = new SimpleCombiner();
        break;
    }
    case ITEM_TYPE::Constraint_Combiner:{
        item = new ConstraintCombiner();
        break;
    }
    case ITEM_TYPE::Add_Math:{
        item = new Add();
        break;
    }
    case ITEM_TYPE::Subtract_Math:{
        item = new Subtract();
        break;
    }
    case ITEM_TYPE::Multiply_Math:{
        item = new Multiply();
        break;
    }
    case ITEM_TYPE::Divide_Math:{
        item = new Divide();
        break;
    }
    case ITEM_TYPE::Invert_Math:{
        item = new Invert();
        break;
    }
    case ITEM_TYPE::Blur_Filter:{
        item = new Blur();
        break;
    }
    case ITEM_TYPE::Noise_Filter:{
        item = new Noise();
        break;
    }
    case ITEM_TYPE::Clamp_Filter:{
        item = new Clamp();
        break;
    }
    case ITEM_TYPE::Terrace_Filter:{
        item = new Terrace();
        break;
    }
    case ITEM_TYPE::WaterErosion_Nature:{
        item = new WaterErosion();
        break;
    }
    case ITEM_TYPE::ThermalErosion_Nature:{
        item = new ThermalErosion();
        break;
    }
    case ITEM_TYPE::Height_Output:{
        item = new HeightOutput();
        break;
    }
    case ITEM_TYPE::Texture_Output:{
        item = new TextureOutput();
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

