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

NamedItem* item_producer(const Item& item)
{
    if (item.name == SULFRAS)
    {
        return new SulfurasItem(item);
    }

    if (item.name == CONJURED)
    {
        return new ConjuredItem(item);
    }

    return new NormalItem(item);
}

void GildedRose::updateItemQuality(Item& item)
{
    if (item.name == AGED_BRIE)
    {
        return UpdateAgedBrieQuality(item);
    }

    if (item.name == TAFKAL80ETC)
    {
        return UpdateTAFKAL80ETCQuality(item);
    }

    NamedItem* named_item = item_producer(item);
    named_item->updateQuality();
    item = Item(*named_item);
    delete named_item;

}
