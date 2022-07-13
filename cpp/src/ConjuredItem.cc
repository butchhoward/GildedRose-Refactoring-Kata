#include "ConjuredItem.h"


std::string ConjuredItem::ITEM_NAME = "Conjured";

void ConjuredItem::updateQuality()
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
