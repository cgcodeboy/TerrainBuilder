#include "include/itemcollector.h"

ItemCollector *ItemCollector::_collector = 0;

ItemCollector::ItemCollector()
{
    list<Generator*>* _generatorList = new list<Generator*>;
    list<Combiner*>* _combinerList = new list<Combiner*>;
    list<Filter*>* _filterList = new list<Filter*>;
    list<Math*>* _mathList = new list<Math*>;
    list<Nature*>* _natureList = new list<Nature*>;
    list<Output*>* _outputList = new list<Output*>;
}


ItemCollector *ItemCollector::getInstance()
{
    if(_collector == 0)
        _collector = new ItemCollector;
    return _collector;
}

void ItemCollector::addItem(Item *item)
{
    if(item == 0){
        return;
    }
    switch (item->getType()) {
    case ITEM_TYPE::Perlin_Generator:
    case ITEM_TYPE::Gradient_Generator:
    case ITEM_TYPE::Constant_Generator:
    case ITEM_TYPE::Layout_Generator:
    case ITEM_TYPE::Radial_Generator:
    case ITEM_TYPE::Voronoi_Generator:{
        _generatorList->push_back(dynamic_cast<Generator*>(item));
        break;
    }
    case ITEM_TYPE::Simple_Combiner:
    case ITEM_TYPE::Constraint_Combiner:{
        _combinerList->push_back(dynamic_cast<Combiner*>(item));
        break;
    }
    case ITEM_TYPE::Blur_Filter:
    case ITEM_TYPE::Clamp_Filter:
    case ITEM_TYPE::Noise_Filter:
    case ITEM_TYPE::Terrace_Filter:{
        _filterList->push_back(dynamic_cast<Filter*>(item));
        break;
    }
    case ITEM_TYPE::Add_Math:
    case ITEM_TYPE::Subtract_Math:
    case ITEM_TYPE::Multiply_Math:
    case ITEM_TYPE::Divide_Math:
    case ITEM_TYPE::Invert_Math:{
        _mathList->push_back(dynamic_cast<Math*>(item));
        break;
    }
    case ITEM_TYPE::WaterErosion_Nature:
    case ITEM_TYPE::ThemalErosion_Nature:{
        _natureList->push_back(dynamic_cast<Nature*>(item));
        break;
    }
    case ITEM_TYPE::HeightField_Output:
    case ITEM_TYPE::Texture_Output:{
        _outputList->push_back(dynamic_cast<Output*>(item));
        break;
    }
    default:
        break;
    }
}
