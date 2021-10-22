#pragma once

#include <numeric>
#include <optional>
#include <vector>

namespace unionfind {

class UnionFind
{
public:
    explicit UnionFind(std::size_t size) noexcept
        : root_(size),
          rank_(size, 1),
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

        if(rank_[x] < rank_[y]) {
            root_[x] = y;
        } else if(rank_[x] > rank_[y]) {
            root_[y] = x;
        } else {
            root_[x] = y;
            rank_[y]++;
        }
    }

    [[nodiscard]] auto numberOfSets() const noexcept
        -> std::size_t
    {
        return number_of_sets_;
    }


private:
    std::vector<std::size_t> root_;
    std::vector<std::size_t> rank_;
    std::size_t number_of_sets_;
};

} // namespace unionfind
