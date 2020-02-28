
#include <vector>
#include <iostream>
#include <chrono>
#include "Example.h"

Example::Example() {};

Example::~Example() {};

void Example::func(std::vector< std::vector<double> > &mat){
        int dim0 = mat.size();
        int dim1 = mat[0].size();
        std::cout << dim0 << ", " << dim1 << std::endl;

        auto t_start = std::chrono::high_resolution_clock::now();

        #pragma omp parallel for
        for (int i = 0; i < dim0; i += 1){
            std::cout << "processing: " << i << std::endl;
            for (int j=0; j< dim1; j+=1){
                if (i < 1000) 
                    mat[i][j] += 1.;
                else if (i < 100000 && i >= 1000) 
                    mat[i][j] *= 50.;
                else 
                    mat[i][j] -= 50.;
            }
        }
        auto t_end = std::chrono::high_resolution_clock::now();
        double elapsed_time_ms = 
            std::chrono::duration<double, std::milli>
                (t_end-t_start).count();
        std::cout << "Time Taken: " << elapsed_time_ms << std::endl;
};
