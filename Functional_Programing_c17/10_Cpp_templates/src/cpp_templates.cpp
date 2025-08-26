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
C++ Template Metaprogramming
    * Template metaprogramming (TMP) is a Turing complete functional programing language built-in to C++
    * TMP variables are always immutable
    * TMP doesn't have loops, so we use recursion
    * TMP doesn't have branching, we use specialization
*/

// regular generic programming, template instantiated at run-time
template <typename T>
T cube(const T &value)      // cube function, returns type 'T', instantiated at compile time
{
    return value * value * value;
}

// TMP programming, template instantiated at compile time
template <int toCube>       // toCube is the name of our variable, it is ummutable (can't be changed)
struct Cube                 // function named 'Cube' returning a struct
{
    enum
    {
        value = toCube * toCube * toCube    // there is no return in TMP, no ending ';', 
                                            // then we create a value, 'value' and we assign what we need
    };
};

int main()
{
    cout << "8 cubed = " << cube(8) << endl;            // cube(8) computed at execution time
    cout << "5 cubed = " << Cube<5>::value << endl;     // Cube<5>:: value is not executed at run time, it was completed at compilation time
    return 0;
}

/*

8 cubed = 512
5 cubed = 125

*/