#pragma once
#include <string>
#include <vector>
#include <sstream>

namespace itertools {
    template <typename Iter1, typename Iter2>
    std::vector<string> zip(Iter1 iter1, Iter2 iter2) {
        std::vector<string> result;
        for (auto a: iter1) {
            ostringstream add;
            add << a << ",";
            result.push_back(add.str());
        }
        int i = 0;
        for (auto b: iter2) {
            if (i < result.size()) {
                ostringstream add;
                add << result[i] << b;
                result[i] = add.str();
            }
            ++i;                
        }
        return result;
    };
}
