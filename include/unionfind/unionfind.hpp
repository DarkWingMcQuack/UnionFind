#pragma once

#include <numeric>
#include <optional>
#include <vector>

namespace unionfind {

template<class Allocator = std::allocator<std::size_t>>
class UnionFind
{
public:
    explicit UnionFind(std::size_t size) noexcept
        : root_(size),
          size_(size, 1),
          number_of_sets_(size)
    {
        std::iota(std::begin(root_),
                  std::end(root_),
                  0);
    }

    [[nodiscard]] auto find(std::size_t x) noexcept
        -> std::optional<std::size_t>
    {
        if(x >= root_.size()) {
            return std::nullopt;
        }

        if(root_[x] != x) {
            return root_[x] = findUnsafe(root_[x]);
        }

        return x;
    }


    [[nodiscard]] auto findUnsafe(std::size_t x) noexcept
        -> std::size_t
    {
        if(root_[x] != x) {
            return root_[x] = findUnsafe(root_[x]);
        }

        return x;
    }

    auto merge(std::size_t x, std::size_t y) noexcept
        -> void
    {
        const auto x_opt = find(x);
        const auto y_opt = find(y);

        if(!x_opt or !y_opt) {
            return;
        }

        x = x_opt.value();
        y = y_opt.value();

        if(x == y) {
            return;
        }

        number_of_sets_--;

        if(size_[x] < size_[y]) {
            std::swap(x, y);
        }

        root_[y] = x;
        size_[x] += size_[y];
    }

    [[nodiscard]] auto numberOfSets() const noexcept
        -> std::size_t
    {
        return number_of_sets_;
    }

    [[nodiscard]] auto sizeOfSetContaining(std::size_t elem) noexcept
        -> std::optional<std::size_t>
    {
        auto root_opt = find(elem);
        if(!root_opt) {
            return std::nullopt;
        }
        return size_[root_opt.value()];
    }

    [[nodiscard]] auto sizeOfSetContainingUnsafe(std::size_t elem) noexcept
        -> std::size_t
    {
        auto root = findUnsafe(elem);
        return size_[root];
    }


private:
    std::vector<std::size_t, Allocator> root_;
    std::vector<std::size_t, Allocator> size_;
    std::size_t number_of_sets_;
};

} // namespace unionfind
