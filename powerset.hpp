#pragma once
#include <string>
#include <vector>
#include <sstream>

namespace itertools {
    template<typename Iterable>
    std::vector<string> powerset(const Iterable& iterable) {
        std::vector<string> result;
        
        int reserve_memory = 1;
        for (auto i: iterable)
            reserve_memory *= 2;
        
        result.reserve( reserve_memory );
        
        result.push_back("");
        for (auto i: iterable) {
            std::vector<string> store;
            for (auto r: result) {
                ostringstream add;
                if (r != "")
                    add << r << "," << i;
                else
                    add << i;
                store.push_back(add.str());
            }
            
            result.insert(result.end(), store.begin(), store.end());
        }
        
        
        for (int i=0; i < reserve_memory; ++i)
            result[i] = "{" + result[i] + "}";
        
        return result;
    };
}