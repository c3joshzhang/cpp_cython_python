#pragma once
#ifndef PYADAPTER_H
#define PYADAPTER_H
#include "ServiceCost.h"

namespace cpp_space {
    class PyAdapter {
        public:
            // c++ object that performs the algorithm heavy tasks
            ServiceCost cost;
            PyAdapter();
            ~PyAdapter();
            // wrapper functions that wraps the function for algorithms 
            void serviceabilityCost(
                double* dmnd_mat, 
                double* prod_mat, 
                double* cost_mat, 
                int n_steps, 
                int n_prods);
    };
}

#endif
