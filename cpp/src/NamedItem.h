#ifndef NAMEDITEM_H
#define NAMEDITEM_H
#include "Item.h"
#include <string>


class NamedItem
{
public:
    NamedItem(std::string name, int sellIn, int quality) :
        item(name, sellIn, quality)
    {
    }
    virtual ~NamedItem()
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
