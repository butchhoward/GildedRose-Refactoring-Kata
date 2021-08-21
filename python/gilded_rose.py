# -*- coding: utf-8 -*-

#pylint: disable=too-few-public-methods
class GildedRose():
    def __init__(self, items):
        self.items = items
        self.__adjusters = {
            "Conjured": GildedRose.__adjuster_conjured,
            "Aged Brie": GildedRose.__adjuster_aged_brie,
            "Sulfuras, Hand of Ragnaros": GildedRose.__adjuster_sulfuras,
            "Backstage passes to a TAFKAL80ETC concert": GildedRose.__adjuster_backstage,
        }

    def update_quality(self):
        for item in self.items:
            self.__adjust_quality(item)

    def __adjust_quality(self, item):
        adjuster = self.__adjusters.get( item.name, GildedRose.__adjuster_default)
        adjuster(item)

    @classmethod
    def __adjuster_default(cls, item):
        cls.__adjust_sellin_value(item)
        if item.sell_in < 0:
            cls.__adjust_quality_value(item, 2)
        else:
            cls.__adjust_quality_value(item, 1)

    @classmethod
    def __adjuster_conjured(cls, item):
        cls.__adjust_sellin_value(item)
        cls.__adjust_quality_value(item, 2)

    @classmethod
    def __adjuster_aged_brie(cls, item):
        cls.__adjust_sellin_value(item)
        cls.__adjust_quality_value(item, -1)

    @classmethod
    def __adjuster_sulfuras(cls, item):
        pass    # sulfuras never changes

    @classmethod
    def __adjuster_backstage(cls, item):
        cls.__adjust_sellin_value(item)
        if item.sell_in <= 0:
            item.quality = 0
        elif item.sell_in < 5:
            cls.__adjust_quality_value(item, -3)
        elif item.sell_in < 10:
            cls.__adjust_quality_value(item, -2)
        else:
            cls.__adjust_quality_value(item, -1)

    @classmethod
    def __adjust_sellin_value(cls, item):
        item.sell_in -= 1

    @classmethod
    def __adjust_quality_value(cls, item, amount):
        if item.sell_in <=0:
            item.quality -= 2*amount
        else:
            item.quality -= amount

        if item.quality < 0:
            item.quality = 0

        if item.quality > 50:
            item.quality = 50

#pylint: disable=too-few-public-methods
class Item:
    def __init__(self, name, sell_in, quality):
        self.name = name
        self.sell_in = sell_in
        self.quality = quality

    def __repr__(self):
        return "%s, %s, %s" % (self.name, self.sell_in, self.quality)
