#pragma once
#include <string>
#include <vector>
#include <sstream>

namespace itertools {
    template <typename Iter1, typename Iter2>
    std::vector<string> product(Iter1 iter1, Iter2 iter2) {
        std::vector<string> result;
        for (auto a: iter1) {
            for (auto b: iter2) {
                ostringstream add;
                add << a << "," << b;
                result.push_back(add.str());
            }
        }
        return result;
    };
}
