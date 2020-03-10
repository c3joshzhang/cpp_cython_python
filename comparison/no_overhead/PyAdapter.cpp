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
        return v;
    }

    void PyAdapter::apply(double* mat, int dim0, int dim1){                    //Modified
//---------------------------------------------------------------------------------------
      example.func(mat, dim0, dim1);                                           //Modified
//---------------------------------------------------------------------------------------
    }
}