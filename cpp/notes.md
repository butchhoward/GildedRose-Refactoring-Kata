# Snippets

## Rebuild after changing CMakelist

Run from `cpp` folder (base of cpp part of the repo):
```shell
rm -rf build && mkdir build && cd build && cmake ..
```


## Build and Test, generating coverage remote

```shell
make && { find . -name "*.gcda" -print0 | xargs -0 rm; ./test/cpp_googletest_unittest/GildedRoseGoogletestUnitTests; find . -name 'GildedRose.cc.gcda' | xargs gcov -b &>/dev/null; }
```

Edit the coverage report file [`build/GildedRose.cc.gcov`](./build/GildedRose.cc.gcov) to see the results.

Lines marked with `#####` have no code coverage during the test runs.

Branches marked with 0% have no coverage.

For `if` statements with no `else` block, this means the negative or the if is not exercised in a test.

In this example, the `if` on line 73 needs a test for `>= 50`. **branch 0** is the negative of the if-statment conditional.

```
        -:   71:            else
        -:   72:            {
        1:   73:                if (items[i].quality < 50)
branch  0 taken 0%
branch  1 taken 100%
        -:   74:                {
        1:   75:                    items[i].quality = items[i].quality + 1;
        1:   76:                }
        -:   77:            }
```
