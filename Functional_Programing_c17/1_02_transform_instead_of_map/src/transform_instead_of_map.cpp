#include <iostream>

#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include "../../common.h"

using namespace std;

/*
map, filter and reduce do not exist in C++
    * std::transform replaces map
    * std::copy_if  replaces filter
    * std::accumulate replaces reduce
*/
int main()
{
    // lambda function taking auto collection to render its content
    auto render = [](auto collection)
    {
        for (const auto &val : collection)
        {
            cout << val << " ";
        }
        cout <<  endl;
    };

    // in vector holding input data
    vector<int> in{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> out;

    cout << "------ Vector in" << endl;
    render(in);

    message("transform(in.begin(), in.end(), back_inserter(out), [](const int &value){ return value * 4; })");
    // as destination is empty we need to use 'back_inserter'
    // lambda function take each element of the container in  as const int 'value' and returns  3 times that value
    transform(in.begin(), in.end(), back_inserter(out), [](const int &value){ return value * 4; });
    cout << "------ Transform" << endl;
    render(out);
    return 0;
}

/*
------ Vector in
1 2 3 4 5 6 7 8 9 10 
transform(in.begin(), in.end(), back_inserter(out), [](const int &value){ return value * 4; })
------ Transform
4 8 12 16 20 24 28 32 36 40 
*/