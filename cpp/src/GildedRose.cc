#include "GildedRose.h"
#include "NormalItem.h"
#include "SulfurasItem.h"
#include "ConjuredItem.h"

static const char* SULFRAS="Sulfuras, Hand of Ragnaros";
static const char* AGED_BRIE="Aged Brie";
static const char* TAFKAL80ETC="Backstage passes to a TAFKAL80ETC concert";

static const char* CONJURED="Conjured";




GildedRose::GildedRose(vector<Item> & items) : items(items)
{}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        updateItemQuality(items[i]);
    }
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
        SulfurasItem sulfuras_item(item);
        sulfuras_item.updateQuality();
        item = sulfuras_item;
        return;
    }

    if (item.name == AGED_BRIE)
    {
        return UpdateAgedBrieQuality(item);
    }

    if (item.name == TAFKAL80ETC)
    {
        return UpdateTAFKAL80ETCQuality(item);
    }

    if (item.name == CONJURED)
    {
        ConjuredItem conjured_item(item);
        conjured_item.updateQuality();
        item = conjured_item;
        return;
    }


    NormalItem normal_item(item);
    normal_item.updateQuality();
    item = normal_item;
}
