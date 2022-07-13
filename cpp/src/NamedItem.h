#ifndef NAMEDITEM_H
#define NAMEDITEM_H
#include "GildedRose.h"

class NamedItem
{
public:
    NamedItem(string name, int sellIn, int quality) :
        item(name, sellIn, quality)
    {
    }

    virtual void updateQuality() = 0;

    operator Item() const
    {
        return item;
    }

protected:
    Item item;
};

#endif
