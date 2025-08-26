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

    message("transform(in.begin(), in.end(), back_inserter(out), [](const int &value){ return value * 3; })");
    // as destination is empty we need to use 'back_inserter'
    // back_inserter is a convenience function template that constructs a std::back_insert_iterator for the
    //               container c with the type deduced from the type of the argument.
    //              Returns a std::back_insert_iterator which can be used to add elements to the end of the container c.
    // lambda function take each element of the 'in' container in as const int 'value' and returns  3 times that value
    transform(in.begin(), in.end(), back_inserter(out), [](const int &value){ return value * 3; });
    cout << "Transform" << endl;
    render(out);

    vector<int> filteredCollection;

    message("copy_if(out.begin(), out.end(), back_inserter(filteredCollection), [](int &value){ return value %2 != 0;}");
    // lambda function take each element of the 'out' container in as const int 'value' and returns only odd values
    copy_if(out.begin(), out.end(), back_inserter(filteredCollection), [](int &value){ return value %2 != 0;});
    cout << "copy_if" << endl;
    render(filteredCollection);

    return 0;
}

/*

transform(in.begin(), in.end(), back_inserter(out), [](const int &value){ return value * 3; })
Transform
3 6 9 12 15 18 21 24 27 30 
copy_if(out.begin(), out.end(), back_inserter(filteredCollection), [](int &value){ return value %2 != 0;}
copy_if
3 9 15 21 27 

*/