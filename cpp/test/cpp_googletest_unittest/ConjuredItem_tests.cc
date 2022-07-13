#include <gtest/gtest.h>
#include <ConjuredItem.h>

static const char* CONJURED="Conjured";


TEST(ConjuredItemTest, ConjuredItemWithZeroSellinAndQuality)
{
    ConjuredItem item(0, 0);
    item.updateItem();
    EXPECT_EQ(CONJURED, Item(item).name);
    EXPECT_EQ(-1, Item(item).sellIn);
    EXPECT_EQ(0, Item(item).quality);
}

TEST(ConjuredItemTest, ConjuredItemWithSellinGtZeroAndQualityZero)
{
    ConjuredItem item( 22, 0);
    item.updateItem();
    EXPECT_EQ(CONJURED, Item(item).name);
    EXPECT_EQ(21, Item(item).sellIn);
    EXPECT_EQ(0, Item(item).quality);
}

TEST(ConjuredItemTest, ConjuredItemWithSellinGtZeroAndQualityGtZero)
{
    ConjuredItem item( 22, 23);
    item.updateItem();
    EXPECT_EQ(CONJURED, Item(item).name);
    EXPECT_EQ(21, Item(item).sellIn);
    EXPECT_EQ(21, Item(item).quality);
}

TEST(ConjuredItemTest, ConjuredItemWithSellinLtZeroAndQualityGtZero)
{
    ConjuredItem item( -1, 23);
    item.updateItem();
    EXPECT_EQ(CONJURED, Item(item).name);
    EXPECT_EQ(-2, Item(item).sellIn);
    EXPECT_EQ(19, Item(item).quality);
}
