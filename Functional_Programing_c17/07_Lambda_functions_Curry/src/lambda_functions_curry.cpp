#include <iostream>

#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <functional>       // <<--- function
#include <cmath>
#include <vector>
#include "../../common.h"

using namespace std;

/*
Lambdas are a powerful feature of C++ that allow you to define a function in place.
they are unnamed functions objects that can be used wherever a function is required.
    * An unnamed function object
    * Create closure over calling scope
    * Use the keywrd mutable to change the value of a variable in the calling scope
    * Can be used as a function pointer
    * Can be used as a function object

capture clause:
    * []: captures nothing
    * [&]: captures all variables by reference
    * [=]: captures all variables by value
    * [a, &b]: captures a by value and b by reference
    * [this]: captures the this pointer of the enclosing class
    * [a, b]: captures a and b by value
    * [&a, &b]: captures a and b by reference
    * [=, &a, &b]: captures all variables by value, but captures a and b by reference
    * [&, a, b]: captures all variables by reference, but captures a and b by value
    * [this, a, b]: captures the this pointer and a and b by value
    * 
    * []{ }          // do not capture anything
    * [foo]{ }       // capture `foo` by value
    * [&foo]{ }      // capture `foo` by reference
    * [foo, &bar]{ } // capture `foo` by value, `bar` by reference
    * [=, &foo]{ }   // capture everything by value, `foo` by reference
    * [&, foo]{ }    // capture everything by reference, `foo` by value


variable is captured by value (i.e. copied) only once, when you define the lambda. 
It's not "updated" if the original variable changes.
*/

/*
Currying is a technique of evaluating a function with multiple arguments, into a sequence 
of functions with a single argument.
*/
auto addCurry = [](auto a)
{
    // a is captured by value, b is captured by reference
    return [a](auto b) {
        // a and b are captured by value, c is captured by reference
        return [a, b](auto c) { return a + b + c;};    // capture list [a, b]
    };
};

int main()
{
    auto added1 = addCurry(1);          // a = 1
    auto added2 = added1(10);           // b = 10
    auto addResults = added2(100);      // c = 100
    cout << "results: " << addResults << endl;
    auto allAtOnce = addCurry(990000)(9900)(99);    // a = 990000, b = 9900, c = 99
    cout << "All results: " << allAtOnce << endl;
    return 0;
}

/*
results: 111
All results: 999999

*/