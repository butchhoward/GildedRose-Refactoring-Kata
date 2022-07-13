#ifndef SULFURAS_ITEM_H
#define SULFURAS_ITEM_H
#include "NamedItem.h"

class SulfurasItem : public NamedItem
{
public:
    SulfurasItem(const Item& item) :
        NamedItem("Sulfuras, Hand of Ragnaros", item.sellIn, item.quality)
        {
        }

    SulfurasItem(int sellIn, int quality) :
        NamedItem("Sulfuras, Hand of Ragnaros", sellIn, quality)
        {
        }

    virtual void updateQuality()
    {
    }

};

#endif
