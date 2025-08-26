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
Lambda does not take any parameters
*/

auto incrementer = []()
{
    auto increment = 0;     // increment = 0 was captured in the closure
    return [increment]() mutable   // capture increment, and the variable will be changed as it is declared 'mutable'
    {
        return increment++;
    };
};

int main()
{

    message("auto incrementer = []() { auto increment = 0; return [increment]() mutable { return increment++;};};");
    message("auto myInc = incrementer()");
    auto myInc = incrementer();
    cout << "myInc = " << myInc() << endl;
    cout << "myInc = " << myInc() << endl;
    cout << "myInc = " << myInc() << endl;
    cout << "myInc = " << myInc() << endl;

    return 0;
}

/*

myInc = 0
myInc = 1
myInc = 2
myInc = 3

*/