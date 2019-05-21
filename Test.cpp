/**
 * A test program for itertools.
 * 
 * @author Many students.
 * @since  2019-05
 */


#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"

using namespace itertools;

template<typename Iterable>
string iterable_to_string(const Iterable& iterable) {
	ostringstream ostr;
	for (decltype(*iterable.begin()) i : iterable){
		ostr << i << ",";
	}
	return ostr.str();
}

int main() {
    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {
            
            
        // Tests by Kira Kondratyeva 
        
        //range
        testcase.setname("test range"); 
        int a = 37;
        for (int i: range(37,42))
            testcase.CHECK_EQUAL(i, a++);
        
        a = -7;
        for (int i: range(-7, 7))
            testcase.CHECK_EQUAL(i, a++);
        
        double d = 4.2;
        for (double i: range(4.2, 10.2))
            testcase.CHECK_EQUAL(i, d++);
        
        char c = 'a';
        for (char i: range('a','z'))
            testcase.CHECK_EQUAL(i, c++);
        
        c = 'z';
        for (char i: range('z','~'))   //who hides after z? {,|,},~
            testcase.CHECK_EQUAL(i, c++);
            
        
        //chain
        testcase.setname("test chain");   
            
        int ans = 0;
        int answer[] = {4, 5, 6, 6, 7, 8, 9, 10};
        for (int i: chain(range(4,7), range(6,11)))
            testcase.CHECK_EQUAL(i, answer[ans++]);
        
        ans = 0;
        double answer1[] = {-5.3, -4.3, -3.3, -2.3};
        char answer2[] = {'g', 'o', 'o', 'o', '!'};
        for (auto i: chain(range(-5.3, -1.3), string("gooo!"))) {
            if (ans < 4)
                testcase.CHECK_EQUAL(i, answer1[ans++]);
            else
                testcase.CHECK_EQUAL(i, answer2[-4 + ans++]);
        }
        
        ans = 0;
        double a1[] = {-97.5, -96.5, -95.5};
        char a2[] = {'e', 'f', 'g'};
        int a3[] = {1000, 1001, 1002};
        char a4[] = {'d', 'o', 'n', 'e', '!'};
        for (auto i: chain(chain(range(-97.5, -94.5), range('e', 'h') ), chain(range(1000, 1003), string("done!") ))) {
            if (ans < 3)
                testcase.CHECK_EQUAL(i, a1[ans++]);
            else if (ans < 6)
                testcase.CHECK_EQUAL(i, a2[-3+ans++]);
            else if (ans < 9)
                testcase.CHECK_EQUAL(i, a3[-6+ans++]);
            else
                testcase.CHECK_EQUAL(i, a4[-9+ans++]);
        }
        
        //zip
        




//not mine, borrowed from the class members
	//////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////// TEST ZIP 	/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
		testcase.setname("OS - TEST ZIP ");
int number=0;

string tab9[]={"1,h","2,e","3,l","4,l","5,o"};
for (auto pair: zip(range(1,6), string("hello")))
{
		testcase.CHECK_OUTPUT(pair,tab9[number]);
		number++;

}

number=0;
		string tab10[]={"6,q","7,w","8,e","9,r","10,t"};
for (auto pair: zip(range(6,11), string("qwert")))
{
		testcase.CHECK_OUTPUT(pair,tab10[number]);
		number++;

}

number=0;
		string tab11[]={"6,0","7,1","8,2","9,3","10,4"};
for (auto pair: zip(range(6,11), range(0,5)))
{
		testcase.CHECK_OUTPUT(pair,tab11[number]);
		number++;

}

number=0;
		string tab16[]={"6,a","7,b","8,c","9,d","10,e"};
for (auto pair: zip(range(6,11), range('a','f')))
{
		testcase.CHECK_OUTPUT(pair,tab16[number]);
		number++;

}

number=0;
		string tab12[]={"0,a","1,b","2,c","3,d","4,e","5,f"};
for (auto pair: zip(range(0,6), range('a','g')))
{
		testcase.CHECK_OUTPUT(pair,tab12[number]);
		number++;

}




	//////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////// TEST PRODUCT 	/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	testcase.setname("OS - TEST PRODUCT");
	number=0;
		string tab13[]={"0,a","0,b","1,a","1,b","2,a","2,b","3,a","3,b","4,a","4,b"};
for (auto pair: product(range(0,5), string("ab")))
{
		testcase.CHECK_OUTPUT(pair,tab13[number]);
		number++;

}

	number=0;
		string tab14[]={"0,5","0,6","1,5","1,6","2,5","2,6","3,5","3,6","4,5","4,6"};
for (auto pair: product(range(0,5), range(5,7)))
{
		testcase.CHECK_OUTPUT(pair,tab14[number]);
		number++;

}


	number=0;
		string tab17[]={"0,a","0,b","1,a","1,b","2,a","2,b","3,a","3,b","4,a","4,b"};
for (auto pair: product(range(0,5), range('a','c')))
{
		testcase.CHECK_OUTPUT(pair,tab17[number]);
		number++;

}

	//////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////// TEST PowerSet 	/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	testcase.setname("OS - TEST PowerSet");
	number=0;
		string tab18[]={"{}","{1}","{2}","{1,2}","{3}","{1,3}","{2,3}","{1,2,3}"};
for (auto pair: powerset(range(1,4))){
		testcase.CHECK_OUTPUT(pair,tab18[number]);
		number++;

}

	number=0;
		string tab20[]={"{}","{a}","{b}","{a,b}","{x}","{a,x}","{b,x}","{a,b,x}","{y}","{a,y}","{b,y}","{a,b,y}","{x,y}","{a,x,y}","{b,x,y}","{a,b,x,y}"};
for (auto subset: powerset(chain(range('a','c'),range('x','z'))))
{		testcase.CHECK_OUTPUT(subset,tab20[number]);
		number++;

}



 		testcase
			.setname("powerset of string")
			.CHECK_EQUAL(iterable_to_string(powerset(string("abc"))), string("{},{a},{b},{a,b},{c},{a,c},{b,c},{a,b,c},"))
			.setname("zip of vector and list")
			.CHECK_EQUAL(iterable_to_string(zip(vector<int>{1,2,3},list<int>{4,5,6})), string("1,4,2,5,3,6,"))
			.setname("chain of string and set")
			.CHECK_EQUAL(iterable_to_string(chain(set<char>{'a','b','c'},string{"def"})), string("a,b,c,d,e,f,"))
		;
		testcase.print();
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
