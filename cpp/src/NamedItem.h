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
    virtual void updateQuality() = 0;
    virtual void updateSellIn() = 0;


    Item item;
};

#endif
