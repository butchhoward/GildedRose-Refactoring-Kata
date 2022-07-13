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

    void updateQuality();


    static std::string ITEM_NAME;

};

#endif
