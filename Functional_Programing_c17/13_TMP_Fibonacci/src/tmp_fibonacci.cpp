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
Using Template Meta Programming
    * Need to create template specializations for 0 and 1
    * The base case recursively call itself
*/

template <int n>
struct fibonacci
{
    enum
    {
        value = fibonacci<n - 1>::value + fibonacci<n - 2>::value   // recursive fibonacci equation using TMP syntax
    };
};

// specializations for 0 and 1
template <>         // empty input
struct fibonacci<0> // for 0
{
    enum
    {
        value = 0
    };
};

template <>         // empty input
struct fibonacci<1> // for 1
{
    enum
    {
        value = 1
    };
};

int main()
{
    cout << "fib(0) = " << fibonacci<0>::value << endl;
    cout << "fib(1) = " << fibonacci<1>::value << endl;
    cout << "fib(2) = " << fibonacci<2>::value << endl;
    cout << "fib(3) = " << fibonacci<3>::value << endl;
    cout << "fib(4) = " << fibonacci<4>::value << endl;
    cout << "fib(11) = " << fibonacci<11>::value << endl;
    cout << "fib(12) = " << fibonacci<12>::value << endl;
    cout << "fib(45) = " << fibonacci<45>::value << endl;
    return 0;
}


/*

fib(0) = 0
fib(1) = 1
fib(2) = 1
fib(3) = 2
fib(4) = 3
fib(11) = 89
fib(12) = 144
fib(45) = 1134903170

*/