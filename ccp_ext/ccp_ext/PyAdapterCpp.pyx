# distutils: language = c++
# distutils: extra_compile_args = -fopenmp -O2
# distutils: extra_link_args = -fopenmp -O2


from ccp_ext.PyAdapterH cimport PyAdapter
import numpy as np
cimport numpy as np


cdef class CppLib:
    cdef PyAdapter adpter

    def __cinit__(self):
        self.adpter = PyAdapter()

    def calculate_cost(self, 
    	np.ndarray[double, ndim=2, mode="c"] dmnd_mat, 
    	np.ndarray[double, ndim=2, mode="c"] prod_mat):

        assert dmnd_mat.shape[0] == prod_mat.shape[0]
        assert dmnd_mat.shape[1] == prod_mat.shape[1]

        n_steps = dmnd_mat.shape[0]
        n_prods = prod_mat.shape[1]
        cdef np.ndarray[double, ndim = 2, mode="c"] cost_mat
        cost_mat = np.zeros_like(dmnd_mat)

        self.adpter.serviceabilityCost(
        	&dmnd_mat[0, 0],
        	&prod_mat[0, 0],
        	&cost_mat[0, 0],
        	n_steps, 
        	n_prods)

        return cost_mat
