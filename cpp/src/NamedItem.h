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
    void updateItem();


    operator Item() const
    {
        return item;
    }

protected:
    virtual void updateQuality() {};
    virtual void updateSellIn() {}


    Item item;
};

#endif
