#include "GildedRose.h"
#include "NormalItem.h"
#include "SulfurasItem.h"
#include "ConjuredItem.h"
#include "AgedBrieItem.h"
#include "BackstagePassesItem.h"

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

    if (item.name == AgedBrieItem::ITEM_NAME)
    {
        return new AgedBrieItem(item);
    }

    if (item.name == BackstagePassesItem::ITEM_NAME)
    {
        return new BackstagePassesItem(item);
    }

    return new NormalItem(item);
}

void GildedRose::updateItemQuality(Item& item)
{
    NamedItem* named_item = item_producer(item);
    named_item->updateQuality();
    item = Item(*named_item);
    delete named_item;
}
