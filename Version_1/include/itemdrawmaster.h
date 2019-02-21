#ifndef ITEMDRAWMASTER_H
#define ITEMDRAWMASTER_H

#include <QRect>
#include <QPainter>
#include <QDomDocument>
#include <QFile>
#include <include/item.h>

class ItemDrawMaster
{
public:
    ItemDrawMaster(ITEM_TYPE type,QPainter *painter,bool focused);

    void draw();

private:
    QPainter *_painter;
    ITEM_TYPE _type;
    bool _focused;
};

#endif // ITEMDRAWMASTER_H
