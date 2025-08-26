#include <iostream>

#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <functional>       // <<--- placeholders
#include <cmath>
#include <vector>
#include "../../common.h"

using namespace std;

/*
In functional Programming, partial application is a technique that allows you to fix
a number of arguments to a function, producing another function of smaller arity.
arity == numbers of arguments a function accepts

bind can reorder the function arguments, and bind values to arguments
*/

// binary function
auto greater_than(int first, int second)
{
    return first >= second;
}

// How many of our custumers are over 28 ?

int main()
{
    vector<int> ages{9, 20, 13, 4, 6, 10, 28, 29, 15, 60, 23, 27, 22, 19, 99};
    int over21 = 0;
    // no  functional solution
    for (int age : ages)
    {
        if (age >= 28)
        {
            over21++;
        }
    }
    cout << "Number over 28 = " << over21 << endl;

    // using count_if, pass iterators begin-end and predicate unirary function
    // however count_if takes a unary function, so we need to use bind to convert our binary function to unary
    // placeholders::_1  == first argument of greater_than
    auto num_over28 = count_if(ages.begin(), ages.end(), bind(&greater_than, placeholders::_1, 28));

    cout << "New Number of 28 = " << num_over28 << endl;

    return 0;
}

/*
Number over 28 = 7
New Number of 28 = 7
*/