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
Class template std::function is a general-purpose polymorphic function wrapper. Instances of std::function
can store, copy, and invoke any CopyConstructible Callable target -- functions (via pointers thereto),
lambda expressions, bind expressions, or other function objects, as well as pointers to member functions
and pointers to data members.
    * std::function is a wrapper for invokable objects
    * Invokable objects include functions, functors and lambdas
    * Can store functions in objects like vectors
*/

void demoFunction()
{
    cout << ANSI_COLOR_GREEN << "Called demoFunction" << ANSI_COLOR_RESET << endl;
}

void adder(int a, int b)
{
    cout << ANSI_COLOR_YELLOW << "Called adder, a + b = " << a + b << ANSI_COLOR_RESET << endl;
}

class functor
{
public:
    // single member  function returning void, 'operator()' is a member function of function, which is going to be the invokation operator
    void operator()() const
    {
        cout << ANSI_COLOR_RED << "Called functor" << ANSI_COLOR_RESET << endl;
    }
};

int main()
{
    // vector of functions, all returning 'void' and taking no parameters '()'
    vector< function<void()> > funcs;
    funcs.push_back(demoFunction);      // push back 'demoFunction' into the vector

    functor functor_instance;           // instance of the functor class
    funcs.push_back(functor_instance);  // push back 'functor_instance', functor class, into the vector
                                        // push back a lambda function, that takes no parameters, just print
    funcs.push_back([]() { cout << "Called anonymous lambda" << endl; });
    funcs.push_back(bind(&adder, 10, 15)); // push back adder as unitary function, 
                                // by using bind() and fixed arguments == function with no input parameters

    for (auto &f : funcs)
    {
        f();        // 'f' is a function object, and f() call the function with no parameters
    }

    return 0;
}

/*
Called demoFunction
Called functor
Called anonymous lambda
Called adder, a + b = 25

*/