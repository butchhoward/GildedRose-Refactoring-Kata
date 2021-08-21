# -*- coding: utf-8 -*-
import unittest

from gilded_rose import Item, GildedRose


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


if __name__ == '__main__':
    unittest.main()
