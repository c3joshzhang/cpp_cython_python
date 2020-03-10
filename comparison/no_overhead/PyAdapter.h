#pragma once
#ifndef PYADAPTER_H
#define PYADAPTER_H
#include "Example.h"

namespace cpp_space {
    class PyAdapter {
        public:
            // c++ object that performs the algorithm heavy tasks
            int v;
            Example example;
            PyAdapter();
            PyAdapter(int val);
            ~PyAdapter();
            int get();
            // wrapper functions that wraps the function for algorithms 
            void apply(double* mat, int dim0, int dim1);                       //Modified
//---------------------------------------------------------------------------------------
    };
}

#endif
