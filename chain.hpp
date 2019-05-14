#pragma once
#include <vector>

namespace itertools {
    template <typename T>
     std::vector<T> chain(T iter1, T iter2) {
        std::vector<T> result;
        for (auto i: iter1)
            result.push_back(i);
        for (auto i: iter2)
            result.push_back(i);
        return result;
    };
}
