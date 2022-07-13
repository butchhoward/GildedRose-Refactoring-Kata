#include <gtest/gtest.h>
#include <BackstagePassesItem.h>

static const char* TAFKAL80ETC="Backstage passes to a TAFKAL80ETC concert";


TEST(BackstagePassesTest, PassesItemWithSellinLtZeroAndQualityGtZero)
{
    BackstagePassesItem item(-1, 23);
    item.updateItem();
    EXPECT_EQ(TAFKAL80ETC, Item(item).name);
    EXPECT_EQ(-2, Item(item).sellIn);
    EXPECT_EQ(0, Item(item).quality);
}

TEST(BackstagePassesTest, PassesItemWithSellinGtZeroAndQualityGt50)
{
    BackstagePassesItem item(10, 55);
    item.updateItem();
    EXPECT_EQ(TAFKAL80ETC, Item(item).name);
    EXPECT_EQ(9, Item(item).sellIn);
    EXPECT_EQ(55, Item(item).quality);
}

TEST(BackstagePassesTest, PassesItemWithSellinGt11AndQualityLt50)
{
    BackstagePassesItem item(12, 40);
    item.updateItem();
    EXPECT_EQ(TAFKAL80ETC, Item(item).name);
    EXPECT_EQ(11, Item(item).sellIn);
    EXPECT_EQ(41, Item(item).quality);
}

TEST(BackstagePassesTest, PassesItemWithSellinLt11AndQuality49)
{
    BackstagePassesItem item(10, 49);
    item.updateItem();
    EXPECT_EQ(TAFKAL80ETC, Item(item).name);
    EXPECT_EQ(9, Item(item).sellIn);
    EXPECT_EQ(50, Item(item).quality);
}

TEST(BackstagePassesTest, PassesItemWithSellinLt6AndQuality49)
{
    BackstagePassesItem item(5, 49);
    item.updateItem();
    EXPECT_EQ(TAFKAL80ETC, Item(item).name);
    EXPECT_EQ(4, Item(item).sellIn);
    EXPECT_EQ(50, Item(item).quality);
}
