# UnionFind
[![Language](https://img.shields.io/badge/C%2B%2B-17/20-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

This repository contains a single-file header-only C++17 [disjoint-set structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure).

## Example:

```cpp
#include <unionfind/unionfind.hpp>
auto main(int argc, char **argv)-> int
{
    // create a disjoint-set structure for 5 sets.
    unionfind::UnionFind uf{5};
    
    // merge sets 0 and 1
    uf.merge(0, 1);
    
    // merge sets 0 and 2
    uf.merge(0, 2);
    
    // find returns an std::optional which is std::nullopt if the passed argument is greater
    // than the number of elements with which the UnionFind structure was created.
    std::optional<std::size_t> zero_opt = uf.find(0);
    
    assert(uf.find(0) ==uf.find(1));
    assert(uf.find(1) ==uf.find(2));
    
    // if it is known that the passed argument is in the valid range UnionFind::findUnsafe can be used instead
    std::size_t zero = uf.findUnsafe(0);

    // UnionFind::numberOfSets returns the number of disjoint sets in the datastructure
    auto sets = uf.numberOfSets();
    
    // uf contains 3 sets: {0, 1, 2}, {3}, {4}
    assert(sets == 3);
}
```
