# UnionFind
[![Language](https://img.shields.io/badge/C%2B%2B-17/20-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

This repository contains a single-file header-only C++17 [disjoint-set structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure).

## Example:

```cpp
#include <unionfind/unionfind.hpp>
auto main(int argc, char **argv)-> int
{
    // create a disjoint-set structure for 5 sets.
    unionfind::UnionFind uf{10};
    
    // merge sets 0 and 1
    uf.merge(0, 1);
    
    // merge sets 0 and 2
    uf.merge(0, 2);
    
    // find returns an std::optional which is std::nullopt if the passed argument is greater
    // than the number of elements with which the UnionFind structure was created.
    std::optional<std::size_t> zero_opt = uf.find(0);
    
    assert(uf.find(0) == uf.find(1));
    assert(uf.find(1) == uf.find(2));
    
    // if it is known that the passed argument is in 
    // a valid range UnionFind::findUnsafe can be used instead
    std::size_t zero = uf.findUnsafe(0);

    // UnionFind::numberOfSets returns the number of disjoint sets in the datastructure
    auto sets = uf.numberOfSets();
    
    // uf contains 3 sets: {0, 1, 2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}
    assert(sets == 3);
    
    // it is also possible to call merge with any number of parameters
    uf.merge(5, 6, 7, 8, 9);
    
    // size_opt contains the number of elements the set in which 5 is an element of
    // if the passed argument is not an element size_opt would be std::nullopt
    std::optional<std::size_t> size_opt = uf.sizeOfSetContaining(5);
    assert(size_opt.value() == 5);
    
    // there also exists an unsave variant
    std::size_t size = uf.sizeOfSetContainingUnsafe(5);
    assert(size == 5);
}
```
