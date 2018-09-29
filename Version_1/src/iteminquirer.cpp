#include <include/iteminquirer.h>

ItemInquirer* ItemInquirer::m_inquier = 0;

ItemInquirer *ItemInquirer::getInstance()
{
    if(m_inquier == 0)
        return m_inquier;
    else{
        m_inquier = new ItemInquirer;
        return m_inquier;
    }
}

const ItemStruct *ItemInquirer::getParameters(ITEM_TYPE type)
{
    map<ITEM_TYPE, ItemStruct>::iterator iter;
    if((iter = inner_map.find(type))!=inner_map.end()){
        return &(iter->second);
    }
}

ItemInquirer::ItemInquirer()
{
    buildMap();
}

void ItemInquirer::buildMap()
{
    QDomDocument *xmlDoc;
    QFile file(":/xml/resource/xml/item.xml");
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    if (!xmlDoc->setContent(&file))
    {
        file.close();
        return;
    }
//    QDomNode *node_1 = xmlDoc->firstChild();
//    while (!node_1->isNull()) {
//        QDomElement element_1 = node_1->toElement();
//        if(element_1.tagName() == "Item"){
//            QDomNode node_2 = node_1->firstChild();
//        }

//    }
}
