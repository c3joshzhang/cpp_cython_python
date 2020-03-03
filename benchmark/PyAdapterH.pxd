from libcpp.vector cimport vector

cdef extern from "PyAdapter.cpp":
    pass

cdef extern from "PyAdapter.h" namespace "cpp_space":
    cdef cppclass PyAdapter:
        PyAdapter() except +
        void serviceabilityCost(double* dmnd_mat, double* prod_mat, double* cost_mat, int n_steps, int n_prods)