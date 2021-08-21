# -*- coding: utf-8 -*-

class GildedRose(object):

    def __init__(self, items):
        self.items = items
        self.__adjusters = {
            "Conjured": self.__adjuster_conjured
        }

    def update_quality(self):
        for item in self.items:
            self.__adjust_quality(item)

    def __adjust_quality(self, item):
        adjuster = self.__adjusters.get( item.name, GildedRose.__adjuster_default)
        adjuster(item)

    @classmethod
    def __adjuster_default(cls, item):
        if item.name != "Aged Brie" and item.name != "Backstage passes to a TAFKAL80ETC concert":
            if item.quality > 0:
                if item.name != "Sulfuras, Hand of Ragnaros":
                    item.quality = item.quality - 1
        else:
            if item.quality < 50:
                item.quality = item.quality + 1
                if item.name == "Backstage passes to a TAFKAL80ETC concert":
                    if item.sell_in < 11:
                        if item.quality < 50:
                            item.quality = item.quality + 1
                    if item.sell_in < 6:
                        if item.quality < 50:
                            item.quality = item.quality + 1

        if item.name != "Sulfuras, Hand of Ragnaros":
            item.sell_in = item.sell_in - 1

        if item.sell_in < 0:
            if item.name != "Aged Brie":
                if item.name != "Backstage passes to a TAFKAL80ETC concert":
                    if item.quality > 0:
                        if item.name != "Sulfuras, Hand of Ragnaros":
                            item.quality = item.quality - 1
                else:
                    item.quality = item.quality - item.quality
            else:
                if item.quality < 50:
                    item.quality = item.quality + 1

    @classmethod
    def __adjuster_conjured(cls, item):
        item.sell_in -= 1
        cls.__adjust_quality_value(item, 2)

    @classmethod
    def __adjust_quality_value(cls, item, amount):
        if item.sell_in <=0:
            item.quality -= 2*amount
        else:
            item.quality -= amount

        if item.quality < 0:
            item.quality = 0

#pylint: disable=too-few-public-methods
class Item:
    def __init__(self, name, sell_in, quality):
        self.name = name
        self.sell_in = sell_in
        self.quality = quality

    def __repr__(self):
        return "%s, %s, %s" % (self.name, self.sell_in, self.quality)
