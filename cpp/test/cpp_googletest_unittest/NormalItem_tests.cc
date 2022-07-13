#include <gtest/gtest.h>
#include <NormalItem.h>

static const char* NORMAL="Normal";

TEST(NormalItemTest, NormalItemWithZeroSellinAndQuality)
{

    NormalItem item(Item(NORMAL, 0, 0));
    item.updateItem();
    EXPECT_EQ(NORMAL, Item(item).name);
    EXPECT_EQ(-1, Item(item).sellIn);
    EXPECT_EQ(0, Item(item).quality);
}

TEST(NormalItemTest, NormalItemWithSellinGtZeroAndQualityZero)
{

    NormalItem item(Item(NORMAL, 22, 0));
    item.updateItem();
    EXPECT_EQ(NORMAL, Item(item).name);
    EXPECT_EQ(21,  Item(item).sellIn);
    EXPECT_EQ(0,  Item(item).quality);
}

TEST(NormalItemTest, NormalItemWithSellinGtZeroAndQualityGtZero)
{

    NormalItem item(Item(NORMAL, 22, 23));
    item.updateItem();
    EXPECT_EQ(NORMAL,  Item(item).name);
    EXPECT_EQ(21,  Item(item).sellIn);
    EXPECT_EQ(22,  Item(item).quality);
}

TEST(NormalItemTest, NormalItemWithSellinLtZeroAndQualityGtZero)
{

    NormalItem item(Item(NORMAL, -1, 23));
    item.updateItem();
    EXPECT_EQ(NORMAL,  Item(item).name);
    EXPECT_EQ(-2,  Item(item).sellIn);
    EXPECT_EQ(21,  Item(item).quality);
}
