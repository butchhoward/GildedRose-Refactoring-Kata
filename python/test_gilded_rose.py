# -*- coding: utf-8 -*-
import unittest
import pytest

from gilded_rose import Item, GildedRose

class ItemMatcher: #pylint: disable=too-few-public-methods
    expected: Item

    def __init__(self, expected):
        self.expected = expected

    def __repr__(self):
        return str(self.expected)

    def __eq__(self, other):
        return self.expected.name == other.name and \
                self.expected.sell_in == other.sell_in and \
                self.expected.quality == other.quality

class GildedRoseTest(unittest.TestCase):
    def setUp(self):
        self.addTypeEqualityFunc(Item, "gilded_rose_item_equal")

    def gilded_rose_item_equal(self, itema, itemb, msg=None):
        self.assertIsInstance(itema, Item, 'First argument is not an Item')
        self.assertIsInstance(itemb, Item, 'Second argument is not an Item')

        if itema.name != itemb.name or itema.sell_in != itemb.sell_in or itema.quality != itemb.quality:
            standard_msg = f"{str(itema)} != {str(itemb)}"
            self.fail(self._formatMessage(msg, standard_msg))


    def test_quality_lower_limit_is_zero_for_normal_products(self):
        items = [Item("foo", 0, 0)]
        gilded_rose = GildedRose(items)

        gilded_rose.update_quality()
        self.assertEqual(Item("foo", -1, 0), gilded_rose.items[0])

    def test_quality_lowers_twice_after_sellby_date(self):
        items = [Item("foo", 0, 2)]
        gilded_rose = GildedRose(items)

        gilded_rose.update_quality()
        self.assertEqual(Item("foo", -1, 0), gilded_rose.items[0])

    def test_quality_of_aged_brie_increases_with_age(self):
        items = [Item("Aged Brie", 5, 2)]
        gilded_rose = GildedRose(items)

        gilded_rose.update_quality()
        self.assertEqual(Item("Aged Brie", 4, 3), gilded_rose.items[0])

    def test_quality_is_limited_to_50_max(self):
        items = [Item("Aged Brie", 5, 50)]
        gilded_rose = GildedRose(items)

        gilded_rose.update_quality()
        self.assertEqual(Item("Aged Brie", 4, 50), gilded_rose.items[0])

    def test_sulfuras_never_changes(self):
        items = [Item("Sulfuras, Hand of Ragnaros", 5, 5)]
        gilded_rose = GildedRose(items)

        gilded_rose.update_quality()
        self.assertEqual(Item("Sulfuras, Hand of Ragnaros", 5, 80), gilded_rose.items[0])

    def test_sulfuras_quality_is_always_80(self):
        items = [Item("Sulfuras, Hand of Ragnaros", 6, 5)]
        gilded_rose = GildedRose(items)

        gilded_rose.update_quality()
        self.assertEqual(Item("Sulfuras, Hand of Ragnaros", 6, 80), gilded_rose.items[0])


    def test_conjured_items_quality_decreases_at_twice_normal_rate(self):
        item_name = "Conjured"
        items = [Item(item_name, 5, 5)]
        gilded_rose = GildedRose(items)

        gilded_rose.update_quality()

        self.assertEqual(ItemMatcher(Item(item_name, 4, 3)), gilded_rose.items[0])


@pytest.mark.parametrize("msg, sell_in, expected_quality", [
    ("normal case", 100, 6),
    ("10 or closer", 10, 7),
    ("5 or closer", 5, 8),
    ("past date", 0, 0)
])
def test_backstage_passes_are_special(msg, sell_in, expected_quality):
    item_name = "Backstage passes to a TAFKAL80ETC concert"
    items = [Item(item_name, sell_in, 5)]
    gilded_rose = GildedRose(items)

    gilded_rose.update_quality()

    assert ItemMatcher(Item(item_name, sell_in-1, expected_quality)) == gilded_rose.items[0], msg



class ItemListMatcher: #pylint: disable=too-few-public-methods
    expected: list

    def __init__(self, expected):
        self.expected = expected

    def __repr__(self):
        return str(self.expected)

    def __eq__(self, other):
        if len(self.expected) != len(other):
            return False

        for index in range(len(self.expected)):
            if self.expected[index].name != other[index].name or \
                    self.expected[index].sell_in != other[index].sell_in or \
                    self.expected[index].quality != other[index].quality:
                return False
        return True



def test_original_data_results():
    items = [
        Item("+5 Dexterity Vest", 10, 20),
        Item("Aged Brie", 2, 0),
        Item("Elixir of the Mongoose", 5, 7),
        Item("Sulfuras, Hand of Ragnaros", 0, 80),
        Item("Sulfuras, Hand of Ragnaros", -1, 80),
        Item("Backstage passes to a TAFKAL80ETC concert", 15, 20),
        Item("Backstage passes to a TAFKAL80ETC concert", 10, 49),
        Item("Backstage passes to a TAFKAL80ETC concert", 5, 49),
        Item("Conjured Mana Cake", 3, 6),
      ]

    gilded_rose = GildedRose(items)

    gilded_rose.update_quality()

    expected_items = [
        Item("+5 Dexterity Vest", 9, 19),
        Item("Aged Brie", 1, 1),
        Item("Elixir of the Mongoose", 4, 6),
        Item("Sulfuras, Hand of Ragnaros", 0, 80),
        Item("Sulfuras, Hand of Ragnaros", -1, 80),
        Item("Backstage passes to a TAFKAL80ETC concert", 14, 21),
        Item("Backstage passes to a TAFKAL80ETC concert", 9, 50),
        Item("Backstage passes to a TAFKAL80ETC concert", 4, 50),
        Item("Conjured Mana Cake", 2, 5)
    ]

    assert ItemListMatcher(expected_items) == items


