from libcpp.vector cimport vector

cdef extern from "PyAdapter.cpp":
    pass

cdef extern from "PyAdapter.h" namespace "cpp_space":
    cdef cppclass PyAdapter:
        PyAdapter() except +
        PyAdapter(int) except +
        int val
        int get()
        void apply(double* mat, int dim0, int dim1)                            #Modified
#---------------------------------------------------------------------------------------