#ifndef BACKSTAGEPASSES_ITEM_H
#define BACKSTAGEPASSES_ITEM_H
#include "NamedItem.h"



class BackstagePassesItem : public NamedItem
{
public:
    BackstagePassesItem(const Item& item) :
        NamedItem(ITEM_NAME, item.sellIn, item.quality)
        {
        }

    BackstagePassesItem(int sellIn, int quality) :
        NamedItem(ITEM_NAME, sellIn, quality)
        {
        }
    virtual ~BackstagePassesItem()
    {

    }

    virtual void updateQuality()
    {
        if (item.quality < 50)
        {
            item.quality = item.quality + 1;

            if (item.sellIn < 11)
            {
                if (item.quality < 50)
                {
                    item.quality = item.quality + 1;
                }
            }

            if (item.sellIn < 6)
            {
                if (item.quality < 50)
                {
                    item.quality = item.quality + 1;
                }
            }
        }

        item.sellIn = item.sellIn - 1;

        if (item.sellIn < 0)
        {
            item.quality = item.quality - item.quality;
        }
    }

    static std::string ITEM_NAME;

};



#endif
