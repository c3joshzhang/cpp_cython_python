<img src="https://github.com/c3joshzhang/cpp_cython_python/blob/master/diagram.png" alt="drawing" width="1000"/>

Compile on Ubuntu16.04

to compile with c++: 
	gcc main.cc PyAdapter.cpp Exmaple.cpp -fopenmp -std=c++11 -O3 -lstdc++

to compile with cython: 
	python setup.py build_ext --inplace


On Mac, you need to setup openmp, and change the compile arguments to compile the files
