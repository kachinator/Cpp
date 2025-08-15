#include <iostream>

#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include "../../common.h"


// c++ 17 nested namespaces
namespace X::Y::Z
{
    int i;
}

namespace V
{
    int j;
    namespace W
    {
        int k;
    }
}

int main()
{
    X::Y::Z::i = 22;
    std::cout << "Nested namespaces are available: " << X::Y::Z::i << std::endl;
    V::j = 23;
    std::cout << "Namespaces : " << V::j << std::endl;
    V::W::k = 24;
    std::cout << "Nested namespaces are available: " << V::W::k << std::endl;


    return 0;
}

/*
Nested namespaces are available: 42
Namespaces : 43
Nested namespaces are available: 44
*/