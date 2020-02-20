#include <vector>
#include <iostream>
#include <chrono>
#include "Rectangle.h"

namespace shapes {

    // Default constructor
    Rectangle::Rectangle () {}

    // Overloaded constructor
    Rectangle::Rectangle (int x0, int y0, int x1, int y1) {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }

    // Destructor
    Rectangle::~Rectangle () {}

    // Return the area of the rectangle
    int Rectangle::getArea () {
        return (this->x1 - this->x0) * (this->y1 - this->y0);
    }

    // Get the size of the rectangle.
    // Put the size in the pointer args
    void Rectangle::getSize (int *width, int *height) {
        (*width) = x1 - x0;
        (*height) = y1 - y0;
    }

    // Move the rectangle by dx dy
    void Rectangle::move (int dx, int dy) {
        this->x0 += dx;
        this->y0 += dy;
        this->x1 += dx;
        this->y1 += dy;
    }

    void Rectangle::modify(std::vector< std::vector<double> > &mat){
        int dim0 = mat.size();
        int dim1 = mat[0].size();
        std::cout << dim0 << ", " << dim1 << std::endl;

        auto t_start = std::chrono::high_resolution_clock::now();

        #pragma omp parallel for
        for (int i = 0; i < dim0; i += 1){
            std::cout << "processng: " << i << std::endl;
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
    }
}
