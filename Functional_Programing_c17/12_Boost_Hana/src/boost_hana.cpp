#include <iostream>

#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <functional>  
#include <cmath>
#include <vector>
#include "../../common.h"

#include <boost/hana.hpp>       // hana declarations
namespace hana = boost::hana;   // hana namespace
using namespace hana::literals;
using namespace std;

/*
Boost.hana is one of the functional programming libraries
    * Superset of the Bosst.MPL and Boost.Fusion libraries
    * provides library support for tuples, also known as heterogeneous collections
    * It also has a large number of functional methods
*/

// 3 types of vehicles, are not related or dependent  on each other 
struct Truck
{
    std::string name;
    double bed_length;
};
struct Car
{
    std::string name;
};
struct Motorcycle
{
    std::string name;
};

int main()
{
    // create a collection of vehicles, as tuples - a collectionof heterogeneous items
    // each has been initialized with the needed parameters
    auto vehicles = hana::make_tuple(
        Truck{"F-150", 8.5}, Car{"Volt"}, Motorcycle{"Ninja"});

    // create a function that uses a lambda that return a decltype based on wheter or not it finds 
    // this property 'bed_length', body of the lambda is empty
    auto has_bed_length = hana::is_valid(
        [](auto &&x) -> decltype((void)x.bed_length) {});

    // filter through the 'vehicles' collection with function 'has_bed_length'
    auto trucks = hana::filter(vehicles, has_bed_length);

    // now filter the same collection, with a compose function, the negation of 'has_bed_length'
    // hana::compose takes two or more functions, and makes them one function
    // hana::compose goes from right to left, so it's goingto take the 'has_bed_length' function
    // and execute it, and then execute hana::not_, if 'has_bed_length' was true, 'not_' it's 
    // going to make it false, and viceversa
    auto nontrucks = hana::filter(vehicles, hana::compose(hana::not_, has_bed_length));

    // rendering for trucks
    hana::for_each(trucks, [](auto &vehicle)
                   { cout << ANSI_COLOR_GREEN << "Truck = " << vehicle.name << ", bed length = " << vehicle.bed_length << ANSI_COLOR_RESET << endl; });

    // rendering for nontrucks
    hana::for_each(nontrucks, [](auto &vehicle)
                   { cout << ANSI_COLOR_YELLOW << "Vehicle = " << vehicle.name << ANSI_COLOR_RESET << endl; });

    return 0;
}

/*

Truck = F-150, bed length = 8.5
Vehicle = Volt
Vehicle = Ninja

*/