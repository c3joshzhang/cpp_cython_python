#include <vector>
#include <iostream>
#include <chrono>
#include "PyAdapter.h"
#include "ServiceCost.h"

namespace cpp_space {

    // Default constructor
    PyAdapter::PyAdapter () {}

    // Destructor
    PyAdapter::~PyAdapter () {}

    void PyAdapter::serviceabilityCost(
        double* dmnd_mat, 
        double* prod_mat, 
        double* cost_mat,
        int n_steps, 
        int n_prods){

      cost.allCost(dmnd_mat, prod_mat, cost_mat, n_steps, n_prods);
    }
}