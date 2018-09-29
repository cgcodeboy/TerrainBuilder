#ifndef ITEMINQUIRER
#define ITEMINQUIRER

#include <include/item.h>
#include <map>
#include <list>
#include <string>

#include <QDomDocument>
#include <QFile>

using namespace std;

struct ItemStruct{
    list<string> input_parameter_list;
    list<string> output_parameter_list;
};

class ItemInquirer{
public:
    static ItemInquirer* getInstance();

    const ItemStruct *getParameters(ITEM_TYPE type);

private:
    ItemInquirer(const ItemInquirer&);
    ItemInquirer& operator=(const ItemInquirer&);

    ItemInquirer();
    ~ItemInquirer();

    void buildMap();

    static ItemInquirer* m_inquier;

    map<ITEM_TYPE,ItemStruct> inner_map;
};

#endif // ITEMINQUIRER

