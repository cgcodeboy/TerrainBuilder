#ifndef ITEMCOLLECTOR_H
#define ITEMCOLLECTOR_H

#include <list>
#include <include/item.h>
#include <include/generator.h>
#include <include/combiner.h>
#include <include/filter.h>
#include <include/math.h>
#include <include/nature.h>
#include <include/output.h>

using namespace std;

class ItemCollector
{
public:
    static ItemCollector* getInstance();

    void addItem(Item* item);

private:
    list<Generator*>* _generatorList;
    list<Combiner*>* _combinerList;
    list<Filter*>* _filterList;
    list<Math*>* _mathList;
    list<Nature*>* _natureList;
    list<Output*>* _outputList;

    ItemCollector();

    static ItemCollector* _collector;
};

#endif // ITEMCOLLECTOR_H
