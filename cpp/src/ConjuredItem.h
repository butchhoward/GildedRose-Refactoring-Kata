#ifndef CONJURED_ITEM_H
#define CONJURED_ITEM_H
#include "NamedItem.h"

class ConjuredItem : public NamedItem
{
public:
    ConjuredItem(const Item& item) :
        NamedItem("Conjured", item.sellIn, item.quality)
        {
        }

    ConjuredItem(int sellIn, int quality) :
        NamedItem("Conjured", sellIn, quality)
        {
        }

    virtual ~ConjuredItem()
    {

    }

    void updateQuality()
    {
        if (item.quality > 0)
        {
            item.quality = item.quality - 2;
        }

        item.sellIn = item.sellIn - 1;

        if (item.sellIn < 0)
        {
            if (item.quality > 0)
            {
                item.quality = item.quality - 2;
            }
        }

    }
};

#endif
