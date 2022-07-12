# Snippets

## Rebuild after changing CMakelist

Run from `cpp` folder (base of cpp part of the repo):
```shell
rm -rf build && mkdir build && cd build && cmake ..
```


## Build and Test, generating coverage remote

```shell
make && find . -name "*.gcda" -print0 | xargs -0 rm; ./test/cpp_googletest_unittest/GildedRoseGoogletestUnitTests; find . -name 'GildedRose.cc.gcda' | xargs gcov &>/dev/null
```

Edit the coverage report file [`build/GildedRose.cc.gcov`](./build/GildedRose.cc.gcov) to see the results.

Lines marked with `#####` have no code coverage during the test runs.
