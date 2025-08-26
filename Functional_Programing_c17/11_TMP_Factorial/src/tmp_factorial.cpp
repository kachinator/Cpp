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

// regular programming
int factorial(const int input, const int sum = 1)
{
    if (input > 1)
    {
        return factorial(input - 1, sum * input);
    }
    return sum;
}

// metaprogramming
template <int input, int sum = 1>       // take initial parameters, with defaults
struct Factorial : Factorial<input - 1, input * sum>    // call itself with: input-1 and input*sum, 
                                                        // there is no branching, only recursion
{
};

// specialization that stops the above recursion, whenever input==1, the specialization is call
// specialization always take priority over the more generic implementation, this breaks the recursion
template <int sum>
struct Factorial<1, sum>
{
    enum
    {
        value = sum     // this is how we get the value out of the template
    };
};

int main()
{
    cout << "5! = " << factorial(5) << endl;
    cout << "Factorial<4> " << Factorial<4>::value << endl;
    cout << "Factorial<5> " << Factorial<5>::value << endl;
    return 0;
}

/*
Standard Template Library
    * Part of the C++ standard library made with templates
    * Consist of four components: algorithms, containers, functions, and iterators
    * STl have multiple and efficient implementations of algorithm, check there first

*/


/*

5! = 120
Factorial<4> 24
Factorial<5> 120

*/