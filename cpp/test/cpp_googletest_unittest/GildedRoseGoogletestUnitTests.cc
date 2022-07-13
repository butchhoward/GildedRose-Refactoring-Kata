#include <gtest/gtest.h>
#include "GildedRose.h"

static const char* SULFRAS="Sulfuras, Hand of Ragnaros";
static const char* AGED_BRIE="Aged Brie";
static const char* TAFKAL80ETC="Backstage passes to a TAFKAL80ETC concert";
static const char* NORMAL="Normal";

TEST(GildedRoseTest, SeveralItemsInCollection)
{
    vector<Item> items;
    items.push_back(Item(NORMAL, 0, 0));
    items.push_back(Item(SULFRAS, 22, 23));
    items.push_back(Item(TAFKAL80ETC, 10, 55));

    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(0, app.items[0].quality);
    EXPECT_EQ(-1, app.items[0].sellIn);

    EXPECT_EQ(22, app.items[1].sellIn);
    EXPECT_EQ(23, app.items[1].quality);

    EXPECT_EQ(9, app.items[2].sellIn);
    EXPECT_EQ(55, app.items[2].quality);

}

TEST(GildedRoseTest, NormalItemWithZeroSellinAndQuality)
{
    vector<Item> items;
    items.push_back(Item(NORMAL, 0, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(NORMAL, app.items[0].name);
    EXPECT_EQ(-1, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseTest, NormalItemWithSellinGtZeroAndQualityZero)
{
    vector<Item> items;
    items.push_back(Item(NORMAL, 22, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(NORMAL, app.items[0].name);
    EXPECT_EQ(21, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseTest, NormalItemWithSellinGtZeroAndQualityGtZero)
{
    vector<Item> items;
    items.push_back(Item(NORMAL, 22, 23));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(NORMAL, app.items[0].name);
    EXPECT_EQ(21, app.items[0].sellIn);
    EXPECT_EQ(22, app.items[0].quality);
}

TEST(GildedRoseTest, NormalItemWithSellinLtZeroAndQualityGtZero)
{
    vector<Item> items;
    items.push_back(Item(NORMAL, -1, 23));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(NORMAL, app.items[0].name);
    EXPECT_EQ(-2, app.items[0].sellIn);
    EXPECT_EQ(21, app.items[0].quality);
}

TEST(GildedRoseTest, SulfurasItemWithSellinGtZeroAndQualityZero)
{
    vector<Item> items;
    items.push_back(Item(SULFRAS, 22, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(SULFRAS, app.items[0].name);
    EXPECT_EQ(22, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseTest, SulfurasItemWithSellinGtZeroAndQualityGtZero)
{
    vector<Item> items;
    items.push_back(Item(SULFRAS, 22, 23));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(SULFRAS, app.items[0].name);
    EXPECT_EQ(22, app.items[0].sellIn);
    EXPECT_EQ(23, app.items[0].quality);
}

TEST(GildedRoseTest, SulfrasItemWithSellLtZeroinAndQualityGt0)
{
    vector<Item> items;
    items.push_back(Item(SULFRAS, -5, 40));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(SULFRAS, app.items[0].name);
    EXPECT_EQ(-5, app.items[0].sellIn);
    EXPECT_EQ(40, app.items[0].quality);
}

TEST(GildedRoseTest, BrieItemWithSellinLtZeroAndQualityGtZero)
{
    vector<Item> items;
    items.push_back(Item(AGED_BRIE, -1, 23));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(AGED_BRIE, app.items[0].name);
    EXPECT_EQ(-2, app.items[0].sellIn);
    EXPECT_EQ(25, app.items[0].quality);
}

TEST(GildedRoseTest, BrieItemWithSellinGtZeroAndQualityGt50)
{
    vector<Item> items;
    items.push_back(Item(AGED_BRIE, 10, 51));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(AGED_BRIE, app.items[0].name);
    EXPECT_EQ(9, app.items[0].sellIn);
    EXPECT_EQ(51, app.items[0].quality);
}

TEST(GildedRoseTest, BrieItemWithSellinLtZeroAndQualityGt50)
{
    vector<Item> items;
    items.push_back(Item(AGED_BRIE, -5, 55));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(AGED_BRIE, app.items[0].name);
    EXPECT_EQ(-6, app.items[0].sellIn);
    EXPECT_EQ(55, app.items[0].quality);
}

TEST(GildedRoseTest, PassesItemWithSellinLtZeroAndQualityGtZero)
{
    vector<Item> items;
    items.push_back(Item(TAFKAL80ETC, -1, 23));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(TAFKAL80ETC, app.items[0].name);
    EXPECT_EQ(-2, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseTest, PassesItemWithSellinGtZeroAndQualityGt50)
{
    vector<Item> items;
    items.push_back(Item(TAFKAL80ETC, 10, 55));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(TAFKAL80ETC, app.items[0].name);
    EXPECT_EQ(9, app.items[0].sellIn);
    EXPECT_EQ(55, app.items[0].quality);
}

TEST(GildedRoseTest, PassesItemWithSellinGt11AndQualityLt50)
{
    vector<Item> items;
    items.push_back(Item(TAFKAL80ETC, 12, 40));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(TAFKAL80ETC, app.items[0].name);
    EXPECT_EQ(11, app.items[0].sellIn);
    EXPECT_EQ(41, app.items[0].quality);
}

TEST(GildedRoseTest, PassesItemWithSellinLt11AndQuality49)
{
    vector<Item> items;
    items.push_back(Item(TAFKAL80ETC, 10, 49));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(TAFKAL80ETC, app.items[0].name);
    EXPECT_EQ(9, app.items[0].sellIn);
    EXPECT_EQ(50, app.items[0].quality);
}

TEST(GildedRoseTest, PassesItemWithSellinLt6AndQuality49)
{
    vector<Item> items;
    items.push_back(Item(TAFKAL80ETC, 5, 49));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(TAFKAL80ETC, app.items[0].name);
    EXPECT_EQ(4, app.items[0].sellIn);
    EXPECT_EQ(50, app.items[0].quality);
}



static const char* CONJURED="Conjured";


TEST(GildedRoseTest, ConjuredItemWithZeroSellinAndQuality)
{
    vector<Item> items;
    items.push_back(Item(CONJURED, 0, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(CONJURED, app.items[0].name);
    EXPECT_EQ(-1, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseTest, ConjuredItemWithSellinGtZeroAndQualityZero)
{
    vector<Item> items;
    items.push_back(Item(CONJURED, 22, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(CONJURED, app.items[0].name);
    EXPECT_EQ(21, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseTest, ConjuredItemWithSellinGtZeroAndQualityGtZero)
{
    vector<Item> items;
    items.push_back(Item(CONJURED, 22, 23));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(CONJURED, app.items[0].name);
    EXPECT_EQ(21, app.items[0].sellIn);
    EXPECT_EQ(21, app.items[0].quality);
}

TEST(GildedRoseTest, ConjuredItemWithSellinLtZeroAndQualityGtZero)
{
    vector<Item> items;
    items.push_back(Item(CONJURED, -1, 23));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(CONJURED, app.items[0].name);
    EXPECT_EQ(-2, app.items[0].sellIn);
    EXPECT_EQ(19, app.items[0].quality);
}
