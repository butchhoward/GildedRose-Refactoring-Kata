#ifndef GILDED_ROSE_H
#define GILDED_ROSE_H

#include "Item.h"

#include <vector>

class GildedRose
{
public:
    std::vector<Item> & items;
    GildedRose(std::vector<Item> & items);

    void updateQuality();
};

#endif
