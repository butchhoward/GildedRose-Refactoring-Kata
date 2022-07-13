#ifndef NORMAL_ITEM_H
#define NORMAL_ITEM_H
#include "NamedItem.h"

class NormalItem : public NamedItem
{
public:
    NormalItem(const Item& item) :
        NamedItem(item.name, item.sellIn, item.quality)
        {
        }
    virtual ~NormalItem()
    {

    }

protected:
    virtual void updateQuality();
    virtual void updateSellIn();

};

#endif
