#ifndef AGEDBRIE_ITEM_H
#define AGEDBRIE_ITEM_H
#include "NamedItem.h"

#define ITEM_NAME "Aged Brie"

class AgedBrieItem : public NamedItem
{
public:
    AgedBrieItem(const Item& item) :
        NamedItem(ITEM_NAME, item.sellIn, item.quality)
        {
        }

    AgedBrieItem(int sellIn, int quality) :
        NamedItem(ITEM_NAME, sellIn, quality)
        {
        }
    virtual ~AgedBrieItem()
    {

    }

    virtual void updateQuality()
    {
        if (item.quality < 50)
        {
            item.quality = item.quality + 1;
        }

        item.sellIn = item.sellIn - 1;

        if (item.sellIn < 0)
        {
            if (item.quality < 50)
            {
                item.quality = item.quality + 1;
            }
        }
    }

};


#endif
