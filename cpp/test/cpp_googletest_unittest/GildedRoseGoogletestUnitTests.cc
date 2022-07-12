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

TEST(GildedRoseTest, NormalItemWithSellinGtZeroAndQualityGtZero)
{
    vector<Item> items;
    items.push_back(Item("Normal", 22, 23));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Normal", app.items[0].name);
    EXPECT_EQ(21, app.items[0].sellIn);
    EXPECT_EQ(22, app.items[0].quality);
}

TEST(GildedRoseTest, NormalItemWithSellinLtZeroAndQualityGtZero)
{
    vector<Item> items;
    items.push_back(Item("Normal", -1, 23));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Normal", app.items[0].name);
    EXPECT_EQ(-2, app.items[0].sellIn);
    EXPECT_EQ(21, app.items[0].quality);
}


TEST(GildedRoseTest, SulfurasItemWithSellinGtZeroAndQualityZero)
{
    vector<Item> items;
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 22, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Sulfuras, Hand of Ragnaros", app.items[0].name);
    EXPECT_EQ(22, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseTest, SulfurasItemWithSellinGtZeroAndQualityGtZero)
{
    vector<Item> items;
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 22, 23));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Sulfuras, Hand of Ragnaros", app.items[0].name);
    EXPECT_EQ(22, app.items[0].sellIn);
    EXPECT_EQ(23, app.items[0].quality);
}
