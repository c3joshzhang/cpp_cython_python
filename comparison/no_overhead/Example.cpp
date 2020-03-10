#include <vector>
#include <iostream>
#include <chrono>
#include "Example.h"

Example::Example() {};

Example::~Example() {};

void Example::func(double* mat, int dim0, int dim1){                           //Modified
//---------------------------------------------------------------------------------------
        auto mat_val = [&](int i, int j)->double&{ return mat[i*dim1 + j]; };  //Modified
//---------------------------------------------------------------------------------------
        auto t_start = std::chrono::high_resolution_clock::now();
        
        #pragma omp parallel for
        for (int i = 0; i < dim0; i += 1){
            std::cout << "processing: " << i << std::endl;
            for (int j=0; j< dim1; j+=1){
                double& val_ref = mat_val(i,j);                                //Modified
//---------------------------------------------------------------------------------------
                if (i < 1000) val_ref += 1.;
                else if (i < 100000 && i >= 1000) val_ref *= 50.;
                else val_ref -= 50.;
            }
        }
    
        auto t_end = std::chrono::high_resolution_clock::now();
        double elapsed_time_ms = 
            std::chrono::duration<double, std::milli>
                (t_end-t_start).count();
        std::cout << "Time Taken: " << elapsed_time_ms << std::endl;
};