#include <gtest/gtest.h>
#include "SulfurasItem.h"

static const char* SULFRAS="Sulfuras, Hand of Ragnaros";


TEST(SulfurasItemTest, SulfurasItemWithSellinGtZeroAndQualityZero)
{
    SulfurasItem item( 22, 0);
    item.updateItem();
    EXPECT_EQ(SULFRAS, Item(item).name);
    EXPECT_EQ(22, Item(item).sellIn);
    EXPECT_EQ(0, Item(item).quality);
}

TEST(SulfurasItemTest, SulfurasItemWithSellinGtZeroAndQualityGtZero)
{
    SulfurasItem item( 22, 23);
    item.updateItem();
    EXPECT_EQ(SULFRAS, Item(item).name);
    EXPECT_EQ(22, Item(item).sellIn);
    EXPECT_EQ(23, Item(item).quality);
}

TEST(SulfurasItemTest, SulfrasItemWithSellLtZeroinAndQualityGt0)
{
    SulfurasItem item( -5, 40);
    item.updateItem();
    EXPECT_EQ(SULFRAS, Item(item).name);
    EXPECT_EQ(-5, Item(item).sellIn);
    EXPECT_EQ(40, Item(item).quality);
}
