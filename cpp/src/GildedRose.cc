#include "GildedRose.h"
#include "NamedItem.h"
#include "NormalItem.h"
#include "SulfurasItem.h"
#include "ConjuredItem.h"
#include "AgedBrieItem.h"
#include "BackstagePassesItem.h"

#include <map>
#include <functional>
#include <memory>


namespace {
template<class T>
std::unique_ptr<NamedItem> create_item(const Item& item)
{
    return std::unique_ptr<NamedItem>(new T(item));
};

std::unique_ptr<NamedItem> item_producer(const Item& item)
{
    typedef std::map<std::string, std::function<std::unique_ptr<NamedItem>()> > Dispatcher;
    Dispatcher dispatcher;

    dispatcher[SulfurasItem::ITEM_NAME] = [item](){ return create_item<SulfurasItem>(item); };
    dispatcher[ConjuredItem::ITEM_NAME] = [item](){ return create_item<ConjuredItem>(item); };
    dispatcher[AgedBrieItem::ITEM_NAME] = [item](){ return create_item<AgedBrieItem>(item); };
    dispatcher[BackstagePassesItem::ITEM_NAME] = [item](){ return create_item<BackstagePassesItem>(item); };

    Dispatcher::iterator creator = dispatcher.find(item.name);
    if (creator != dispatcher.end())
    {
        return creator->second();
    }

    return create_item<NormalItem>(item);
}

void updateItemQuality(Item& item)
{
    auto named_item = item_producer(item);
    named_item->updateQuality();
    item = Item(*named_item);
}

}


GildedRose::GildedRose(std::vector<Item> & items) : items(items)
{}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        updateItemQuality(items[i]);
    }
}
