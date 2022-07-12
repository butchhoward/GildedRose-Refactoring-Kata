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
        if (items[i].name != AGED_BRIE && items[i].name != TAFKAL80ETC)
        {
            if (items[i].quality > 0)
            {
                if (items[i].name != SULFRAS)
                {
                    items[i].quality = items[i].quality - 1;
                }
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                items[i].quality = items[i].quality + 1;

                if (items[i].name == TAFKAL80ETC)
                {
                    if (items[i].sellIn < 11)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }

                    if (items[i].sellIn < 6)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }
                }
            }
        }

        if (items[i].name != SULFRAS)
        {
            items[i].sellIn = items[i].sellIn - 1;
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name != AGED_BRIE)
            {
                if (items[i].name != TAFKAL80ETC)
                {
                    if (items[i].quality > 0)
                    {
                        if (items[i].name != SULFRAS)
                        {
                            items[i].quality = items[i].quality - 1;
                        }
                    }
                }
                else
                {
                    items[i].quality = items[i].quality - items[i].quality;
                }
            }
            else
            {
                if (items[i].quality < 50)
                {
                    items[i].quality = items[i].quality + 1;
                }
            }
        }
    }
}
