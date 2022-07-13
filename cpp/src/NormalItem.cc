#include "NormalItem.h"


void NormalItem::updateSellIn()
{
    item.sellIn = item.sellIn - 1;
}

void NormalItem::updateQuality()
{
    if (item.quality > 0)
    {
        item.quality = item.quality - 1;
    }

    if (item.sellIn < 0)
    {
        if (item.quality > 0)
        {
            item.quality = item.quality - 1;
        }
    }
}
