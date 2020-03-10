# distutils: language = c++
# distutils: extra_compile_args = -fopenmp -O2
# distutils: extra_link_args = -fopenmp 

from PyAdapterH cimport PyAdapter
import numpy as np
cimport numpy as np

cdef class CppLib:
    cdef PyAdapter adpter

    def __cinit__(self, int v):
        self.adpter = PyAdapter(v)

    def get(self):
        return self.adpter.get()

    def apply(self, np.ndarray[double, ndim=2, mode="c"] mat):
        self.adpter.apply(&mat[0,0], mat.shape[0], mat.shape[1])              #Modified
#---------------------------------------------------------------------------------------
        print('Success')
        return mat