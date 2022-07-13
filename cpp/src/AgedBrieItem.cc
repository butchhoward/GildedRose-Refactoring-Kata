#include "AgedBrieItem.h"

std::string AgedBrieItem::ITEM_NAME = "Aged Brie";

void AgedBrieItem::updateQuality()
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

void AgedBrieItem::updateSellIn()
{

}
