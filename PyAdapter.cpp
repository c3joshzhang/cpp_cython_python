#include <vector>
#include <iostream>
#include <chrono>
#include "PyAdapter.h"
#include "Example.h"

namespace cpp_space {

    // Default constructor
    PyAdapter::PyAdapter () {}

    // Overloaded constructor
    PyAdapter::PyAdapter (int val) {
        v = val;
    }

    // Destructor
    PyAdapter::~PyAdapter () {}

    // Return the area of the rectangle
    int PyAdapter::get () {
        return this->v;
    }

    void PyAdapter::apply(std::vector< std::vector<double> > &mat){
      eg.func(mat);
    }
}