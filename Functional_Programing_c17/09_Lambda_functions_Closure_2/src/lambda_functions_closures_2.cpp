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

auto continouosAdd = [](int initial, int addBy)     //
{
    auto total = initial;
    return [total, addBy]() mutable         // capture 'total' and 'addBy' in the scope, take no variables, mutable because we will change the value of 'total'
    {
        total += addBy;
        return total;
    };
};

int main()
{

    message("auto continouosAdd = [](int initial, int addBy) { auto total = initial; return [total, addBy]() mutable { total += addBy; return total;};};");
    message("auto x = continouosAdd(1000, 10)");
    auto x = continouosAdd(1000, 10);
    cout << x() << endl;
    cout << x() << endl;
    cout << x() << endl;
    cout << x() << endl;
    cout << x() << endl;

    return 0;
}

/*

1010
1020
1030
1040
1050

*/