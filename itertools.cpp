#include <iostream>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
using namespace std;

namespace itertools {
    string range(auto Start, auto End) {
        
        for (; Start<End; ++Start)
            cout << Start;
        cout << endl;
        return "hehe";
    };
    
    template<typename Iterable>
    string iterable_to_string(const Iterable& iterable) {
	ostringstream ostr;
	for (auto i: iterable)
		ostr << i << ",";
	return ostr.str();
}
}


int main() {
    auto a = itertools::range(10,14);
    string aa = itertools::iterable_to_string(a);
    cout << aa << endl;
    auto b = itertools::range('a','e');
    string bb = itertools::iterable_to_string(b);
    cout << bb << endl;
} 