#include <gtest/gtest.h>
#include <AgedBrieItem.h>

static const char* AGED_BRIE="Aged Brie";


TEST(AgedBrieTest, BrieItemWithSellinLtZeroAndQualityGtZero)
{
    AgedBrieItem item(-1, 23);
    item.updateItem();
    EXPECT_EQ(AGED_BRIE, Item(item).name);
    EXPECT_EQ(-2, Item(item).sellIn);
    EXPECT_EQ(25, Item(item).quality);
}

TEST(AgedBrieTest, BrieItemWithSellinGtZeroAndQualityGt50)
{
    AgedBrieItem item( 10, 51);
    item.updateItem();
    EXPECT_EQ(AGED_BRIE, Item(item).name);
    EXPECT_EQ(9, Item(item).sellIn);
    EXPECT_EQ(51, Item(item).quality);
}

TEST(AgedBrieTest, BrieItemWithSellinLtZeroAndQualityGt50)
{
    AgedBrieItem item( -5, 55);
    item.updateItem();
    EXPECT_EQ(AGED_BRIE, Item(item).name);
    EXPECT_EQ(-6, Item(item).sellIn);
    EXPECT_EQ(55, Item(item).quality);
}
