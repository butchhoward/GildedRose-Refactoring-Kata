#include "BackstagePassesItem.h"

std::string BackstagePassesItem::ITEM_NAME = "Backstage passes to a TAFKAL80ETC concert";


void BackstagePassesItem::updateQuality()
{
    if (item.quality < 50)
    {
        item.quality = item.quality + 1;

        if (item.sellIn < 10)
        {
            if (item.quality < 50)
            {
                item.quality = item.quality + 1;
            }
        }

        if (item.sellIn < 5)
        {
            if (item.quality < 50)
            {
                item.quality = item.quality + 1;
            }
        }
    }


    if (item.sellIn < 0)
    {
        item.quality = item.quality - item.quality;
    }
}

void BackstagePassesItem::updateSellIn()
{
    item.sellIn = item.sellIn - 1;
}
