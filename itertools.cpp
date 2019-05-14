#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
using namespace std;



int main() {
    auto a = itertools::range(10,14);
    string aa = iterable_to_string(a);
    cout << aa << endl;
    auto b = itertools::range('a','e');
    string bb = iterable_to_string(b);
    cout << bb << endl;
    auto c = itertools::range(5.1, 10.1);
    string cc = iterable_to_string(c);
    cout << cc << endl;
    
    
} 