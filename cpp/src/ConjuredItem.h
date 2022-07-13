#ifndef CONJURED_ITEM_H
#define CONJURED_ITEM_H
#include "NamedItem.h"

class ConjuredItem : public NamedItem
{
public:
    ConjuredItem(const Item& item) :
        NamedItem("Conjured", item.sellIn, item.quality)
        {
        }

    ConjuredItem(int sellIn, int quality) :
        NamedItem("Conjured", sellIn, quality)
        {
        }

    virtual ~ConjuredItem()
    {

    }


    static std::string ITEM_NAME;

protected:
    virtual void updateQuality();
    virtual void updateSellIn();

};

#endif
