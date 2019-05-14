#pragma once
#include <vector>

namespace itertools {
    template <typename T>
    std::vector<T> range(T Start, T End) {
        std::vector<T> result;
        for (; Start<End; ++Start) {
            result.push_back(Start);
        }
        return result;
    };
}