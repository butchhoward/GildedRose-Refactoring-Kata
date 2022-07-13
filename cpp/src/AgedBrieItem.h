#ifndef AGEDBRIE_ITEM_H
#define AGEDBRIE_ITEM_H
#include "NamedItem.h"


class AgedBrieItem : public NamedItem
{
public:
    AgedBrieItem(const Item& item) :
        NamedItem(ITEM_NAME, item.sellIn, item.quality)
        {
        }

    AgedBrieItem(int sellIn, int quality) :
        NamedItem(ITEM_NAME, sellIn, quality)
        {
        }
    virtual ~AgedBrieItem()
    {

    }

    virtual void updateQuality();

    static std::string ITEM_NAME;

};



#endif
