#include "GildedRose.h"

static const char* SULFRAS="Sulfuras, Hand of Ragnaros";
static const char* AGED_BRIE="Aged Brie";
static const char* TAFKAL80ETC="Backstage passes to a TAFKAL80ETC concert";


GildedRose::GildedRose(vector<Item> & items) : items(items)
{}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        updateItemQuality(items[i]);
    }
}

void UpdateNormalItemQuality(Item& item)
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

void UpdateSulfurasQuality(Item& item)
{
}

void UpdateAgedBrieQuality(Item& item)
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

void UpdateTAFKAL80ETCQuality(Item &item)
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

void GildedRose::updateItemQuality(Item& item)
{
        if (item.name == SULFRAS)
        {
            return UpdateSulfurasQuality(item);
        }

        if (item.name == AGED_BRIE)
        {
            return UpdateAgedBrieQuality(item);
        }

        if (item.name == TAFKAL80ETC)
        {
            return UpdateTAFKAL80ETCQuality(item);
        }

        return UpdateNormalItemQuality(item);


        if (item.name != AGED_BRIE && item.name != TAFKAL80ETC)
        {
            if (item.quality > 0)
            {
                item.quality = item.quality - 1;
            }
        }
        else
        {
            if (item.quality < 50)
            {
                item.quality = item.quality + 1;

                if (item.name == TAFKAL80ETC)
                {
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
            }
        }

        item.sellIn = item.sellIn - 1;

        if (item.sellIn < 0)
        {
            if (item.name != AGED_BRIE)
            {
                if (item.name != TAFKAL80ETC)
                {
                    if (item.quality > 0)
                    {
                        item.quality = item.quality - 1;
                    }
                }
                else
                {
                    item.quality = item.quality - item.quality;
                }
            }
            else
            {
                if (item.quality < 50)
                {
                    item.quality = item.quality + 1;
                }
            }
        }
}
