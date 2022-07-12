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

TEST(GildedRoseTest, SulfrasItemWithSellLtZeroinAndQualityGt0)
{
    vector<Item> items;
    items.push_back(Item("Sulfuras, Hand of Ragnaros", -5, 40));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Sulfuras, Hand of Ragnaros", app.items[0].name);
    EXPECT_EQ(-5, app.items[0].sellIn);
    EXPECT_EQ(40, app.items[0].quality);
}

TEST(GildedRoseTest, BrieItemWithSellinLtZeroAndQualityGtZero)
{
    vector<Item> items;
    items.push_back(Item("Aged Brie", -1, 23));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Aged Brie", app.items[0].name);
    EXPECT_EQ(-2, app.items[0].sellIn);
    EXPECT_EQ(25, app.items[0].quality);
}

TEST(GildedRoseTest, BrieItemWithSellinGtZeroAndQualityGt50)
{
    vector<Item> items;
    items.push_back(Item("Aged Brie", 10, 51));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Aged Brie", app.items[0].name);
    EXPECT_EQ(9, app.items[0].sellIn);
    EXPECT_EQ(51, app.items[0].quality);
}

TEST(GildedRoseTest, BrieItemWithSellinLtZeroAndQualityGt50)
{
    vector<Item> items;
    items.push_back(Item("Aged Brie", -5, 55));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Aged Brie", app.items[0].name);
    EXPECT_EQ(-6, app.items[0].sellIn);
    EXPECT_EQ(55, app.items[0].quality);
}

TEST(GildedRoseTest, PassesItemWithSellinLtZeroAndQualityGtZero)
{
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", -1, 23));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", app.items[0].name);
    EXPECT_EQ(-2, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseTest, PassesItemWithSellinGt11AndQualityLt50)
{
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 12, 40));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", app.items[0].name);
    EXPECT_EQ(11, app.items[0].sellIn);
    EXPECT_EQ(41, app.items[0].quality);
}

TEST(GildedRoseTest, PassesItemWithSellinLt11AndQuality49)
{
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 10, 49));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", app.items[0].name);
    EXPECT_EQ(9, app.items[0].sellIn);
    EXPECT_EQ(50, app.items[0].quality);
}

TEST(GildedRoseTest, PassesItemWithSellinLt6AndQuality49)
{
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 5, 49));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", app.items[0].name);
    EXPECT_EQ(4, app.items[0].sellIn);
    EXPECT_EQ(50, app.items[0].quality);
}
