#include <gtest/gtest.h>
#include "GildedRose.h"


TEST(GildedRoseTest, NormalItemWithZeroSellinAndQuality)
{
    vector<Item> items;
    items.push_back(Item("Normal", 0, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Normal", app.items[0].name);
    EXPECT_EQ(-1, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseTest, NormalItemWithSellinGtZeroAndQualityZero)
{
    vector<Item> items;
    items.push_back(Item("Normal", 22, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Normal", app.items[0].name);
    EXPECT_EQ(21, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}
