# distutils: language = c++
# distutils: extra_compile_args = -fopenmp -O3 
# distutils: extra_link_args = -fopenmp 

from PyAdapterH cimport PyAdapter
from libcpp.vector cimport vector

cdef class CppLib:
    cdef PyAdapter adpter

    def __cinit__(self, int v):
        self.adpter = PyAdapter(v)

    def get(self):
        return self.adpter.get()

    def apply(self, vector[vector[double]]& mat):
        self.adpter.apply(mat)
        print('Success')
        return mat
#==============================================================================