#pragma once
#include <vector>

namespace itertools {
    template <typename Iter1, typename Iter2>
    std::vector<typename Iter1::value_type> chain(Iter1 iter1, Iter2 iter2) {
        std::vector<typename Iter1::value_type> result;
        for (auto i: iter1)
            result.push_back(i);
        for (auto i: iter2)
            result.push_back(i);
        return result;
    };
}
