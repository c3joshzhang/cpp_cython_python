#include<iostream>
#include "PyAdapter.h"

using namespace cpp_space;

int main(){
  PyAdapter p = PyAdapter(1);

  int max_i = 10;
  int max_j = 20000000;

  std::vector< std::vector<double> > mat(max_i);
  #pragma omp parallel for 
  for (int i = 0; i < max_i; i += 1){
  	std::cout << "filling -- " << i << std::endl;
  	auto& row = mat[i];
  	for (double j = 0.; j < max_j; j += 1){
  		row.push_back(j);
  	}
  }
  p.apply(mat);
}
