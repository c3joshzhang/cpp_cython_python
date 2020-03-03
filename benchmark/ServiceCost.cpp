
#include <vector>
#include <iostream>
#include <chrono>
#include <math.h>
#include "ServiceCost.h"

ServiceCost::ServiceCost() {};

ServiceCost::~ServiceCost() {};

void ServiceCost::allCost(
        double* dmnd_mat, 
        double* prod_mat, 
        double* cost_mat,
        int n_steps, 
        int n_prods){

    #pragma omp parallel for
    for (int p = 0; p < n_prods; p += 1)
        singleCost(
            dmnd_mat, prod_mat, cost_mat, 
            n_steps, n_prods, p);
};

void ServiceCost::singleCost(
        double* dmnd_mat, 
        double* prod_mat, 
        double* cost_mat,
        int n_steps, 
        int n_prods, 
        int cur_prod){
    // Helper Lambdas to get the matrix value reference
    auto dmnd_val = [&](int t)->double&{
        return dmnd_mat[t * n_prods + cur_prod];};

    auto prod_val = [&](int t)->double&{
        return prod_mat[t * n_prods + cur_prod];};

    auto cost_val = [&](int t)->double&{
        return cost_mat[t * n_prods + cur_prod];};
    // initialize the iterators
    int t_dmnd = 0; 
    int t_prod = 0;
    double cur_d = dmnd_val(t_dmnd); 
    double cur_p = prod_val(t_prod); 
    // iterate two matrix at the same time
    while ((t_dmnd < n_steps) && (t_prod < n_steps)){
        // when there is no demand move to the next
        while (cur_d == 0){
            if (++t_dmnd == n_steps) break;
            cur_d = dmnd_val(t_dmnd);
        }
        // when there is no production move to the next
        while (cur_p == 0){
            if (++t_prod == n_steps) break;
            cur_p += prod_val(t_prod);
        }
        // If reach the end
        if (t_dmnd == n_steps || t_prod == n_steps) break;
        // use production to fufill demand
        int n_hrs = t_prod - t_dmnd;
        double filled = (cur_d <= cur_p)? cur_d: cur_p; 
        cur_p -= filled; 
        cur_d -= filled;
        // add cost to the cost matrix
        cost_val(t_dmnd) += delay_cost(filled, n_hrs);
    }
    // cost for any remaining demand
    cost_val(n_steps-1) += delay_cost(cur_d, n_steps - t_dmnd);
    t_dmnd += 1;
    while (t_dmnd < n_steps){
        cur_d = dmnd_val(t_dmnd);
        cost_val(n_steps-1) += delay_cost(cur_d, n_steps - t_dmnd);
        t_dmnd += 1;
    }
}

double ServiceCost::delay_cost(double quantity, int hrs){
    double unit_cost = (hrs >= 0)? 2: -1;
    double total_cost = quantity * hrs * unit_cost;
    return total_cost;
}