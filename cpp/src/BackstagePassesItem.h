#ifndef BACKSTAGEPASSES_ITEM_H
#define BACKSTAGEPASSES_ITEM_H
#include "NamedItem.h"



class BackstagePassesItem : public NamedItem
{
public:
    BackstagePassesItem(const Item& item) :
        NamedItem(ITEM_NAME, item.sellIn, item.quality)
        {
        }

    BackstagePassesItem(int sellIn, int quality) :
        NamedItem(ITEM_NAME, sellIn, quality)
        {
        }
    virtual ~BackstagePassesItem()
    {

    }

    static std::string ITEM_NAME;

protected:
    virtual void updateQuality();
    virtual void updateSellIn();

};



#endif
