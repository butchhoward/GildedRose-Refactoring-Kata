#ifndef NORMAL_ITEM_H
#define NORMAL_ITEM_H
#include "NamedItem.h"

class NormalItem : public NamedItem
{
public:
    NormalItem(const Item& item) :
        NamedItem(item.name, item.sellIn, item.quality)
        {
        }

    virtual void updateQuality()
    {
        if (item.quality > 0)
        {
            item.quality = item.quality - 1;
        }

        item.sellIn = item.sellIn - 1;

        if (item.sellIn < 0)
        {
            if (item.quality > 0)
            {
                item.quality = item.quality - 1;
            }
        }
    }

};

#endif
